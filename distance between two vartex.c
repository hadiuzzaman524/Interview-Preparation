#include <stdio.h>

typedef struct queue
{
    int data;
    struct queue *next;
} queue;

queue *front=NULL;
queue *rear=NULL;

void enqueue(int data)
{

    queue *temp= (queue*) malloc(sizeof(queue));
    temp->data=data;
    temp->next=NULL;

    if(front==NULL && rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}

int dequeue()
{
    int val;
    if(front==rear)
    {
        rear=NULL;
    }
    if(front!=NULL)
    {

        queue *temp= (queue*) malloc(sizeof(queue));
        temp=front;
        front=front->next;
        val=temp->data;
        free(temp);
        return val;
    }
}
int isEmpty()
{

    int c=0;
    queue *temp= (queue*) malloc(sizeof(queue));
    temp= front;

    while(temp)
    {
        c++;
        temp=temp->next;
    }
    if(c==0)
        return 1;
    return 0;
}

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
void bfs(int n, int s)
{
    int visited[n];
    int level[n];
    int parent[n];

    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }

    level[s]=0;
    visited[s]=1;
    parent[s]=s;

    enqueue(s);

    while(!isEmpty())
    {
        int u= dequeue();

        while(adjList[u]!=NULL)
        {
            int v= adjList[u]->data;

            if(visited[v]==0)
            {
                visited[v]=1;
                level[v]= level[u]+1;
                parent[v]= u;
                enqueue(v);
            }
            adjList[u]= adjList[u]->next;
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d to %d:  %d \n",s,i, level[i]);
    }

    printf("\n\n");
    int t=1;
    int now=t;
    printf("%d ", now);
    while(now!=s)
    {
        printf("%d ", parent[now]);
        now= parent[now];
    }

}
int main()
{
    freopen("input.txt", "r", stdin);
    int n, e;
    scanf("%d %d", &n, &e);

    adjList= (graphNode*) malloc(n*sizeof(graphNode));
    for(int i=0; i<n; i++)
    {
        adjList[i]=NULL;
    }
    graphNode *node;

    for(int i=0; i<e; i++)
    {
        int s, d;
        scanf("%d %d", &s, &d);

        node=createNode(d);
        node->next= adjList[s];
        adjList[s]=node;
        node= createNode(s);
        node->next= adjList[d];
        adjList[d]=node;

    }

    bfs(n,2);


    return 0;
}
