#include"myTP.hpp"

void afficherMemoire(int n,int tab[])
{
    printf("\n --- \n");
    for(int i=0;i<n;i++)
    {
        printf("| %d |",tab[i]);
        printf("\n --- \n");
    }
}
void afficherReference(int n,int tab[])
{
    for(int i=0;i<n;i++)      printf(" ---");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("| %d ",tab[i]);
    }
    printf("|\n");
    for(int i=0;i<n;i++)      printf(" ---");
    printf("\n");
}
void setupReference(int &tailleReference,int references[])
{
    printf("donner la taille de la chaine de reference :");
    std::cin>>tailleReference;
    srand(time(NULL));
    for(int i=0;i<tailleReference;i++)      references[i] = rand() %10;
    afficherReference(tailleReference,references);
}
void setupMemoire(int &nombreCaseMemoire,int caseMemoire[])
{
    printf("\nVeuillez presiser le nombre de cases memoire :");
    std::cin>>nombreCaseMemoire;

    for(int i=0;i<nombreCaseMemoire;i++)    caseMemoire[i]=i;
    afficherMemoire(nombreCaseMemoire,caseMemoire);
}
