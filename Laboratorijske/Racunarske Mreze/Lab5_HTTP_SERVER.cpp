#include <iostream>
#include <winsock.h>
#include <fstream>
#include <string.h>
#include <string>

#pragma comment(lib,"wsock32.lib")
#define PORT 80

using namespace std;

void EE(string message)
{
    cout << "Program se zavrsio | " << message << endl;
    WSACleanup();
    exit(-1);
}

int main()
{
    WSAData wsa;
    SOCKET sock;

    if (WSAStartup(0x0202, &wsa) != 0)
        EE("Greska, wsa!");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
        EE("Greska, socket!");

    struct sockaddr_in addr;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //INADDR_ANY
    addr.sin_port = htons(PORT);
    addr.sin_family = AF_INET;

    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
        EE("Greska, bind!");

    if (listen(sock, 3) == SOCKET_ERROR)
        EE("Greska, listen!");

    while (1)
    {
        SOCKET client;
        struct sockaddr_in clientAddr;
        int clientAddrSize = sizeof(clientAddr);

        if ((client = accept(sock, (struct sockaddr*)&clientAddr, &clientAddrSize)) == INVALID_SOCKET)
            EE("Greska, accept!");
        else
            cout << "Uspesna konekcija!\t" << "Adresa: " << clientAddr.sin_addr.s_addr << "\tPORT: " << clientAddr.sin_port << "\n";


        char buffRcv[4000];
        memset(buffRcv, 0, sizeof(buffRcv));

        if (recv(client, buffRcv, sizeof(buffRcv), 0) < 0)
            EE("Greska, rcv!");

        //REQUEST
        //GET url HTTP/1.1
        //HEADER:VALUE
        //...
        //HEADER:VALUE
        //\n
        //BODY

        char* slash = strstr(buffRcv, "/");
        char* version = strstr(buffRcv, "HTTP");
        char basepath[] = "C:\\randommm\\";

        if (strstr(buffRcv, "GET") != buffRcv || slash == nullptr || version == nullptr)
        {
            char message[] = "Greska, morate poslati GET!";
            char buffSend[2000];
            memset(buffSend, 0, sizeof(buffSend));
            sprintf(buffSend, "HTTP/1.1 400 Bad Request\r\nContent-Type:text/plain\r\nContent-Length:%d\r\n\r\n%s", strlen(message), message);
            
            if(send(client, buffSend, strlen(buffSend),0) != strlen(buffSend))
                EE("Greska send!");
        }
        else
        {
            int urlLen = version - slash - 2;
            char* fullPath = new char[strlen(basepath) + urlLen + 1 + 4];
            strcpy(fullPath, basepath);
            strncat(fullPath, slash + 1, urlLen);
            strcat(fullPath, ".jpg");

            cout << "Putanja do trazenog fajla je: " << fullPath << "\n\n";

            ifstream file(fullPath, ios::binary);

            if (!file.is_open())
            {
                char message[] = "Niste uneli validnu putanju u url!";
                char buffSend[2000];
                memset(buffSend, 0, sizeof(buffSend));
                sprintf(buffSend, "HTTP/1.1 404 Not Found\r\nContent-Type:text/plain\r\nContent-Length:%d\r\n\r\n%s", strlen(message), message);

                int ret;

                if ((ret = send(client, buffSend, strlen(buffSend), 0)) != strlen(buffSend))
                    EE("Greska, send!!");
            }
            else
            {
                file.seekg(0, ios::end);
                long fileLen = file.tellg();
                file.seekg(0, ios::beg);

                char* fileContent = new char[fileLen];
                file.read(fileContent, fileLen);

                char header[200];
                sprintf(header, "HTTP/1.1 200 OK\r\nContent-Type:image/jpg\r\nContent:Length:%ld\r\n\r\n", fileLen);
                
                long totalSize = strlen(header) + fileLen;

                char* buffSend = new char[totalSize];
                memset(buffSend, 0, sizeof(buffSend));

                strcpy(buffSend, header);
                memcpy(buffSend + strlen(header), fileContent, fileLen);
                
                if (send(client, buffSend, totalSize, 0) != totalSize)
                    EE("Greska send!!!");
            }
        }

        //RESPONSE
        //HTTP/1.1 200 OK
        //HEADER:VALUE
        //...
        //HEADER:VALUE
        //\n
        //BODY

        closesocket(client);
    }

    WSACleanup();
    closesocket(sock);

    return 0;
}

