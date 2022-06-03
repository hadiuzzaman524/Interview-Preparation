#include <stdio.h>

typedef struct node
{
    int data;
    struct node *left,*right;
} node;
node *createNode(int val)
{
    node *temp= (node*)malloc(sizeof(node));
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}

void addLeft(node *head, node *child)
{
    head->left=child;
}

void addRight(node *head, node *child)
{
    head->right=child;
}

void printTree(node *head)
{

    printf("%d ", head->data);

    if(head->left)
    {
        printTree(head->left);
    }
    if(head->right)
    {
        printTree(head->right);
    }
}

typedef struct stack
{
    node *data;
    struct stack *next;
} stack;
stack *head=NULL;

void push(node *data)
{

    stack *temp= (stack*) malloc(sizeof(stack));
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
node *pop()
{

    if(head!=NULL)
    {
        stack *temp= (stack*) malloc(sizeof(stack));
        node *treedata= (node*) malloc(sizeof(node));
        temp= head;
        treedata= head->data;
        head=head->next;
        free(temp);
        return treedata;
    }
    else
    {
        printf("NULL");
    }
}

int isNotEmpty()
{
    if(head==NULL)
        return 0;
    return 1;
}


void printStack()
{

    stack *temp= (stack*) malloc(sizeof(stack));
    temp=head;

    while(temp!=NULL)
    {
        printf("%d ", temp->data->data);
        temp=temp->next;
    }
}

void preOrder(node *root){

    if(root==NULL)
        return;
    else{
        push(root);
         node *temp= (node*) malloc(sizeof(node));

        while(isNotEmpty()){
           temp= pop();
           printf("%d ", temp->data);

           if(temp->right){
            push(temp->right);
           }
           if(temp->left){
            push(temp->left);
           }
        }
    }
}
int main()
{
    /* Create this tree
           1
          / \
         2   3
        / \ / \
       4  5 6  7

       */
    node *head=createNode(1);
    addLeft(head, createNode(2));
    addRight(head, createNode(3));
    addLeft(head->left, createNode(4));
    addRight(head->left, createNode(5));
    addLeft(head->right, createNode(6));
    addRight(head->right, createNode(7));

    printf("\n\nUsing recursion: ");
    printTree(head);
    printf("\nUsing Iterative method: ");
    preOrder(head);
   // printStack();

    return 0;
}
