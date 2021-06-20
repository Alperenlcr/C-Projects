#include <stdio.h>
#include<stdlib.h>

struct node{
    int a;
    struct node * nextptr;
};
typedef struct node node;

void insert(struct node **head, int value);
int countEvenNumbers(node *head);

int main()
{
    node* root = NULL;;
    int value, i;

    while (value != -1)
    {
        scanf("%d", &value);
        insert(&root, value);
    }
    printf("\n%d\n", countEvenNumbers(root));

    return 0;
}

void insert(struct node **head, int value)
{
    node* new_node = (struct node*) malloc(sizeof(node));
    new_node->a  = value;
    new_node->nextptr = (*head);
    (*head) = new_node;
}

int countEvenNumbers(node *head)
{
    node* current = head;
    int count = 0;
    while ( current != NULL )
    {
        if (current->a % 2 == 0)
            count ++;
        current = current->nextptr;   
    }
    return count;
}