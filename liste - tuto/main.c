#include <stdio.h>
#include <stdlib.h>

/*
Nos fonctions :
    - insererTete ...
    - inserqueue...
    - supprimerTete...
    - supprimerQueue
    - afficher ...

*/
typedef struct noeud {
    int val;
    struct noeud *suiv;
}noeud, *liste;

// Ajout en début de liste

liste insertete(liste l,int v)
{
    liste p = malloc(sizeof(noeud));
    p->val=v;
    p->suiv=l;

    return p;
}
// ajout en queue
liste inserqueue(liste l,int v)
{
    if(l==NULL)
    {
        liste p = malloc(sizeof(noeud));
        p->val = v;
        p->suiv = NULL;
        return p;
    }else {
    liste p = malloc(sizeof(noeud));
    p->val = v;
    p->suiv = NULL;
    liste q = l;
    while (q->suiv != NULL)
    {
        q = q->suiv;
    }
    q->suiv =p;

    return l;
    }
}

// Suppression en tete
liste supprimertete(liste l)
{
    if( l == NULL)
    {
        printf("La liste est vide , Suppression impossible \n");
        return l;
    }else{
        liste p = l;
        l = l->suiv;
        free(p);
        return l;
    }
}

//Suppression en Queue
liste supprimerqueue(liste l)
{
    if( l == NULL)
    {
        printf("La liste est vide , Suppression impossible \n");
        return l;
    }else{
    liste p = l;
    if(p->suiv == NULL)
    {
        l =NULL;
        free(p);
        return l;
    }else
    {
        liste q = p->suiv;
        while(q->suiv!=NULL)
        {
            p = q;
            q = q->suiv;

        }
        p->suiv = NULL;
        free(q);
        return l;
    }

    }
}

//Affichage

void afficher(liste l)
{
    liste p = l;
    while(p != NULL)
    {
        printf("%d ",p->val);
        p=p->suiv;
    }

}
liste reset(){
    return NULL;
}


int main()
{

    liste l = reset();
    l = insertete(l,47);
    l = insertete(l,74);
    l = insertete(l,00);
    l = insertete(l,50);
    afficher(l);printf("\n");

    l = supprimertete(l);
    afficher(l);printf("\n");

    l = supprimerqueue(l);
    afficher(l);printf("\n");
    l = inserqueue(l,90);

    afficher(l);printf("\n");



    return 0;
}
