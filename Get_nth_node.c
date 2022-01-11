
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
int insert(node**,int);
void display(node*);
void get_nth_node(node*,int);
int main()
{
    node *start=NULL;
    int choice,count=0;
    while(1)
    {
        printf("Enter 1 to insert\n2 to display\n3 to get data from nth node\n4 to exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: count=insert(&start,count);
            break;
            case 2: display(start);
            break;
            case 3: get_nth_node(start,count);
            break;
            case 4:exit(0);
            break;
            default: printf("Invalid choice.Enter again!\n");
        }
    }
}
int insert(node**st,int count)
{
    node *ptr;
    ptr=(node*)malloc(sizeof(node));
    printf("Enter data\n");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(*st==NULL)
    {
        (*st)=ptr;
        ++count;
    }
    else{
        node*temp=*st;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=ptr;
        ++count;
    }
    return count;
}
void display(node*start)
{
    if(start==NULL)
    printf("List is empty\n");
    else{
        printf("List:\t");
        while(start!=NULL)
        {
            printf("%d\t",start->data);
            start=start->next;
        }
        printf("\n");
    }
}
void get_nth_node(node*start,int count)
{
    if(start==NULL)
    printf("List is empty\n");
    else{
        printf("Enter the number of node you want the data of\n");
        int c;
        scanf("%d",&c);
        if(c>count)
        printf("Node doesn't exist!\n");
        else{
            for(int i=1;i<c;i++)
            start=start->next;
            printf("The node at position %d is %d\n",c,start->data);
        }
    }
}
