#ifndef __PILE__
    #define __PILE__
#include<iostream>
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




#endif //__PILE__
