#include"AlgoLRU.hpp"

void ExuctionAlgo2()
{
    int compteurDefautPage = 0;
    int choixAlea = 1;
    int tailleReference;
    int references[100];
    while (choixAlea != 0 && choixAlea!=777 && choixAlea!=5)
    {
        setupReference(tailleReference, references);
        printf("\nA ce que vous voulez un autre tableau ? :\n(0) pour non :\n(777) pour pouvoir enter votre propre chaine de reference\n(5)pour prendre lexemple du cours\n");
        std::cin >> choixAlea;
        if (choixAlea == 777)
        {
            //printf("\nDonner la taille de la chaine de references :");
            //std::cin >> tailleReference;
            for (int i = 0; i < tailleReference; i++)
            {

                printf("\nDonner la %d reference :", i + 1);
                std::cin >> references[i];
            }
        }
        if (choixAlea == 5)
        {
            tailleReference = 20;
            int r[] = { 7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1 };
            for (int i = 0; i < 20; i++)
                references[i] = r[i];
        }
    }

    int nombreCaseMemoire;
    int caseMemoire[100];
    setupMemoire(nombreCaseMemoire, caseMemoire);

    int row = nombreCaseMemoire + 1;
    int column = tailleReference + 1;
    char application[100][100];
    for (int i = 0; i < nombreCaseMemoire + 1; i++)
    {
        for (int j = 0; j < tailleReference + 1; j++)
        {
            if (i == 0 && j == 0) application[0][0] = '\\';
            else if (i == 0 && j > 0) application[0][j] = char('0' + references[j - 1]);
            else if (i > 0 && j == 0) application[i][0] = char('0' + caseMemoire[i - 1]);
            else application[i][j] = '_';
        }
    }
    //-----------------------------draw table------------------------------
    printf("\n\nLe Tableau d'exuction :\n");
    for (int i = 0; i < nombreCaseMemoire + 1; i++)
    {
        for (int k = 0; k < tailleReference + 1; k++)
        {
            printf(" ---");
        }
        printf("\n");
        for (int j = 0; j < tailleReference + 1; j++)
        {

            printf("| %c ", application[i][j]);

        }
        printf("|");
        printf("\n");
    }
    for (int k = 0; k < tailleReference + 1; k++)
    {
        printf(" ---");
    }
    //--------------------------END draw table--------------------------------
    //-------------------------DEBUT ALGORITHME-------------------------------
bool quitter;
int c=0;
std::vector<int> queueVect;//(4,-1);
//--------------------------DEBUT ALGO----------------------------------
printf("\nAppuyer sur nimporte quelle button(a part le button eteindre) entre chaque iteration:\n");
for (int i = 1; i < column; i++)
{
    quitter = false;
    _getch();
    for(int j=1;j<row;j++)
            {
                if(char('0'+references[i-1]) == application[j][i])
                    {
                        quitter=true;
                        queueVect.erase(std::find(queueVect.begin(),queueVect.end(),references[i-1]));
                        queueVect.push_back(references[i-1]);
                        break;
                    }
             }
    for (int j = 1; j < row; j++)
    {
        if (quitter)
            break;
        if (application[j][i] == '_')
        {
            quitter = true;
            compteurDefautPage++;
            queueVect.push_back(references[i - 1]);
            for (int k = i; k < column; k++)
            {
                application[j][k] = char('0' + references[i - 1]);
            }
            break;
        }
    }
        if (quitter)
            goto flag;
        if((queueVect.size()==nombreCaseMemoire))
        {

                queueVect.push_back(references[i - 1]);
                compteurDefautPage++;
                for (int k = 1; k < row; k++)
                {
                    if (application[k][i] == char('0' +queueVect.front()))
                    {
                        for (int z = i; z < column; z++)
                        {
                            application[k][z] = char('0' + queueVect.back());
                        }
                        break;
                    }
                }
               queueVect.erase(std::find(queueVect.begin(),queueVect.end(),queueVect.front()));
        }



    //---------------------------FIN ALGO------------------------------
    flag:
    printf("\nLe Tableau d'exuction :\n");
    for (int i = 0; i < nombreCaseMemoire + 1; i++)
    {
        for (int k = 0; k < tailleReference + 1; k++)
        {
            printf(" ---");
        }
        printf("\n");
        for (int j = 0; j < tailleReference + 1; j++)
        {

            printf("| %c ", application[i][j]);

        }
        printf("|");
        printf("\n");
    }
    for (int k = 0; k < tailleReference + 1; k++)
    {
        printf(" ---");
    }
    printf("\n");
    printf("\n");
    printf("File Dattente actuel : ");
    for(int i=0;i<queueVect.size();i++)
    {
        if(queueVect[i]==-1)
            continue;

        printf("[%d]  ",queueVect.at(i));
    }
    printf("\n");

}
printf("\nLe Tableau d'exuction :APRES PAGINATION par LRU\n");
for (int i = 0; i < nombreCaseMemoire + 1; i++)
{
    for (int k = 0; k < tailleReference + 1; k++)
    {
        printf(" ---");
    }
    printf("\n");
    for (int j = 0; j < tailleReference + 1; j++)
    {

        printf("| %c ", application[i][j]);

    }
    printf("|");
    printf("\n");
}
for (int k = 0; k < tailleReference + 1; k++)
{
    printf(" ---");
}
printf("\nLE Nombre totale de Default de Page est :%d\n\n\n", compteurDefautPage);
_getch();

}


