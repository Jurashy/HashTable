#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct node
{
    char * name;
    struct node * next;
}
node;

node* first[26] = {NULL};

/*
 * inserts a name called buffer into
 * our linked list
 */

void insert(int key, const char * buffer)
{
    node* newptr = malloc(sizeof(node));
    if (newptr == NULL)
    {
        return;
    }
    //make a new pointer

    newptr->name = malloc(strlen(buffer) + 1);
    strcpy(newptr->name, buffer);

    newptr -> next = NULL;

    //check for empty list

    if(first[key] == NULL)
    {
        first[key] = newptr;
    }
    else
    {
        node* predptr = first[key];

        while (true)
        {
            /* code */
            if(predptr -> next == NULL)
            {
                predptr -> next = newptr;
                break;
            }
            predptr = predptr->next;
        }
        
    }
}

int hash(const char * buffer)
{
    return tolower(buffer[0]) - 'a';
}

void print_bucket(int key)
{
    node*current = first[key];
    if(current == NULL)
    {
        printf("Bucket %d is empty\n", key);
        return;
    }

    printf("bucket %d: ", key);
    while (current != NULL)
    {
        printf("%s -> ", current->name);
        current = current->next;
        /* code */
    }
    
}
int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("usage %s <name>\n", argv[0]);
        return 1;
    }
    int hashvalue = hash(argv[1]);
    insert(hashvalue, argv[1]);
    print_bucket(hashvalue);
}
