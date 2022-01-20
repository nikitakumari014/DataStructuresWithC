//Operations on two polynomials
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
}node;
void insert(node**,int,int);
void display(node*);
void sum(node*,node*);
void multiply(node*,node*);
void check(node**);
int main()
{
    node*head1=NULL,*head2=NULL;
    int ch,coeff,exp,n1,n2;
    printf("Enter number of terms for 1st polynomial\n");
      scanf("%d",&n1);
      for(int i=0;i<n1;i++)
      {
          printf("Enter coefficient for term %d: ",i+1);
          scanf("%d",&coeff);
          printf("Enter exponent for term %d: ",i+1);
          scanf("%d",&exp);
          insert(&head1,coeff,exp);
      }
      printf("Enter number of terms for 2nd polynomial\n");
      scanf("%d",&n2);
      for(int i=0;i<n2;i++)
      {
          
          printf("Enter coefficient for term %d: ",i+1);
          scanf("%d",&coeff);
          printf("Enter exponent for term %d: ",i+1);
          scanf("%d",&exp);
          insert(&head2,coeff,exp);
      }
      while(1){
      printf("Enter 1 for Addition\n2 for Multiplication\n3 to Stop");
      scanf("%d",&ch);
      switch(ch)
      {
          case 1: sum(head1,head2);
          break;
          case 2: multiply(head1,head2);
          break;
          case 3: exit(0);
          default: printf("Wrong choice!\n");
      }
      }
}
void insert(node**hd,int coeff,int exp)
{
    node* p= malloc(sizeof(node));
    p->coeff=coeff;
    p->exp=exp;
    p->next=NULL;
     if(*hd==NULL || (*hd)->exp <= p->exp)
    {
        p->next=*hd;
        *hd=p;
    }
    else{
        node*temp=*hd;
        while(temp->next!=NULL && temp->next->exp >= p->exp)
        temp=temp->next;
        p->next=temp->next;
        temp->next=p;
    }

}
void display(node*head)
{
        while(head!=NULL)
        {
            printf("%dx^%d ",head->coeff,head->exp);
            head=head->next;
            if(head!=NULL)
            printf("+");
            else
            printf("\n");
        }
}
void sum(node*head1,node*head2)
{
    node*head3=NULL;
    while(head1!=NULL && head2!=NULL) {
    if(head1->exp==head2->exp){
    int coeff;
    coeff= head1->coeff+head2->coeff;
    insert(&head3,coeff,head1->exp);
    head1=head1->next;
    head2=head2->next;
    }
    else if(head1->exp > head2->exp){
        insert(&head3,head1->coeff,head1->exp);
        head1=head1->next;
    }
    else  {
        insert(&head3,head2->coeff,head2->exp);
        head2=head2->next;
    }
  }
  while(head1!=NULL)
  {
      insert(&head3,head1->coeff,head1->exp);
      head1=head1->next;
  } 
   while(head2!=NULL)
  {
      insert(&head3,head2->coeff,head2->exp);
      head2=head2->next;
  } 
  printf("Result After Addition : ");
  display(head3);
}
void multiply(node*head1,node*head2)
{
    node*head4=NULL;
    while(head1!=NULL)
    {
        node*temp=head2;
        while(temp){
            int coeff,exp;
            coeff=(temp->coeff) * (head1->coeff);
            exp=(temp->exp) + (head1->exp);
            insert(&head4,coeff,exp);
            temp=temp->next;
            }
        head1=head1->next;
    }
    printf("Result After Multiplication: ");
    check(&head4);
    display(head4);
}
void check(node**hd)
{
    node* temp= *hd;
    while(temp->next!=NULL)
    {
        if(temp->exp == temp->next->exp)
        {
            temp->coeff=temp->coeff+temp->next->coeff;
            node*ptr=temp->next;
            temp->next=temp->next->next;
            free(ptr);
        }
        temp=temp->next;
    }
}
