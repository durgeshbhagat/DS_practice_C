#include<stdio.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
 }Node;

 typedef struct LinkList{
    Node *head;
 }LinkList;

 void init_linklist(LinkList **l);
 void show_linklist(LinkList *l);

void add_at_beg_linklist(LinkList *l, int data);
void add_at_last_linklist(LinkList *l, int data);

int main()
{
    LinkList *l1; ;
    int data;
    init_linklist(&l1);
    show_linklist(l1);
    // printf("------------------- Link list succefully Initialized -------------------\n");
    add_at_beg_linklist(l1, 2);
    // printf("------------------- Added first Element to the list -------------------\n");
    add_at_beg_linklist(l1, 4);
    // printf("------------------- Added second Element to the list -------------------\n");
    add_at_beg_linklist(l1, 6);
    //printf("------------------- Added third Element to the list -------------------\n");
    add_at_beg_linklist(l1, 8);
    // printf("------------------- Added fourth Element to the list -------------------\n");
    show_linklist(l1);
    //printf("------------------- Call showlinklist function -------------------\n");
    add_at_last_linklist(l1, 20);
    add_at_last_linklist(l1, 30);
    add_at_last_linklist(l1, 40);
    show_linklist(l1);
    return(0);
}

// To initialize the Single Link List
void init_linklist(LinkList **l)
{       // LinkList *l;
        (*l) = malloc(sizeof(LinkList *));
        (*l)->head = NULL;
        //return(l);
}

// To add data x at the begining of Single Link List
void add_at_beg_linklist(LinkList *l, int data)
{
    Node *new_node;
    new_node = malloc(sizeof(Node *));
    new_node->data = data;
    if(l->head==NULL)
    {
        //printf("\t\t\t\t Empty Link list :::::::::\n");
        l->head = new_node;
        new_node->next = NULL;
    }
    else
    {
        new_node->next = (l->head);
        l->head = new_node;
    }
}

// To add a node at last in th eSingle Link list
void add_at_last_linklist(LinkList *l, int data)
{
    Node *new_node, *temp;
    new_node = malloc(sizeof(Node *));
    new_node->data = data;
    new_node->next = NULL;
    if(l->head == NULL)
    {
        l->head = new_node;
    }
    else
    {
        temp = l->head;
        while(temp->next !=NULL)
           temp = temp->next;
        temp->next= new_node; 

    }
}
// To print Link list
void show_linklist(LinkList *l)
{
    Node *temp;
    temp = malloc(sizeof(Node *));
    // printf(" \n\n In the show_linklist function \n\n");
    //printf("head: %p\n  ", l->head);
    if(l->head == NULL)
        printf("\t Empty Single Link list\n");
    else
    {
        //printf("\t \t Inside the else loop:: ");
        temp = l->head;
        printf("The elements of Single Link list are :: ");
        while(temp!=NULL)
        {
            printf("|%d ||%p|--> ", temp->data, temp->next);
            temp = temp->next;
        }
        printf("\n");
    }
}