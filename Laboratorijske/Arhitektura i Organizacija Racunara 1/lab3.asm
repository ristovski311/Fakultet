#include <stdio.h>

void main()
{
	int N, M, i, j, imin, p, A[100], B[100], C[200];
	printf("Unesite broj clanova niza A: ");
	scanf("%d", &N);
	printf("Unesite broj clanova niza B: ");
	scanf("%d", &M);
	printf("Unesite clanove niza A: ");
	for (i = 0; i < N; i++)
		scanf("%d", A+i);
	printf("Unesite clanove niza B: ");
	for (i = 0; i < M; i++)
		scanf("%d", B + i);
	for (i = 0; i < N + M; i++) 
	{
		if (i < N)
			C[i] = A[i];
		else
			C[i] = B[i - N];
	}
	for (i = 0; i < N + M; i++)
		printf("%d ", C[i]);
	for (i = 0; i < N + M - 1; i++)
	{
		imin = i;
		for (j = i + 1; j < N + M; j++) 
		{
			if (C[imin] > C[j])
				imin = j;
		}
		if (imin != i)
		{
			p = C[imin];
			C[imin] = C[i];
			C[i] = p;
		}
	}
	printf("Niz C: ");
	for (i = 0; i < N + M; i++)
		printf("%d ", C[i]);
}