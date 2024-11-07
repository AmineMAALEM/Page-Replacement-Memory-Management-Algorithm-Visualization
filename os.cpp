#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<windows.h>
#include<time.h>
#include<conio.h>
#define WIDTH 60


enum TP { QUITTER, AlgoFIFO, AlgoLRU, AlgoOPT , AlgoSecondChance};
const std::string welcomText = "Bienvenue pour mon projet de pagination 'gestion de memoire' \n of the second year DSIA\n";

void Ligne(int longueurLigne =60, char charartere = char(205));
void textAnimation(std::string text, int speed = 100);
void Forme1(int longueurLigne, char charartere = '|');


void afficherMemoire(int n,int tab[]);
void afficherReference(int n,int tab[]);
void setupReference(int &tailleReference,int references[]);
void setupMemoire(int &nombreCaseMemoire,int caseMemoire[]);


typedef struct QueueElement
{
    int value;
    struct QueueElement *next;
}QueueElement, *Queue;


static QueueElement *first = nullptr;
static QueueElement *last = nullptr;
static int nb_elements = 0;


bool is_empty_queue(void);
int queue_length(void);
int queue_first(void);
int queue_last(void);
void print_queue(void);
void push_queue(int x);
void pop_queue(void);
void clear_queue(void);



void ExuctionAlgo1();



void afficherMemoire(int n, int tab[]);
void afficherReference(int n, int tab[]);
void setupReference(int& tailleReference, int references[]);
void setupMemoire(int& nombreCaseMemoire, int caseMemoire[]);
void ExuctionAlgo2();




int indexMax(int taille, int tab[]);
void ExuctionAlgo3();

int main()
{
	Forme1(WIDTH, '|');
	textAnimation(welcomText);
	textAnimation("From :Amine MAALEM \nSpeciality :Data Science et Intelligence Artificielle\n", 50);
	textAnimation("To :.....................\n", 50);
	Sleep(500);
	textAnimation("Chargement en cours .....\n", 200);
	int choixTp;
	Forme1(WIDTH, '|');

	do
	{
		system("cls");
		Forme1(WIDTH, '|');
		std::cout << "quelle Algorithmes de remplacement de pages voullez vous ?\n" << std::endl;
		printf("(1) 1er ALGO First In First Out\n");
		printf("(2) 2eme ALGO Least Recently Used\n");
		printf("(3) 3eme ALGO Optimal \n");
		//printf("(4) <en development> 4eme second chance\n");
		printf("(0) Pour Quitter le programme \n");
		Forme1(WIDTH, '|');
		std::cout << "Votre Choix:";
		std::cin >> choixTp;
		switch (choixTp)
		{
		case AlgoFIFO:
			system("cls");
			Forme1(WIDTH, '|');
			ExuctionAlgo1();

			break;

		case AlgoLRU:
			system("cls");
			Forme1(WIDTH, '|');
			ExuctionAlgo2();
			break;

		case AlgoOPT:
			system("cls");
			Forme1(WIDTH, '|');
			ExuctionAlgo3();
			_getch();
			break;

		case AlgoSecondChance:
			system("cls");
			Forme1(WIDTH, '|');
			//ExuctionAlgo4();
			printf("\n  En developement.....\n");
			_getch();
			break;

		case QUITTER:
			system("cls");
			Forme1(WIDTH, '|');
			textAnimation("Merci pour votre Temps et a plus tard\n");
			Forme1(WIDTH, '|');
			_getch();
			return 0;
			break;

		default:
			Ligne();
			std::cout << "Choix invalide\n";
			_getch();
			Ligne();
			break;

		}

	} while (choixTp != 0);
	return 0;
}
void Ligne(int longueurLigne, char charartere)
{
	for (int i = 0; i < longueurLigne; i++)
	{
		std::cout << charartere;
	}
	std::cout << "\n";
}

void textAnimation(std::string text, int speed)
{
	for (int i = 0; i < text.size(); i++)
	{
		Sleep(speed);
		std::cout << text.at(i);
	}
}
void Forme1(int longueurLigne, char charartere)
{
	Ligne(longueurLigne);
	Ligne(longueurLigne, charartere);
	Ligne(longueurLigne);
}


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

