#include <stdio.h>
#include <stdlib.h>

void saisie_tab(int tab[5])
{
	int i;
	for(i=0;i<5;i++)
	{
		tab[i] = (i+2)*3;
	}
}

int main()
{
	int i,tab[5];
	saisie_tab(tab);
	for(i=0;i<5;i++)
	{
		printf("%d ",tab[i]);
	}
	printf("\n");
	return 0;

}
