#include <stdio.h>
typedef struct graphNode
{
    int data;
    struct graphNode *next;
} graphNode;
graphNode **adjList;

graphNode *createNode(int val)
{

    graphNode *temp= (graphNode*) malloc(sizeof(graphNode));
    temp->data=val;
    temp->next=NULL;

    return temp;
}

void dfs(int visited[], int n, int s)
{

    if(visited[s]==0)
    {
        visited[s]=1;
        printf("%d ", s);

        while(adjList[s]!=NULL)
        {
            int data= adjList[s]->data;

            if(visited[data]==0)
            {
                dfs(visited, n, data);
            }
            adjList[s]=adjList[s]->next;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    int n, e;
    scanf("%d %d", &n, &e);
    adjList= (graphNode*) malloc(n* sizeof(graphNode));

    for(int i=0; i<n; i++)
    {
        adjList[i]=NULL;
    }

    graphNode *node;

    for(int i=0; i<e; i++)
    {
        int s, d;
        scanf("%d %d", &s, &d);
        // for directed graph
        node= createNode(d);
        node->next= adjList[s];
        adjList[s]= node;

        node= createNode(s);
        node->next= adjList[d];
        adjList[d]= node;

    }

    /*  for(int i=0; i<n; i++){

          printf("%d : ", i);
          while(adjList[i]!=NULL){
              printf("%d ", adjList[i]->data);
              adjList[i]= adjList[i]->next;
          }
          printf("\n");
      }*/

    int visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }

    int c=0;
    for(int i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            dfs(visited, n, i);
            c++;
            printf("\n");
        }

    }

    printf("Number of connected component: %d\n", c);

    return 0;
}
