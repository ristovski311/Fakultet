#include <iostream>
#include <fstream>
#include <winsock.h>
#include <string.h>
#include <string>
#pragma comment(lib, "wsock32.lib")

#define IPADDRESS "146.190.62.39"
#define PORT 80

using namespace std;

void EE(string msg)
{
	cout << "Program je prestao sa radom! | " << msg << endl;
	WSACleanup();
	exit(-1);
}

int main()
{
	WSAData wsa;
	SOCKET sock;
	if (WSAStartup(0x0202, &wsa) != 0)
		EE("Greska! Startup!");

	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
		EE("Greska, socket!");

	struct sockaddr_in server;

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr(IPADDRESS);
	server.sin_port = htons(PORT);

	if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
		EE("Greska, connect!");

	char buffSend[1000];
	char buffRcv[4000];

	memset(buffSend, 0, sizeof(buffSend));
	memset(buffRcv, 0, sizeof(buffRcv));

	strcpy(buffSend, "GET / HTTP/1.1\r\nHost:httpforever.com\r\nConnection:close\r\nAccept:text/plain\r\n\r\n");

	int sizeSend = strlen(buffSend);

	if (send(sock, buffSend, sizeSend, 0) != sizeSend)
		EE("Greska, send!");

	cout << "Client sent: " << buffSend << endl << endl;

	if (recv(sock, buffRcv, sizeof(buffRcv), 0) < 0)
		EE("Greska, recieve!");

	cout << "Server sent:\n\n" << buffRcv << endl << endl;

	WSACleanup();

	return 0;
}
