//lab6
#include <stdio.h>
#include <string.h>
#include <math.h>
void main()
{
	int i = 0, len, found = 0;
	char s[50], rec[50];
	printf("Unesi rec koju proveravas\n");
	gets(rec);
	len = strlen(rec);
	FILE* fp;
	fp = fopen("tekst.txt", "r");
	while (!feof(fp) && !found)
	{
		i = 0;
		fscanf(fp, "%s", s);
		while (s[i] == rec[i] && s[i] != '\0')
		{
			i++;
		}
		if (i == len)
			found = 1;
	}
	fclose(fp);
	if (found)
		printf("Rec postoji u fajlu\n");
	else
		printf("Rec ne postoji u fajlu\n");
}