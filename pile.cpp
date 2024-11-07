#include"pile.hpp"

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
