#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}node;
node* insert(node*);
node* sort(node*);
void display(node*);
int main()
{
    node *head=NULL;
    int ch;
    while(1)
    {
        printf("Enter 1 to Insert\n2. Display\n3 to Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert(head);
            break;
            case 2: if(head==NULL)
            printf("List is empty\n");
            else{
            printf("Original List: ");
            display(head);
            printf("List after sorting: ");
            head=sort(head);
            display(head);
            }
            break;
            case 3: exit(0);
            default: printf("Invalid choice! Enter again.\n");
            
        }
    }
}
node* insert(node*head)
{
     node*p;
    int key;
    p=(node*)malloc(sizeof(node));
    printf("Enter data: ");
    scanf("%d",&key);
    p->data=key;
    p->next=NULL;
    p->prev= NULL;
    if(head==NULL)
    {
        head=p;
    }
    else{
        node*temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=p;
        p->prev=temp;
    }
    return head;
}
node* sort(node*head)
{
    node*current=NULL;
    node*index=NULL;
    for(current=head; current->next!=NULL; current=current->next)
    {
        for(index=current->next; index!=NULL; index=index->next)
        {
            if(current->data > index->data)
            {
                int temp= current->data;
                current->data= index->data;
                index->data=temp;
            }
        }
    }
    return head;
}
void display(node*head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
