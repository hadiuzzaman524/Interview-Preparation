#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node **adjList;

node *createNode(int val)
{
    node *temp= (node*)malloc(sizeof(node));
    temp->data=val;
    temp->next=NULL;
    return temp;
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n, e;
    scanf("%d %d", &n, &e);

    adjList= (node*) malloc(n*sizeof(node));
    for(int i=0; i<n; i++)
    {
        adjList[i]=NULL;
    }

    for(int i=0; i<e; i++)
    {
        int s, d;
        scanf("%d %d", &s, &d);

        node *newNode= createNode(d);
        newNode->next=adjList[s];
        adjList[s]=newNode;

    }

    for(int i=0; i<n; i++)
    {
        printf("%d : ", i);
        while(adjList[i]!=NULL)
        {
            printf("%d ", adjList[i]->data);
            adjList[i]= adjList[i]->next;
        }

        printf("\n");
    }
    return 0;
}