/*
SOCKET sock;
    WSAData wsa;
    if (WSAStartup(0x0202, &wsa) != 0)
        EE("Greska, wsa!");

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
        EE("Greska, socket!");

    struct sockaddr_in sockadd;
    sockadd.sin_addr.s_addr = INADDR_ANY;
    sockadd.sin_family = AF_INET;
    sockadd.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr*)&sockadd, sizeof(sockaddr)) == SOCKET_ERROR)
        EE("Greska, bind!");

    if (listen(sock,6) == SOCKET_ERROR)
        EE("Greska, listen!");

    while(true)
    {
        SOCKET client;
        struct sockaddr_in clientAddr;
        int clientAddrSize = sizeof(clientAddr);

        if ((client = accept(sock, (struct sockaddr*)&clientAddr, &clientAddrSize)) == INVALID_SOCKET)
            EE("Greska! Accept!");

        cout << "\nConnected!\t" << clientAddr.sin_addr.s_addr << "\t" << clientAddr.sin_port << "\n\n";

        char buffSend[20000];
        char buffRecv[1000];

        memset(buffSend, 0, sizeof(buffSend));
        memset(buffRecv, 0, sizeof(buffRecv));

        char path[] = "C:\\randommm\\";

        if (recv(client, buffRecv, sizeof(buffRecv), 0) < 0)
            EE("Greska, recieve!");

        cout << "Primljeno:\n\n" << buffRecv << "\n\n";

        char* start = strstr(buffRecv, "GET");

        if (start != buffRecv)
        {
            strcpy(buffSend, "HTTP/1.1 400 Bad Request\r\nConnection:close\r\nContent-Type:text/plain\r\nContent-Length:34\r\n\r\n400 Bad Request.\tPokusajte ponovo!");
            int sendSize = strlen(buffSend);
            if (send(client, buffSend, sendSize, 0) != sendSize)
                EE("Greska, send!");
            cout << "Poslato:\n\n" << buffSend << endl;

            continue;
        }

        if (strstr(buffRecv, "favicon") != nullptr)
        {
            strcat(path, "favicon.ico");
            ifstream file(path, ios::binary);
            if (!file.is_open())
                EE("Greska, otvaranje fajla!");

            file.seekg(0, ios::end);
            long size = file.tellg();
            file.seekg(0, ios::beg);

            char* toSend = new char[size];
            file.read(toSend, size);

            sprintf(buffSend, "HTTP/1.1 200 OK\r\nConnection:close\r\nContent-Type:image/x-icon\r\nContent-Length:%ld\r\n\r\n",size);
            long totalSize = strlen(buffSend) + size;

            char* buffToSend = new char[totalSize];

            strcpy(buffToSend, buffSend);

            memcpy(buffToSend + strlen(buffSend), toSend, size);

            if (send(client, buffToSend, totalSize,0) != totalSize)
                EE("Greska! send!");

            cout << "Poslato:\n\n" << buffToSend;

            continue;
        }

        else
        {

            char* slash = strstr(buffRecv, "/");
            char* http = strstr(buffRecv, "HTTP");
            if (slash == nullptr || http == nullptr)
            {
                strcpy(buffSend, "HTTP/1.1 400 Bad Request\r\nConnection:close\r\nContent-Type:text/plain\r\nContent-Length:34\r\n\r\n400 Bad Request.\tPokusajte ponovo!");
                int sendSize = strlen(buffSend);
                if (send(client, buffSend, sendSize, 0) != sendSize)
                    EE("Greska, send!");
                cout << "Poslato:\n\n" << buffSend << endl;

                continue;
            }

            int parSize = http - slash;
            char* par = new char[parSize];

            strncpy(par, slash + 1, parSize);

            cout << "Parameter is : " << par << endl;

            strcat(path, par);

            cout << "Path is : " << path << endl;

            ifstream file(path, ios::binary);
            if (!file.is_open())
            {
                strcpy(buffSend, "HTTP/1.1 400 Bad Request\r\nConnection:close\r\nContent-Type:text/plain\r\nContent-Length:34\r\n\r\n400 Bad Request.\tNema takve slike!");
                int sendSize = strlen(buffSend);
                if (send(client, buffSend, sendSize, 0) != sendSize)
                    EE("Greska, send!");
                cout << "Poslato:\n\n" << buffSend << endl;

                continue;
            }



            strcpy(buffSend, "HTTP/1.1 200 OK\r\nConnection:close\r\nContent-Type:text/plain\r\nContent-Length:23\r\n\r\n200 OK!\tUspesno slanje!");
            int sendSize = strlen(buffSend);
            if (send(client, buffSend, sendSize, 0) != sendSize)
                EE("Greska, send!");
            cout << "Poslato:\n\n" << buffSend << endl;

        }

    }

    WSACleanup();
*/