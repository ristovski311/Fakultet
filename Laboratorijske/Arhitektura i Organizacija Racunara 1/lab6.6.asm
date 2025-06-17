//lab6/6
#include <stdio.h>
#include <string.h>
#include <math.h>
void main()
{
	char sent1[100], word[100];
	int i = 0, j = 0, counter = 0, lensen1 = 0, lenword = 0;
	printf("Unesi recenicu\n");
	gets(sent1);
	gets(word);
	lenword = strlen(word);
	while (sent1[i] != '\0')
	{
		j = 0;
		while (sent1[i + j] == word[j] && word[j] != '\0')
			j++;
		if (j == lenword)
			counter++;
		i++;
	}
	printf("ima %d reci", counter);
 }