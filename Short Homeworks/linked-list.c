#include <stdio.h>
#include<stdlib.h>
#include<time.h>

struct node_struct
{
    int data;
    struct node_struct *next;
};
typedef struct node_struct node;

node* add_left(node* r,int value);
void printList(node* current);
void solution(node* r,int value);
int main()
{
    node* root;
    int i, value, search_input;
    root = NULL;
    srand(time(NULL));

    for ( i = 0; i < 10  ; i++)
    {
        value = rand()%100; 
        root = add_left(root,value);
    }
    printList(root);
    printf("\nEnter the number to search : ");
    scanf("%d", &search_input);
    solution(root,search_input);
}

node* add_left(node* r,int value)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = value;
    new_node->next = r;
    r = new_node;
    return r;
}

void printList(node* current)
{
   if ( current == NULL ) {
      printf( "List is empty.\n" );
   }
   else { 
      printf( "The list is:\n" );

      while ( current != NULL ) { 
         printf( "%d --> ", current->data );
         current = current->next;   
      }
      printf( "NULL\n" );
   }
} 

void solution(node* r,int value)
{
    node* temp;
    node* iter = r;
    
    if (r->data == value)
    {
        printList(r);
        return ;
    }
    while (iter->next != NULL && iter->next->data != value)
    {
        iter = iter->next;
    }
    if (iter->next == NULL)
    {
        printf("NOT FOUND\n");
        return ;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    r = add_left(r,value);
    printList(r);
    return ;
}
