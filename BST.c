// binary search tree and its operations
#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
}treetype;
treetype* create(int);
treetype* insert(treetype*,treetype*);
void inorder(treetype*);
int Total_nodes(treetype*);
int leaf_node(treetype*);
int left_child(treetype*);
int both_child(treetype*);
void search_node(treetype*,int,int);
treetype* delete(treetype*,int );
treetype* minimum(treetype*);
int main()
{
    treetype *root=NULL,*temp;
    int ch,key,num,val;
    while(1)
    {
        printf(
            "\n1. Create & insert a node\n"
            "2. Display Data\n"
            "3. Count total nodes\n"
            "4. Count total leaf nodes\n"
            "5. Count the nodes having left child\n"
            "6. Count the nodes having both child\n"
            "7. To delete a node\n"
            "8. To search a data and print its parent node\n"
            "9. Stop the program\n"
            "Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data\n");
            scanf("%d",&num);
            temp=create(num);
             if(root==NULL)
            root=temp;
            else
            root=insert(root,temp);
            break;
            case 2: printf("Inorder traversal: ");
            inorder(root);
            break;
            case 3: printf("Total nodes = %d\n",Total_nodes(root));
            break;
            case 4: printf("Total leaf nodes = %d\n",leaf_node(root));
            break;
            case 5: printf("Total nodes having left child = %d\n",left_child(root));
            break;
            case 6: printf("Total nodes having both child = %d\n",both_child(root));
            break;
            case 7: printf("Enter a key to delete: ");
            scanf("%d",&val);
            root = delete(root,val);
            break;
            case 8: printf("Enter a number: ");
            scanf("%d",&key);
            search_node(root,key,root->data);
            break;
        }
    }
}
void search_node(treetype*root,int key,int parent)
{
    if(root==NULL)
    return ;
    if(root->data==key)
    printf("Parent node is: %d\n",parent);
    else{
         search_node(root->left,key,root->data);
         search_node(root->right,key,root->data);
    }
}
treetype* delete(treetype*root,int key)
{
    treetype*temp;
    if(root==NULL)
        printf("List is empty\n");
    else if(key < root->data)
    root->left= delete(root->left,key);
    else if(key > root->data)
    root->right= delete(root->right,key);
    else{
        // key found.
        // case1 : for no child
        if(root->left==NULL && root->right==NULL) {
        free(root);
        root=NULL;
        }
        else if(root->left==NULL){
            temp= root;    // for right child
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            temp=root;
            root= root->left; // for left child
            free(temp); }
        else
        {
            temp = minimum(root->right); // for both childs
            root->data= temp->data;
            root->right= delete(root->right,temp->data);
        }   
            
    }
    return root;
}

treetype* minimum(treetype*root)
{
    treetype* temp=root;
    while(temp!=NULL && temp->left!=NULL)
    {
        temp=temp->left;
    }
    return temp;
}
int both_child(treetype*root)
{
    int count =0 ;
    if(root==NULL)
    return 0 ;
     if(root->left!=NULL && root->right!=NULL)
     count=1;
    return count +  both_child(root->left) + both_child(root->right);
}
int left_child(treetype*root)
{
    int count=0;
    if(root==NULL)
    return 0 ;
    if(root->left!=NULL && root->right==NULL)
    count=1;
    return count + left_child(root->left)+left_child(root->right);
}
int leaf_node(treetype*root)
{
    if(root==NULL)
    return 0; 
    if (root->left==NULL && root->right==NULL)
    return 1 ;
    return leaf_node(root->right) + leaf_node(root->left);
}
int Total_nodes(treetype*root)
{
    if(root)
    return(1+(Total_nodes(root->left)+ Total_nodes(root->right)));
    
}
treetype* create(int num)
{
    treetype *temp;
    temp=(treetype*)malloc(sizeof(treetype));
    if(temp==NULL)
    printf("not enough memory!");
    else{
        temp->data=num;
        temp->left=NULL;
        temp->right=NULL;
    }
    return temp;
}
treetype* insert(treetype*root,treetype*temp)
{
    if(temp->data < root->data)
    {
        if(root->left==NULL)
        root->left=temp;
        else insert(root->left,temp);
    }
    else if(temp->data > root->data)
    {
        if(root->right==NULL)
        root->right=temp;
        else insert(root->right,temp);
    }
    else printf("Duplicate data\n");
    return(root);
}
void inorder(treetype*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
