//jun221
#include <stdio.h>
#include <string.h>
#include <math.h>
void nadovezi(char s1[], char s2[], int len1, int len2)
{
	int p = 0;
	while (p <= len2)
	{
		s1[len1 + p] = s2[p];
		p++;
	}
}
void main()
{
	char sent1[100], sent2[100];
	int i, lensen1 = 0, lensen2 = 0;
	printf("Unesi recenicu\n");
	gets(sent1);
	gets(sent2);
	while (sent1[lensen1] != '\0')
		lensen1++;
	while (sent2[lensen2] != '\0')
		lensen2++;
	nadovezi(sent1, sent2, lensen1, lensen2);
	printf("\n");
	puts(sent1);
 }