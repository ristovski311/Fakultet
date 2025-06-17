#include <stdio.h>
void prikaz_matrice(int* X, int x, int y);
void main()
{
	int i, n, m, j, A[100][100];
	printf("Uneti broj vrsta n\n");
	scanf("%d", &n);
	printf("Uneti broj kolona m\n");
	scanf("%d", &m);
	printf("Unesi elemente matrice\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	prikaz_matrice(A, n, m);
}
void prikaz_matrice(int X[100][100], int x, int y)
{
	int p, q;
	for (p = 0; p < x; p++)
	{
		printf("| ");
		for (q = 0; q < y; q++)
			printf("%4d ", X[p][q]);
		printf(" | \n");
	}
}