#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lklist
{
    int number;
    struct lklist *next;

}
lklist;


lklist* createlist(int number);
lklist* insertlist(lklist* list, int number);
bool find(lklist* list, int number);
void printlist(lklist* list);
void delList(lklist* list);

/*
A little bit of tdlr when it comes to linked list:
    -they dont have to follow a specific order, which means they are not always sorted 
    - its important to always know the head or the top of the linked list otherwise you dont know where it should start
    - when doing any configurations of the list its very important to know how the nodes are pointing before doing anything, otherwiese: orphane
    - malloc is important / free 
*/

/*
Problem: Cant the first element to print because condition set to when next is NULL => stop!
*/

int main(void)
{
    lklist *beg = createlist(6); // creating a linked list with start value of 6
    //printf("%i\n", beg->number);
    beg = insertlist(beg, 3); // insert a number 3 into the list. 
    beg = insertlist(beg, 1); // insert a number 3 into the list. 
    beg = insertlist(beg, 1); // insert a number 3 into the list. 
    //printf("%i\n", beg->number);

    printf("Is %i in the linked list: %i\n", 10 ,find(beg, 10));
    printlist(beg);
    delList(beg);
    return 0;
}

lklist* createlist(int number) 
{
    // checks if there is space for list using malloc 
    lklist *list = malloc(sizeof(lklist));
    if (list == NULL)
    {
        return NULL;
    }

    // If there is space we assign the number given to "number" and we want it to point at the NULL pointer so we it can stop 
    list->number = number;
    list->next = NULL;

    // list is now a pointer which means when we return this we will get the adress of this structure that has a value and a pointer! 
    return list;
}

lklist* insertlist(lklist* list, int number)
{
    // we need to malloc space to see if there is space for our new strucutre in our memory 
    lklist *newNode = malloc(sizeof(lklist));
    if (newNode == NULL)
    {
        return NULL;
    }

    // Now we can give it a number. "lklist* list" is the head of the entire list, because list will alwats point at the top of it. 
    newNode->number = number;
    newNode->next = list;

    // then we want to return this new pointer ("adress") so our previous head can point at this new location. 
    return newNode;

}

bool find(lklist* list, int number) // Get the head pointer of the linked list and a value it should compare to 
{
    lklist* temp = list; // We never want to mess with the head 
    while (temp->next != NULL)
    {
        if (temp->number == number)
        {
            return true;
        }

        temp = temp->next;
    }
    if (temp->number == number) // Having this extra condition because i dont know how to accesss the last element in a linked lsit 
    {
        return true;
    }

    return false;
}

void printlist(lklist* list)
{
    lklist *node = list;
    printf("This linked list consist of the following:\n");
    while (node->next != NULL)
    {
        printf("%i\n", node->number);
        node = node->next;
    }
    printf("%i\n", node->number); // Last element 

}

void delList(lklist* list)
{
    if (list->next == NULL)
    {   
        return free(list);
    }
    delList(list->next);

    return free(list);

}