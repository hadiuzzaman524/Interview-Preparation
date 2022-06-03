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

void addLeft(node *head, node *child){
    head->left=child;
}

void addRight(node *head, node *child){
    head->right=child;
}
void printTree(node *head){

    printf("%d ", head->data);

    if(head->left){
        printTree(head->left);
    }
    if(head->right){
        printTree(head->right);
    }
}
int main()
{
    node *head=createNode(1);
    addLeft(head, createNode(2));
    addRight(head, createNode(3));
    addLeft(head->left, createNode(4));
    addRight(head->left, createNode(5));
    addLeft(head->right, createNode(6));
    addRight(head->right, createNode(7));

    printTree(head);


    return 0;
}
