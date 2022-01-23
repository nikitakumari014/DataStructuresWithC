// stack using single pointer
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node* push(node*);
node* pop(node*);
void peek(node*);
void display(node*);
int main()
{
    node *top=NULL;
    int ch;
    while(1)
    {
        printf(
            "Enter 1 to push\n"
            "Enter 2 to pop\n"
            "Enter 3 to peek\n"
            "Enter 4 to display\n"
            "Enter 5 to exit\n"
        );
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: top=push(top);
            break;
            case 2: top=pop(top);
            break;
            case 3: peek(top);
            break;
            case 4: display(top);
            break;
            case 5: exit(0);
            break;
            default: printf("Invalid choice\n");

        }
    }
}
node* push(node*top)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    printf("Enter data to push\n");
    scanf("%d",&p->data);
    p->next=top;
    top=p;
    return top;

}
node* pop(node*top)
{
    if(top==NULL)
    printf("Stack is empty\n");
    else{
        node *temp=top;
        printf("Popped data is:%d\n",top->data);
        top=top->next;
        free(temp);
    }
    return top;
}
void peek(node*top)
{
    if(top==NULL)
    printf("Stack is empty\n");
    else
    printf("Element at the peek is %d\n",top->data);
}
void display(node*top)
{
    if(top==NULL)
    printf("Nothing to display\n");
    else{
        while(top!=NULL)
        {
            printf("%d\n",top->data);
            top=top->next;
        }
    }
}