bool is_empty_queue(void)
{
	if(first == nullptr && last == nullptr)
		return true;

	return false;
}

/*------------------------------------------------------------------------*/

/**
* Retourne la longueur d'une File
*/
int queue_length(void)
{
	return nb_elements;
}

/*------------------------------------------------------------------------*/

/**
* Retourne la tête de la File
*/
int queue_first(void)
{
	if(is_empty_queue())
		exit(1);

	return first->value;
}

/*------------------------------------------------------------------------*/

/**
* Retourne la queue de la File
*/
int queue_last(void)
{
	if(is_empty_queue())
		exit(1);

	return last->value;
}

/*------------------------------------------------------------------------*/

/**
* Affiche une File
*/
void print_queue(void)
{
	if(is_empty_queue())
	{
		printf("Rien a afficher, la File est vide.\n");
		return;
	}

	QueueElement *temp = first;

	while(temp != NULL)
	{
		printf("[%d] ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}

/*------------------------------------------------------------------------*/

/**
* Insère un entier dans une File
*/
void push_queue(int x)
{
	QueueElement *element;

	element = (QueueElement *)malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = NULL;

	if(is_empty_queue())
	{
		first = element;
		last = element;
	}
	else
	{
		last->next = element;
		last = element;
	}

	nb_elements++;
}

/*------------------------------------------------------------------------*/

/**
* Retire un élément de la File
*/
void pop_queue(void)
{
	if(is_empty_queue())
	{
		printf("Rien a retirer, la File est deja vide.\n");
		return;
	}

	QueueElement *temp = first;

	if(first == last)
	{
		first = NULL;
		last = NULL;
	}
	else
		first = first->next;

	free(temp);
	nb_elements--;
}

/*------------------------------------------------------------------------*/

/**
* Nettoie la File de tous ses éléments
*/
void clear_queue(void)
{
	if(is_empty_queue())
	{
		printf("Rien a nettoyer, la File est deja vide.\n");
		return;
	}

	while(!is_empty_queue())
		pop_queue();
}

void ExuctionAlgo1()
{
    int compteurDefautPage = 0;
    int choixAlea=1;
    int tailleReference;
    int references[100];
    while(choixAlea != 0 && choixAlea != 777 && choixAlea != 5)
    {
        setupReference(tailleReference,references);
        printf("\nA ce que vous voulez un autre tableau ? :\n(0) pour non :\n(777) pour pouvoir enter votre propre chaine de reference\n(5)pour prendre lexemple du cours\n");
        std::cin>>choixAlea;
        if(choixAlea==777)
        {
            for(int i=0;i<tailleReference;i++)
            {
                printf("\nDonner la %d reference :",i+1);
                std::cin>>references[i];
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
    setupMemoire(nombreCaseMemoire,caseMemoire);

    int row=nombreCaseMemoire+1;
    int column=tailleReference+1;
    char application[100][100];
    for(int i=0;i<nombreCaseMemoire+1;i++)
    {
        for(int j=0;j<tailleReference+1;j++)
        {   if(i==0 && j==0) application[0][0]='\\';
            else if(i==0 && j>0) application[0][j]=char('0'+references[j-1]);
            else if(i>0 && j==0) application[i][0]=char('0'+caseMemoire[i-1]);
                 else application[i][j]='_';
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
        int pageTmp;
        bool quitter;
    //--------------------------DEBUT ALGO----------------------------------
        printf("\nAppuyer sur nimporte quelle button(a part le button eteindre) entre chaque iteration:\n");
for(int i=1;i<column;i++)
{
    quitter=false;
    _getch();
            for(int j=1;j<row;j++)
            {
                if(char('0'+references[i-1]) == application[j][i])
                    {
                        quitter=true;
                        break;
                    }
             }
            for(int j=1;j<row;j++)
            {
                if(quitter)
                    break;
                if(application[j][i]== '_')
                    {
                        quitter=true;
                        compteurDefautPage++;
                        push_queue(references[i-1]);
                        for(int k=i;k<column;k++)
                        {
                            application[j][k]=char('0'+references[i-1]);
                        }
                        break;
                    }
             }
            for(int j=1;j<row;j++)
            {
                if(quitter)
                    break;
                if((application[j][i]!= '_') && (queue_length()==nombreCaseMemoire))
                    {
                        push_queue(references[i-1]);
                        compteurDefautPage++;
                        pageTmp=queue_first();
                        pop_queue();
                        for(int z=0;z<row;z++)
                        {
                            if(application[z][i]==char('0'+pageTmp))
                            {
                                for(int k=i;k<column;k++)
                                {
                                    application[z][k]=char('0'+queue_last());
                                }
                                break;
                            }
                        }
                        break;
                    }
            }
    //---------------------------FIN ALGO------------------------------
    printf("\nLe Tableau d'exuction :\n");
    for(int i=0;i<nombreCaseMemoire+1;i++)
    {
        for(int k=0;k<tailleReference+1;k++)
        {
            printf(" ---");
        }
        printf("\n");
        for(int j=0;j<tailleReference+1;j++)
        {

            printf("| %c ",application[i][j]);

        }
        printf("|");
        printf("\n");
    }
    for(int k=0;k<tailleReference+1;k++)
        {
            printf(" ---");
        }
        printf("\n");
        printf("\n");
        printf("File Dattente actuel : ");print_queue();
        printf("\n");

}
    printf("\nLe Tableau d'exuction :APRES PAGINATION par FIFO\n");
    for(int i=0;i<nombreCaseMemoire+1;i++)
    {
        for(int k=0;k<tailleReference+1;k++)
        {
            printf(" ---");
        }
        printf("\n");
        for(int j=0;j<tailleReference+1;j++)
        {

            printf("| %c ",application[i][j]);

        }
        printf("|");
        printf("\n");
    }
    for(int k=0;k<tailleReference+1;k++)
        {
            printf(" ---");
        }
        printf("\nLE Nombre totale de Default de Page est :%d\n\n\n",compteurDefautPage);
        _getch();
}


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

int indexMax(int taille, int tab[])
{
    int i_max = 0;
    int max = -10;
    for (int i = 0; i < taille; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
            i_max = i;
        }
    }
    return i_max;
}
void ExuctionAlgo3()
{
    int compteurDefautPage = 0;
    int choixAlea = 1;
    int tailleReference;
    int references[100];

    while (choixAlea != 0 && choixAlea != 777 && choixAlea != 5)
    {
        setupReference(tailleReference, references);
        printf("\nA ce que vous voulez un autre tableau ? :\n(0) pour non :\n(777) pour pouvoir enter votre propre chaine de reference\n(5)pour prendre lexemple du cours\n");
        std::cin >> choixAlea;
        if (choixAlea == 777)
        {
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
    //references[]={7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};

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
    int tabDistance[10] = { 0 };
    int k;
    //--------------------------DEBUT ALGO----------------------------------
    printf("\nAppuyer sur nimporte quelle button(a part le button eteindre) entre chaque iteration:\n");
    for (int i = 1; i < column; i++)
    {
        quitter = false;
        for (int z = 0; z < nombreCaseMemoire; z++)
        {
            tabDistance[z] = 0;
        }

        _getch();
        for (int j = 1; j < row; j++)
        {
            if (char('0' + references[i - 1]) == application[j][i])
            {
                quitter = true;
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
                for (int k = i; k < column; k++)
                {
                    application[j][k] = char('0' + references[i - 1]);
                }
                break;
            }
        }
        for (int j = 1; j < row; j++)
        {
            if (quitter)
                break;
            for (k = i; k < column; k++)
            {
                tabDistance[j - 1]++;
                if (application[j][i] == char(references[k - 1] + '0'))
                    break;
            }
        }

        for (int z = i; z < column; z++)
        {
            if (quitter)
                break;
            if (z == i)
                compteurDefautPage++;
            application[(indexMax(nombreCaseMemoire, tabDistance)) + 1][z] = char('0' + references[i - 1]);
        }
        //compteurDefautPage++;


//---------------------------FIN ALGO------------------------------
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

        std::cout << "\nla distance pour que les nombres de la file actuelle se repete :";
        printf("\n====\n");
        for (int i = 0; i < nombreCaseMemoire; i++)
        {

            std::cout << tabDistance[i] << std::endl;
            printf("\n====\n");
        }

    }
    printf("\nLe Tableau d'exuction :APRES PAGINATION par OPTIMAL\n");
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