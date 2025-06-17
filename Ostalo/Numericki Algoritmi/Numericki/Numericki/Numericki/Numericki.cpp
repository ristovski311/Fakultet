#include <iostream>
#include <math.h>

using namespace std;

void Sistem(double* sistem, double greska)
{
    double trenutnaGreska = 9999;
    double* starisistem = new double[3];
    int iteracija = 0;
    while (trenutnaGreska > greska)
    {
        for (int i = 0; i < 3; i++)
        {
            starisistem[i] = sistem[i];
        }

        //Jakobijev

        double x1 = 0.2 * (-4 * sistem[1] + sistem[2]);
        double x2 = 0.333 * (4 + 2 * sistem[0] - sistem[2]);
        double x3 = 0.25 * (8 + sistem[0] - 2 * sistem[1]);

        sistem[0] = x1;
        sistem[1] = x2;
        sistem[2] = x3;

        //Gaus-Zajdelov

        /*sistem[0] = 0.2 * (-4 * sistem[1] + sistem[2]);
        sistem[1] = 0.333 * (4 + 2 * sistem[0] - sistem[2]);
        sistem[2] = 0.25 * (8 + sistem[0] - 2 * sistem[1]);*/


        double c0 = abs(sistem[0] - starisistem[0]);
        double c1 = abs(sistem[1] - starisistem[1]);
        double c2 = abs(sistem[2] - starisistem[2]);

        trenutnaGreska = max(c0, max(c1, c2));
        iteracija++;

        cout << "\n-----\nTrenutni niz: x1:" << sistem[0] << " x2: " << sistem[1] << "x3: " << sistem[2] << " | iteracija: " << iteracija << " | greska:" << trenutnaGreska << "\n\n";

    }

    cout << "\nPoslednja greska: " << trenutnaGreska << endl;
}

double NadjiResenjeJednacine(double a)
{
    double x1 = a;
    double x0 = 9999999;
    double greska = 0.05;
    int iteracija = 0;
    while (abs(x1 - x0) > greska)
    {
        iteracija++;
        x0 = x1;
        double temp = pow(2.71828182846, x0);
        double temp2 = cos(temp);
        x1 = log(temp2);
        cout << "\nTrenutna vrednost x" << iteracija << "  = " << x1 << " u iteraciji: " << iteracija << " | greska : " << x1 - x0;
    }
    cout << " < 0.05!";
    return x1;
}

double NadjiResenjeJednacine2(double a)
{
    double x1 = a;
    double x0 = 9999999;
    double greska = 0.05;
    int iteracija = 0;
    while (abs(x1 - x0) > greska)
    {
        iteracija++;
        x0 = x1;
        double temp1 = pow(2.72, x1);
        double temp2 = cos(temp1);
        double temp3 = sin(temp1) * temp1;
        double temp4 = temp2 - temp1;
        double temp5 = temp3 + temp1;
        double temp6 = temp4 / temp5;
        x1 = x1 + temp6;
        cout << "\nTrenutna vrednost x" << iteracija << "  = " << x1 << " u iteraciji: " << iteracija << " | greska : " << x1 - x0;
    }
    cout << " < 0.05!";
    return x1;
}

double f(double x)
{
    double res1 = pow(x, 3) - 5 * x + 1;
    double res2 = 8 - 5 * x - pow(x, 4);

    //cout << "\n-------\nmax { " << res1 << ", " << res2 << "}\n---------\n";

    //cout << max(res1, res2) << endl;
    return max(res1, res2);
}

double pomoc(double x1, double x2)
{
    return abs(x1 - x2) / 2;
}

double ResiZadatak2(double x, double y)
{
    double x0 = x;
    double y0 = y;
    double z0;
    double greska = 0.01;
    int iteracija = 0;


    while (pomoc(x0, y0) > greska)
    {

        z0 = (x0 + y0) / 2;

        cout << "x" << iteracija << " = " << x0 << " y" << iteracija << " = " << y0 << " z" << iteracija << " = " << z0 << " greska: " << pomoc(x0, y0) << " | iteracija " << iteracija << "\n";


        if (f(x0) * f(z0) < 0)
        {
            y0 = z0;
        }
        else
        {
            x0 = z0;
        }

        iteracija++;


    }
    z0 = (x0 + y0) / 2;
    cout << "x" << iteracija << " = " << x0 << " y" << iteracija << " = " << y0 << " z" << iteracija << " = " << z0 << " greska: " << pomoc(x0, y0) << " | iteracija " << iteracija << "\n";



    cout << "\n\nResenje je: x* = z" << iteracija << " = " << z0 << endl;
    return (x0 + y0) / 2;

}

void IspisiMatricu(double** matrica, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "|   ";
        for (int j = 0; j < n; j++)
        {
            cout << matrica[i][j] << "   ";
        }
        cout << "   |\n";
    }
}

void UnesiMatricu(double*** matrica, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Unesi matricu[" << i << "][" << j << "]\n";
            cin >> (*matrica)[i][j];
        }
    }
}

void RacunajF(double** racunaj, int n)
{
    double temp = -1 - pow((*racunaj[1]), 2);
    double temp1 = pow(2.72, temp);
    double resx = temp1 - (*racunaj)[0];

    double temp2 = pow((*racunaj)[0], 2);
    double temp3 = temp2 + 10;
    double temp4 = log(temp3);
    double resy = temp4 - 1 - (*racunaj)[1];

    (*racunaj)[0] = resx;
    (*racunaj)[1] = resy;
}

void MatriceZadatak(double** matrix, int n)
{
    double greska = 0.01;
    double trenutnaGreska = 9999;
    double** J0 = new double* [n];
    double** J0inverz = new double* [n];
    double* f = new double[2];
    double* x = new double[2];
    x[0] = 0;
    x[1] = 0;
    for (int i = 0; i < n; i++)
    {
        J0[i] = new double[n];
        J0inverz[i] = new double[n];
    }
    int iteracija = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            J0[i][j] = matrix[i][j];
        }
    }

    while (trenutnaGreska > greska)
    {
        cout << "==\nJ" << iteracija << ":\n\n";
        IspisiMatricu(J0, 2);
        cout << "\n\nUnesi inverznu matricu:\n\n";
        UnesiMatricu(&J0inverz, 2);
        cout << "==\nJ" << iteracija << "inverz:\n\n";
        IspisiMatricu(J0inverz, 2);

        RacunajF(&f, 2);

        cout << "\n====\nf: (x,y) = (" << f[0] << "," << f[1] << ")\n\n";

        double resx = x[0] - (J0inverz[0][0] * f[0] + J0inverz[0][1] * f[1]);
        double resy = x[1] - (J0inverz[1][0] * f[0] + J0inverz[1][1] * f[1]);

        cout << "(x" << iteracija << ",y" << iteracija << ") = (" << resx << "," << resy << ")\n\n";

        double c0 = abs(x[0] - resx);
        double c1 = abs(x[1] - resy);

        trenutnaGreska = max(c0, c1);


    }

}

int main()
{

    double** pocetna = new double* [2];
    for (int i = 0; i < 2; i++)
        pocetna[i] = new double[2];

    UnesiMatricu(&pocetna, 2);

    IspisiMatricu(pocetna, 2);

    MatriceZadatak(pocetna, 2);

}

