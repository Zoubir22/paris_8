#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int genererAlea(int a, int b)
{
    int alea = rand() % (b - a + 1) + a;
    return alea;
}

void permuter(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void remplirTab(int taille, int *tab)
{
    int i;
    for(i=0;i<taille;i++)
    {
        tab[i] = genererAlea(-100,100);
    }
}

void ajoutTabDebut(int taille, int *tab, int val)
{
    int i;
    for(i=taille+1;i>=1;i--)
    {
        tab[i+1] = tab[i];
    }
    tab[1] = tab[0];
    tab[0] = val;
}

void ajoutTabFin(int taille, int *tab, int val)
{
    tab[taille+1] = val;
}

void suppValTab(int taille, int *tab, int pos)
{
    int i;
    for(i=pos;i<taille;i++)
    {
        tab[i] = tab[i+1];
    }
}

int main()
{
    srand(time(NULL));
    int i;
    int taille = 30;
    int tab[50];
    remplirTab(taille,tab);

    for(i=0;i<taille;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");

    int val = genererAlea(-100,100);
    printf("%d\n",val);
    ajoutTabDebut(taille,tab,val);
    for(i=0;i<=taille;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");

    int val2 = genererAlea(-100,100);
    printf("%d\n",val2);
    ajoutTabFin(taille,tab,val2);
    for(i=0;i<=taille+1;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");

    taille = taille + 1;

    int pos = genererAlea(0,32);
    printf("%d\n",pos);
    suppValTab(taille,tab,pos);
    for(i=0;i<taille;i++)
    {
        printf("%d ",tab[i]);
    }
    printf("\n");
    
    return 0;
}