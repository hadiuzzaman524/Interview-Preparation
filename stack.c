#include <stdio.h>

typedef struct stack
{   int data;
    struct stack *next;
} stack;

stack *head=NULL;

void push(int val)
{
    stack *node= (stack *) malloc(sizeof(stack));
    node->data= val;
    node->next=NULL;

    if(head==NULL)
        head=node;
    else
    {
        node->next= head;
        head=node;
    }
}

int pop()
{
    if(head!=NULL)
    {
        int val= head->data;
        stack *temp= (stack*) malloc(sizeof(stack));
        temp=head;
        head=head->next;
        free(temp);
        return val;
    }
}

void print()
{

    while(head!=NULL)
    {
        printf("%d ", head->data);
        head=head->next;
    }
}

int isEmpty(){

    if(head==NULL)
        return 1;
    return 0;

}


int main()
{

    push(40);
    push(41);
    push(42);
    push(43);

    printf("%d \n", pop());
    printf("%d \n", pop());
    printf("%d \n", pop());
    printf("%d \n", pop());

    push(4492);
    pop();
    if(isEmpty()){
        printf("Empty");
    }
    else{
        printf("Not Empty");
    }
    print();

    return 0;
}
