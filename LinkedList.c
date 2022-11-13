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
lklist* SortedInsertList(lklist* list, int number);
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
FIX = instead of have the while condition to be: if temp->next = NULL => STOP! DO: if temp == NULL STOP!
*/

int main(void)
{
    lklist *beg = createlist(1000); // creating a linked list with start value of 6
    //printf("%i\n", beg->number);
    beg = SortedInsertList(beg, 30); // insert a number 3 into the list. 
    beg = SortedInsertList(beg, 45); // insert a number 3 into the list. 
    beg = SortedInsertList(beg, 1001000); // insert a number 3 into the list. 
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
    while (temp != NULL)
    {
        if (temp->number == number)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

void printlist(lklist* list)
{
    lklist *node = list;
    printf("This linked list consist of the following:\n");
    while (node != NULL)
    {
        printf("%i\n", node->number);
        node = node->next;
    }
    

}

void delList(lklist* list)
{
    if (list->next == NULL) // Base case: we want the recursion to stop when its the end of the linked list.
    {   
        return free(list); // Free's up the memory 
    }
    delList(list->next); // Recursion we look each and everyone until we reach the base case,
    return free(list); // it returns and keeps going to the next line of code that wants it to free the current memory and go back the last recursion. Until its done!

}

lklist* SortedInsertList(lklist* list, int number)
{
    lklist *new = malloc(sizeof(lklist));
    if (new == NULL)
    {
        return NULL;
    }
    
    // Basically we need two variables to be able to go "back in time" 
    lklist *temp = list;
    lklist *prev = NULL; // It's intially set to NULL because we haven't gone back in time yet and its gonna be useful in the loop down below
    
    new->number = number;
    

    while (temp != NULL)
    {
        if (new->number < temp->number)
        {
            // If we haven't gone back in time,(prev is NULL) and its less than the number infront, we can conclude it has to be in the front
            if (prev == NULL)
            {
                new->next = temp;
                return new;
            }
            
            // If prev != NULL we're inside the linked list somewhere, we want "new" to point at the "temp" which is greater than "new" and then set "prev" to point to "new"
            // Otherwise we end up orphaning the previous part of the list. 
            new->next = temp;
            prev->next = new;

            return list;
        }
        prev = temp;
        temp = temp->next;
    }

    // If we happend to go through the entire list ("new" is the biggest number), "prev" (last element) should point at "new" and "new" should point at NULL
    prev->next = new;
    new->next = NULL;
    
    // Then we just return the head of the list 
    return list;

}
