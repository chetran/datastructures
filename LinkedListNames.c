#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct linkedlist
{
    char *name;
    struct linkedlist * next;
}
linkedlist;

linkedlist* makelist(char* first);
linkedlist* insertPerson(linkedlist* list, char* newperson);
void printList(linkedlist* list);
void delList(linkedlist* list);
bool find(linkedlist* list, char* person);

int main(void)
{
    linkedlist *newlist = makelist("Jhon");
    newlist = insertPerson(newlist, "bobafetttttt");
    printList(newlist);
    printf("Is Jakob is this list (0=NO/1=YES): %i\n", find(newlist, "Jakob"));
    delList(newlist);
    return 0;
}

linkedlist* makelist(char* first)
{
    linkedlist* newList = malloc(sizeof(linkedlist));
    if (newList == NULL)
    {
        return NULL;
    }

    newList->name = first;
    newList->next = NULL;

    return newList;
}

linkedlist* insertPerson(linkedlist* list, char* newperson)
{
    linkedlist* newP = malloc(sizeof(linkedlist));
    if (newP == NULL)
    {
        return NULL;
    }

    newP->name = newperson;
    newP->next = list;

    return newP;
}

void printList(linkedlist* list)
{
    linkedlist* temp = list;
    while (temp != NULL)
    {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

bool find(linkedlist* list, char* person)
{
    linkedlist* temp = list;
    while (temp != NULL)
    {
        if (strcmp(temp->name, person) == 0)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void delList(linkedlist* list)
{
    if (list->next == NULL)
    {
        return free(list);
    }

    delList(list->next);

    return free(list);
}




