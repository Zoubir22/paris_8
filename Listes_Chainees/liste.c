#include <stdio.h>
#include <stdlib.h>

typedef struct maillon
{
    int val;
    struct maillon *suiv;
} t_maillon;

t_maillon* creer()
{
    t_maillon *pMaillon;
    pMaillon = (t_maillon*)malloc(sizeof(t_maillon));

    if(pMaillon == NULL)
    {
        printf("Problème d'allocation\n");
    }

    else
    {
        printf("Saisissez une valeur : ");
        scanf("%d",&pMaillon->val);
        pMaillon->suiv = NULL;
    }
    return pMaillon;
}

t_maillon *ajoutDebut(t_maillon *L, t_maillon *nouveau)
{
    if(L == NULL)
    {
        return nouveau;
    }
    else
    {
        nouveau->suiv = L;
        return nouveau;
    }
}

t_maillon *ajoutFin(t_maillon *L, t_maillon *nouveau)
{
    t_maillon *cour;
    if (L == NULL)
    {
        return nouveau;
    }
    else
    {
        cour = L;
        while (cour->suiv != NULL) 
        {
             cour=cour->suiv; 
        }
        cour->suiv = nouveau;
        return L;
     }
}

void afficherL(t_maillon *liste)
{
    if(liste == NULL)
    {
        printf("Liste vide\n");
        exit(EXIT_FAILURE);
    }

    t_maillon *liste_actuel = liste;

    while(liste_actuel != NULL)
    {
        printf("Val : %d\n",liste_actuel->val);
        liste_actuel = liste_actuel->suiv;
    }
}

void suppression_tete(t_maillon** li)
{
    t_maillon* A_supprimer = NULL;
    if((*li) != NULL)
    {
        A_supprimer = (*li);
        (*li) = (*li)->suiv;
        free(A_supprimer);
    }
    else
    {
        printf("Suppression Impossible\n");
    }
}

void suppression_pos(int K, t_maillon** li)
{
    t_maillon* prec = NULL;
    t_maillon* A_supprimer = NULL;
    int i;
    if(((*li) == NULL) || (K == 1))
    {
        suppression_tete(li);
    }
    else
    {
        prec = (*li);
        i = 1;
        while((prec->suiv->suiv != NULL) && (i < K - 1))
        {
            prec = prec->suiv;
            i++;
        }
        A_supprimer = prec->suiv;
        prec->suiv = prec->suiv->suiv;
        free(A_supprimer);
    }
}

void libererL(t_maillon *liste)
{
    free(liste);
    liste = NULL;
}

int main()
{
    t_maillon *v = creer();
    t_maillon *liste = v;
    for(int i=0;i<3;i++)
    {
        liste->suiv = creer();
        liste = liste->suiv;
    }
    afficherL(v);

    t_maillon *new1 = creer();
    new1 = ajoutDebut(v,new1); 
    afficherL(new1);

    t_maillon *new2 = creer();
    new2 = ajoutFin(new1,new2);
    afficherL(new1);
    
    printf("\n");

    suppression_tete(&new1);
    afficherL(new1);
    
    printf("\n");
    
    suppression_pos(3,&new1);
    afficherL(new1);

    libererL(liste);
    libererL(v);
    
    return 0;
}