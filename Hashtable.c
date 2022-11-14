/*
Hashtable = array & linked list
- if not sorted => O(1), else O(n)
- consists of 2 pieces, hash function and array

hashfunction returns hashcode = unsigned int that works as an index for the hashtable 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    char* name;
    struct node* next;
}
node;

#define HASH_TABLE_SIZE 10


int hashcode(char* name); 
void insertht(node* hashtable, char* name); // insert in hashtable 
node* create(char* name); // create node
node* insertll(node* list, char* name); // insert in linked list
void search(node* hashtable, char* name);
bool findinlist(node* list, char*name); 

int main(void)
{
    node hashtable[HASH_TABLE_SIZE];
    insertht(hashtable, "john");
    insertht(hashtable, "johnson");
    search(hashtable, "yess");
    search(hashtable, "johnson");
    search(hashtable, "john");

    return 0;
}

int hashcode(char* name)
{
    int sum = 0;

    for (int i = 0; name[i] != (int) '\0'; i++)
    {
        sum += (int) name[i];
    }

    // Mod HASH_TABLE_SIZE because we hashtable contains HASH_TABLE_SIZE buckets.
    return sum % HASH_TABLE_SIZE;
}

node* create(char* name)
{
    node* new = malloc(sizeof(node));
    if (new == NULL)
    {
        return NULL;
    }

    new->name =  name;
    new->next = NULL;

    return new;
}

node* insertll(node* list, char* name)
{
    node* new = malloc(sizeof(node));
    if (new == NULL)
    {
        return list;
    }

    new->name = name;
    new->next = list;
    
    return new;

}


void insertht(node* hashtable, char* name)
{
    unsigned int index = hashcode(name);
    //printf("%s\n", name);
    
    // hashtable[index].next is a node which means we can just insert new elements like a normal linked list.
    hashtable[index].next = insertll(hashtable[index].next, name);

}

bool findinlist(node* list, char*name)
{
    node* temp = list; 
    while(temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

void search(node* hashtable, char* name)
{
    unsigned int index = hashcode(name);
    char* answer = "No";
    if (findinlist(hashtable[index].next, name)) // It's easier to understand if words are displayed
    {
        answer = "Yes";
    }

    printf("Is '%s' in hashtable? %s!\n", name, answer);
}
