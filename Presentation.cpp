#include"Presentation.h"

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