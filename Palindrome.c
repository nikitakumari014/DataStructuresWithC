
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node *next;
}node;
void push(node**,node*);
node* pop(node*);
void insert(node**);
void display(node*);
void Is_pallindrome(node*);
int main()
{
    node* start=NULL;
    int choice;
    while(1)
{
    printf("Enter 1 to insert\n2 to display\n3 to check for pallindrome\n4 to exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert(&start);
        break;
        case 2: display(start);
        break;
        case 3: Is_pallindrome(start);
        break;
        case 4:exit(0);
        break;
        default: printf("Invalid choice!\n");

    }
}
}
void insert(node**st)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    printf("Enter data\n");
    fflush(stdin);
    scanf("%c",&ptr->data);
    ptr->next=NULL;
    if(*st==NULL)
    {
        (*st)=ptr;
    }
    else{
        node*temp=*st;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=ptr;
    }
}
void display(node*start)
{
    if(start==NULL)
    printf("List is empty\n");
    else{
        printf("List:\t");
        while(start!=NULL)
        {
            printf("%c\t",start->data);
            start=start->next;
        }
        printf("\n");
    }
}
void Is_pallindrome(node*start)
{
    int flag=0;
    if(start==NULL)
    printf("List is empty\n");
    else{
        node *head=start;
        node*top=NULL;
        while(head!=NULL)
        {
            push(&top,head);
            head=head->next;
        }
        while(top!=NULL)
        {
            if(top->data!=start->data) {
            flag=1;
            break; }
            else{
            top=pop(top);
            start=start->next;
            }
        }
        if(flag==0)
        printf("Is_pallindrome:True\n");
        else
        printf("Is_pallindrome:False\n");
    }
}
void push(node**tp,node*head)
{
    node*ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->data=head->data;
    ptr->next=(*tp);
    (*tp)=ptr;
}
node* pop(node*top)
{
    top=top->next;
    return top;
}
