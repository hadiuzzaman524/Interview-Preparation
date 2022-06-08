#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int data;
    struct queue *next;
} queue;
queue *front=NULL;
queue *rear= NULL;

void enqueue(int val)
{

    queue *node= (queue*)malloc(sizeof(queue));
    node->data=val;
    node->next=NULL;

    if(front==NULL && rear==NULL)
    {
        front=rear=node;
    }
    else
    {
        rear->next= node;
        rear= node;
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
        val= temp->data;
        free(temp);
        return val;
    }
}

int isEmpty()
{
    int c=0;
    queue *temp= (queue*) malloc(sizeof(queue));
    temp=front;
    while(temp)
    {
        c++;
        temp=temp->next;
    }
    if(c==0)
        return 1;
    return 0;
}

int adjMatrix[1000][1000];
int visited[1000][1000];
int distance[1000][1000];
int r, c;
int dx[]= {-1,0,1,0};
int dy[]= {0,-1,0,1};

int valid(int r1, int c1)
{
    if((r1>=0 && r1<r) && (c1>=0 && c1<c) && visited[r1][c1]==0)
        return 1;
    return 0;
}

void bfs(int i, int j)
{
    enqueue(i);
    enqueue(j);
    visited[i][j]=1;
    distance[i][j]=0;

    while(!isEmpty())
    {
        int ui= dequeue();
        int uj= dequeue();

        for(int k=0; k<4; k++)
        {
            int vi= ui+dx[k];
            int vj= uj+dy[k];

            if(valid(vi,vj))
            {
                enqueue(vi);
                enqueue(vj);
                visited[vi][vj]=1;
                distance[vi][vj]= distance[ui][uj]+1;
            }
        }

    }
}
int main()
{

    int bom, row, col, n_bom;
    int sr,sc,dr,dc;
    while(scanf("%d%d", &r,&c)==2 && r)
    {

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                adjMatrix[i][j]=0;
                visited[i][j]=0;
                distance[i][j]=0;
            }
        }
        scanf("%d",&bom);
        while(bom--)
        {
            scanf("%d%d", &row,&n_bom);

            while(n_bom--)
            {
                scanf("%d", &col);
                adjMatrix[row][col]=1;
                visited[row][col]=1;

            }
        }
        scanf("%d%d", &sr,&sc);
        scanf("%d%d", &dr,&dc);

        bfs(sr, sc);
        printf("%d\n", distance[dr][dc]);

    }

    return 0;
}
