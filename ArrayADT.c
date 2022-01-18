#include<stdio.h>
#include<stdlib.h>
typedef struct arrayADT
{
    int capacity;
    int lastindex;
    int *ptr; // this datatype can be changed as per the requirement
}ADT;
ADT* createArray(int);
int getItem(ADT*,int);
int setItem(ADT*,int,int);
int editItem(ADT*,int,int);
int countItem(ADT*);
void display(ADT*);
int removeItem(ADT*,int);
int search(ADT*,int);
void sort(ADT*);
int main()
{
    int capacity,choice,num,index,value;
    ADT* p;
    printf("Enter the capacity for array\n");
    scanf("%d",&capacity);
    p=createArray(capacity);
    while(1)
    {
        printf("The following operations you can choose to do in the array....\n");
        printf(
            "Enter 1 to get any item\n"
            "Enter 2 to set any item\n"
            "Enter 3 to display the array\n"
            "Enter 4 to modify the value\n"
            "Enter 5 to count the total elements\n"
            "Enter 6 to remove any value\n"
            "Enter 7 to search any value\n"
            "Enter 8 to sort the array\n"
            "Enter 9 to exit\n"
        );
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the index you want the value of\n");
            scanf("%d",&index);
            num=getItem(p,index);
            if(num!=-1)
            printf("The value is: ",num);
            break;
            case 2: printf("Enter the index\n");
            scanf("%d",&index);
            printf("Enter the value\n");
            scanf("%d",&num);
            value=setItem(p,index,num);
            if(value==1)
            printf("Set successfully!\n");
            break;
            case 3: display(p);
            break;
            case 4: printf("Enter the index and new value\n");
            scanf("%d%d",&index,&num);
            value=editItem(p,index,num);
            if(value==0)
            printf("Modified!\n");
            break;
            case 5: printf("Total number of elements are: %d",countItem(p));
            break;
            case 6: printf("Enter the index\n");
            scanf("%d",&index);
            value=removeItem(p,index);
            if(value==0)
            printf("Value removed!\n");
            break;
            case 7: printf("Enter the number\n");
            scanf("%d",&num);
            index=search(p,num);
            if(index==1)
            printf("Value found\n");
            break;
            case 8: sort(p);
            break;
            case 9: exit(0);
            break;
            default: printf("Invalid choice\n");
            
        }
    }

}
void display(ADT*p)
{
    if(p->lastindex==-1)
    printf("Array is empty\n");
    else{
        for(int i=0;i<=p->lastindex;i++)
        printf("%d ",p->ptr[i]);
        printf("\n");
    }
}
void sort(ADT*p)
{
    if(p->lastindex==-1)
    printf("Array is empty!\n");
    else{
        int temp,flag=0;
        for(int i=0;i<=p->lastindex;i++)
        {
            for(int j=0;j<=p->lastindex-i;j++)
            {
                flag=0;
                if(p->ptr[j]>p->ptr[j+1])
                {
                    temp=p->ptr[j];
                    p->ptr[j]=p->ptr[j+1];
                    p->ptr[j+1]=temp;
                    flag=1;
                }
            }
            if (flag==0) {
           printf("Array is sorted in %d pass\n",i);
        }
    }
        printf("Sorted Array is: \n");
        for(int i=0;i<=p->lastindex;i++)
        printf("%d ",p->ptr[i]);
        printf("\n");
        }
 }

int search(ADT*p,int item)
{
    if(p->lastindex==-1)
    return -1;
    else{
        int i;
        for(i=0;i<=p->lastindex;i++)
        {
            if(p->ptr[i]==item)   
            return 1;  // if number found, it get simply return and it will not enter to the next part of the code.
        }
        return -1; // if it runs,that simply means number not found.
    }
}
int removeItem(ADT*p ,int index){
    if(index<0 || index>p->lastindex){
        printf("Invalid Index\n");
        return -1;
    }
    else if(index==p->lastindex){
        p->lastindex--;
        return 0;
    }
    else{
        int i=index;
        while(i<p->lastindex){
            p->ptr[i]=p->ptr[i+1];
            i++;
        }
        p->lastindex--;
        return 0;
    }
}

int countItem(ADT* p)
{
    return(p->lastindex+1);
}
int editItem(ADT*p,int index,int newValue){
    // here we dont need to change the last index value
    if(index<0 || index>p->lastindex){
        printf("Invalid Index\n");
        return -1;
    }
    else{
        p->ptr[index]=newValue;
        return 0;
    }
}
int setItem(ADT*p,int index,int value)
{
    if(index==(p->capacity)){ // if array is full.
        printf("Overflow\n");
        return -1;
    }
    else if(index<0 || index>(p->lastindex+1)){ // if the index if invalid
        printf("Invalid Index!\n");
        return -1;
    }
    else if(index<=p->lastindex)  // if user wants to change the previous value
    {
        //shifting applies here
        int i;
        p->lastindex++;
        i=p->lastindex;
        while(i!=index)
        {
            p->ptr[i]=p->ptr[i-1];
            i--;
        }
        p->ptr[index]=value;
        return 1;
    }
    else{ // normal insertion
        p->lastindex++;
        p->ptr[index]=value;
        return 1;
    } 
}
int getItem(ADT* p,int index)
{
  if(p->lastindex<index || index<0){
      printf("Invalid index\n");
      return -1;    
  }
  else 
  return(p->ptr[index]);
}
ADT* createArray(int capacity)
{
    ADT* p;
    p=(ADT*)malloc(sizeof(ADT));
    p->capacity=capacity;
    p->lastindex=-1;
    p->ptr=(int*)malloc(p->capacity*sizeof(int));
    return p;
}
