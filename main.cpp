#include"main.h"
#define WIDTH 60
int main()
{
	Forme1(WIDTH, '|');
	textAnimation(welcomText);
	textAnimation("From :Amine MAALEM\nSpeciality :Data Science et Intelligence Artificielle\n", 50);
	textAnimation("To :Madame Woujdene Nahili \n", 50);
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