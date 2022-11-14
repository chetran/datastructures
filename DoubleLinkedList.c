#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ddnode
{
    int value;
    struct ddnode* prev;
    struct ddnode* next;

}ddnode;

ddnode* create(int value);
ddnode* insertul(ddnode* list, int value);
void printdd(ddnode* list);
void del(ddnode* list);
bool find(ddnode* list, int target);
ddnode* delnode(ddnode* list, int target);

int main(void)
{
    // Testing
    ddnode* list = create(6);
    list = insertul(list, 3);
    list = insertul(list, 7);
    printdd(list);
    list = delnode(list, 10);
    printdd(list);

    del(list);

    return 0;
}

ddnode* create(int value)
{
    ddnode* list = malloc(sizeof(ddnode));
    if (list == NULL)
    {
        return NULL;
    }

    list->value = value;
    // There shouldnt be any instances of any other nodes
    list->next = NULL;
    list->prev = NULL;

    return list;
}

// Unordered list insert
ddnode* insertul(ddnode* list, int value)
{
    ddnode* new = malloc(sizeof(ddnode));
    if (new == NULL)
    {
        // No space in memory so return "old" list
        return list;
    }

    new->value = value;
    new->next = list;
    new->prev = NULL;
    list->prev = new;

    return new;
}

void printdd(ddnode* list)
{
    ddnode* temp = list;

    printf("This double linked list contains the following:\n");
    while (temp != NULL)
    {
        printf("%i\n", temp->value);
        temp = temp->next;
    }
}

// Delete a specific node
void del(ddnode* list)
{
    if (list == NULL)
    {
        return free(list);
    }

    del(list->next);

    return free(list);
}

bool find(ddnode* list, int target)
{
    ddnode* temp = list;

    while(temp != NULL)
    {
        if (temp->value == target)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}

ddnode* delnode(ddnode* list, int target)
{
    ddnode* temp = list;

    while (temp != NULL)
    {
        if (temp->value == target)
        {
            // If its the first element in the list
            if (temp->prev == NULL)
            {
                ddnode *new = temp->next;
                new->prev = NULL;
                free(temp);
                return new;
            }
            // If its the last element
            else if (temp->next == NULL)
            {
                ddnode *new = temp->prev;
                new->next = NULL;
                free(temp);
                return list;
            }
            // If its somewhere in between
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return list;
        }
        temp = temp->next;
    }

    printf("No instances of %i!\n", target);

    return list;

}


