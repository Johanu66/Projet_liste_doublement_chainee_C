#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef void Object;

typedef struct CelluleDbl* PCelluleDbl;
typedef struct CelluleDbl
{
    Object* valeur;
    PCelluleDbl suivant;
    PCelluleDbl precedent;
}ListeDbl;

void creerListeDbl(PCelluleDbl l,int n);
void afficherListeDbl(PCelluleDbl p);
int rechercherUnElementDbl(PCelluleDbl l,Object* ValeurRecherche,PCelluleDbl* addrRecherche);
PCelluleDbl ajoutTete(PCelluleDbl l,Object* donnee);
void ajoutQueue(PCelluleDbl l,Object* donnee);
PCelluleDbl supprimerUnElementDbl(PCelluleDbl l,Object* donnee);
PCelluleDbl inverserDbl(PCelluleDbl l);
void triBulleDbl(PCelluleDbl l);
void supprimerDoublonDbl(PCelluleDbl p);
PCelluleDbl fusionDbl(PCelluleDbl l1,PCelluleDbl l2);
int nombreElmt(PCelluleDbl l , PCelluleDbl *q);
void palyndrome(PCelluleDbl l);

int main()
{
   PCelluleDbl maListe=NULL, l;
   int option=0, donne;
   while(option!=11)
   {
        do
        {
            printf("VEUILLEZ CHOISIR UNE OPTION\n");
            printf("1-Creer une liste chainee d'entier\n2-Ajouter un element en tete de liste\n3-Ajouter un element en queue de liste\n4-Trier une liste\n5-Supprimer un element donne de la liste\n6-Supprimer les doublons de la liste\n7-Rechercher un element dans la liste\n8-Fusionner deux listes\n9-Inverser une liste\n10-Verifier si une liste est un palyndrome\n11-Quitter\n");
            scanf("%d",&option);
        }while(option<1 || option>11);
        switch(option)
        {
            case 1:
                {
                    printf("Votre liste contiendra combien d'element : \n");
                    scanf("%d",&donne);
                    maListe=malloc(sizeof(PCelluleDbl));
                    creerListeDbl(maListe,donne);
                    afficherListeDbl(maListe);
                    printf("\n");
                    break;
                }
            case 2:
                {
                    if(maListe!=NULL)
                    {
                        printf("Que voulez-vous ajouter en tete de la liste : ");
                        scanf("%d",&donne);
                        maListe=ajoutTete(maListe,donne);
                        afficherListeDbl(maListe);
                        printf("\n");
                    }
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            case 3:
                {
                    if(maListe!=NULL)
                    {
                        printf("Que voulez-vous ajouter en queue de la liste : ");
                        scanf("%d",&donne);
                        ajoutQueue(maListe, donne);
                        afficherListeDbl(maListe);
                        printf("\n");
                    }
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            case 4:
                {
                    if(maListe!=NULL)
                    {
                        triBulleDbl(maListe);
                        afficherListeDbl(maListe);
                        printf("\n");
                    }
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            case 5:
                {
                    if(maListe!=NULL)
                    {
                        printf("Quel element voulez-vous supprimer : \n");
                        scanf("%d",&donne);
                        maListe=supprimerUnElementDbl(maListe,donne);
                        afficherListeDbl(maListe);
                        printf("\n");
                    }
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            case 6:
                {
                    if(maListe!=NULL)
                    {
                        supprimerDoublonDbl(maListe);
                        afficherListeDbl(maListe);
                        printf("\n");
                    }
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            case 7:
                {
                    if(maListe!=NULL)
                    {
                        printf("Quel element voulez-vous rechercher dans la liste : ");
                        scanf("%d",&donne);
                        if(rechercherUnElementDbl(maListe,donne,&l)==1)
                        {
                            printf("Element trouve\n");
                        }
                        else
                        {
                            printf("Element non trouve\n");
                        }
                        printf("\n");
                    }
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            case 8:
                {
                     if(maListe!=NULL)
                     {
                        printf("Veuillez creer une seconde liste\n");
                        printf("La seconde liste contiendra combien d'element : \n");
                        scanf("%d",&donne);
                        l=malloc(sizeof(PCelluleDbl));
                        creerListeDbl(l,donne);
                        afficherListeDbl(l);
                        maListe=fusionDbl(maListe,l);
                        printf("\nVoici votre nouvelle liste fusionnee est :\n");
                        afficherListeDbl(maListe);
                        printf("\n");
                        free(l);
                     }
                     else
                     {
                        printf("Veuillez d'abord creer une premiere liste\n");
                     }
                     break;
                }
            case 9:
                {
                    if(maListe!=NULL)
                    {
                        maListe=inverserDbl(maListe);
                        afficherListeDbl(maListe);
                        printf("\n");
                    }
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            case 10:
                {
                    if(maListe!=NULL)
                        palyndrome(maListe);
                    else
                        printf("Veuillez d'abord creer une liste\n");
                    break;
                }
            default:
                break;
        }
    }
    return 0;
}

void creerListeDbl(PCelluleDbl l,int n)
{
    PCelluleDbl tete,p;
    int i,donnee;
    printf("Entrez le premier element\n");
    scanf("%d",&donnee);
    tete=l;
    tete->valeur=donnee;
    tete->suivant=NULL;
    tete->precedent=NULL;
    for(i=2;i<=n;i++)
    {
        p=malloc(sizeof(PCelluleDbl));
        printf("Entrez l'element suivant\n");
        scanf("%d",&donnee);
        p->valeur=donnee;
        p->suivant=NULL;
        p->precedent=tete;
        tete->suivant=p;
        tete=p;
    }
}



void afficherListeDbl(PCelluleDbl p)
{
    printf("\nLa liste est constituer de : ");
    while(p!=NULL)
    {
        printf("    %d",p->valeur);
        p=p->suivant;
    }
}



int rechercherUnElementDbl(PCelluleDbl l,Object* ValeurRecherche,PCelluleDbl* addrRecherche)
{
    PCelluleDbl p;
    int trouver=0;
    p=l;
    while(trouver==0 && p!=NULL)
    {
        if(p->valeur==ValeurRecherche)
        {
            trouver=1;
            *addrRecherche=p;
        }
        p=p->suivant;
    }
    return trouver;
}



PCelluleDbl ajoutTete(PCelluleDbl l,Object* donnee)
{
    PCelluleDbl tete;
    tete=malloc(sizeof(PCelluleDbl));
    tete->valeur=donnee;
    tete->suivant=l;
    tete->precedent=NULL;
    l->precedent=tete;
    return tete;
}



void ajoutQueue(PCelluleDbl l,Object* donnee)
{
    PCelluleDbl que,p=l;
    que=malloc(sizeof(PCelluleDbl));
    que->valeur=donnee;
    que->suivant=NULL;
    if(p!=NULL)
        while(p->suivant!=NULL)
            p=p->suivant;
    p->suivant=que;
    que->precedent=p;
}



PCelluleDbl supprimerUnElementDbl(PCelluleDbl l,Object* donnee)
{
    PCelluleDbl p=NULL,preced;
    if(l->valeur==donnee)
    {
        p=l;
        l=l->suivant;
        if(l!=NULL)
            l->precedent=NULL;
        free(p);
        printf("L'element a ete supprimer\n");
        return l;
    }
    else
    {
        if(rechercherUnElementDbl(l,donnee,&p))
        {
            preced=p->precedent;
            preced->suivant=p->suivant;
            if(p->suivant!=NULL)
            {
                p->suivant->precedent=preced;
            }
            free(p);
            printf("L'element a ete supprimer\n");
        }
        else
        {
            printf("L'element n'a pas pu etre supprimer.Assurez vous qu'il existe bien\n");
        }
        return l;
    }
}



void triBulleDbl(PCelluleDbl l)
{
    int permut;
    PCelluleDbl p,q;
    Object* temp;
    do
    {
        p=l;
        permut=0;
        while(p!=NULL)
        {
            q=p->suivant;
            while(q!=NULL)
            {
                if(p->valeur > q->valeur)
                {
                    permut=1;
                    temp=p->valeur;
                    p->valeur=q->valeur;
                    q->valeur=temp;
                }
                q=q->suivant;
            }
            p=p->suivant;
        }
    }
    while(permut==1);
}



void supprimerDoublonDbl(PCelluleDbl p)
{
    PCelluleDbl q,d;
    while(p->suivant!=NULL)
    {
        q=p->suivant;
        while(q!=NULL)
        {
            if(p->valeur==q->valeur)
            {
                q->precedent->suivant=q->suivant;
                if(q->suivant!=NULL)
                    q->suivant->precedent=q->precedent;
                d=q;
                q=q->suivant;
                free(d);
            }
            else{
                q=q->suivant;
            }
        }
        p=p->suivant;
    }
    return;
}



PCelluleDbl fusionDbl(PCelluleDbl l1,PCelluleDbl l2)
{
    PCelluleDbl p, l;
    triBulleDbl(l1);
    triBulleDbl(l2);
    if(l1->valeur < l2->valeur)
    {
        l=l1;
        l1=l1->suivant;
    }
    else if(l1->valeur > l2->valeur)
    {
        l=l2;
        l2=l2->suivant;
    }
    else if(l1->valeur == l2->valeur)
    {
        l=l1;
        l1=l1->suivant;
        l2=l2->suivant;
    }
    p=l;
    while(l1!=NULL && l2!=NULL)
    {
        if(p->valeur==l1->valeur)
        {
            l1=l1->suivant;
        }
        else if(p->valeur==l2->valeur)
        {
            l2=l2->suivant;
        }
        else
        {
            if(l1->valeur < l2->valeur)
            {
                p->suivant=l1;
                l1->precedent=p;
                p=p->suivant;
                l1=l1->suivant;
            }
            else if(l1->valeur > l2->valeur)
            {
                p->suivant=l2;
                l2->precedent=p;
                p=p->suivant;
                l2=l2->suivant;
            }
            else if(l1->valeur == l2->valeur)
            {
                p->suivant=l1;
                l1->precedent=p;
                p=p->suivant;
                l1=l1->suivant;
                l2=l2->suivant;
            }
        }
    }
    if(l1==NULL && l2!=NULL)
    {
        while(l2!=NULL)
        {
            if(l2->valeur!=p->valeur)
            {
                p->suivant=l2;
                l2->precedent=p;
                p=p->suivant;
            }
            l2=l2->suivant;
            p->suivant=NULL;
        }
    }
    else if(l2==NULL && l1!=NULL)
    {
        while(l1!=NULL)
        {
            if(l1->valeur!=p->valeur)
            {
                p->suivant=l1;
                l1->precedent=p;
                p=p->suivant;
            }
            l1=l1->suivant;
            p->suivant=NULL;
        }
    }
    return l;
}



PCelluleDbl inverserDbl(PCelluleDbl l)
{
    PCelluleDbl p=l, tmp;
    while(p!=NULL)
    {
        tmp=p->suivant;
        p->suivant=p->precedent;
        p->precedent=tmp;
        tmp=p;
        p=p->precedent;
    }
    return tmp;
}



int nombreElmt(PCelluleDbl l , PCelluleDbl *q)
{
    int n=1;
    PCelluleDbl d=l;
    while(d->suivant!=NULL)
    {
        n++;
        d=d->suivant;
    }
    *q=d;
    return n;
}



void palyndrome(PCelluleDbl l)
{
    PCelluleDbl p=l, q;
    int i , etat=1 , valeurParcours=nombreElmt(l , &q)/2;
    for(i=0;i<valeurParcours;i++)
    {
        if(p->valeur!=q->valeur)
        {
            etat=0;
            break;
        }
        else
        {
            continue;
        }
    }
    if(etat==0)
        printf("Cette liste n'est pas un palyndrome\n");
    else
        printf("Cette liste est un palyndrome\n");
}

