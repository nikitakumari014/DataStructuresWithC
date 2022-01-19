// To sort a singly linked list while inserting the elements
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node*next;
}node;
void insert(node**);
void display(node*);
int main()
{
    node *head=NULL;
    int ch;
    while(1)
    {
        printf("Enter 1 to insert\n2 to display\n3 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert(&head);
            break;
            case 2: display(head);
            break;
            case 3: exit(0);
            default: printf("Invalid choice!Enter Again!\n");
        }
    }
}
void insert(node**hd)
{
    int key;
    node*p=malloc(sizeof(node));
    printf("Enter the data\n");
    scanf("%d",&key);
    p->data=key;
    p->next=NULL;
    if(*hd==NULL || (*hd)->data>key)
    {
        p->next=*hd;
        *hd=p;
    }
    else{
        node*temp=*hd;
        while(temp->next!=NULL && temp->next->data<key)
        temp=temp->next;
        p->next=temp->next;
        temp->next=p;
    }
}
void display(node*head)
{
    if(head==NULL)
    printf("List is empty\n");
    else{
        while(head!=NULL)
        {
            printf("%d ",head->data);
            head=head->next;
        }
        printf("\n");
    }
}
