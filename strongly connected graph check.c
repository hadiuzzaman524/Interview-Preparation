#include <stdio.h>
typedef struct GraphNode
{
    int data;
    struct GraphNode *next;
} GraphNode;
GraphNode **adjList;

GraphNode *createNode(int val)
{
    GraphNode *temp= (GraphNode*) malloc(sizeof(GraphNode));
    temp->data=val;
    temp->next=NULL;

}

int dfs(int visited[], int n, int s)
{
    if(visited[s]==0)
    {
        visited[s]=1;
        GraphNode *temp= (GraphNode*) malloc(sizeof(GraphNode));
        temp= adjList[s];
        while(temp!=NULL)
        {
            int v= temp->data;
            temp= temp->next;

            if(visited[v]==0)
            {
                return dfs(visited,n,v)+1;
            }
        }
    }
}
int main()
{
    freopen("input3.txt", "r", stdin);

    int n, e;
    scanf("%d%d", &n,&e);
    adjList= (GraphNode*)malloc(n*sizeof(GraphNode));

    for(int i=0; i<n; i++)
    {
        adjList[i]=NULL;
    }

    for(int i=0; i<e; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        GraphNode *temp;
        temp= createNode(v);
        temp->next= adjList[u];
        adjList[u]= temp;
    }

    int x=0;
    for(int i=0; i<n; i++)
    {
        int visited[n];
        for(int j=0; j<n; j++)
        {
            visited[j]=0;
        }

        x+= dfs(visited, n,i);
    }
    if(x==n*n)
    {
        printf("Strongly Connected Graph\n");
    }
    else
    {
        printf("Not Strongly Connected Graph\n");
    }

    return 0;
}
