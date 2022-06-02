#include <stdio.h>

int adjMat[20][20];

typedef struct queue
{

    int data;
    struct queue *next;
} queue;

queue *front= NULL;
queue *rear= NULL;

void enqueue(int val)
{

    queue *temp = (queue *) malloc(sizeof(queue));
    temp->data=val;
    temp->next = NULL;

    if(front==NULL && rear==NULL)
        front=rear=temp;
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
        rear= NULL;
    }
    else if(front!=NULL)
    {
        queue *temp= (queue *) malloc(sizeof(queue));
        temp= front;
        val= front->data;
        front= front->next;
        free(temp);
    }

    return val;
}

int isEmpty()
{

    int c=0;

    queue *temp= (queue*) malloc(sizeof(queue));
    temp= front;
    while(temp!=NULL)
    {
        temp= temp->next;
        c++;
    }

    if(c==0)
        return 1;
    return 0;
}

void topologicalSort(int indegree[], int n)
{

    for(int i=0; i<n; i++)
    {
        if(indegree[i]==0)
        {
            enqueue(i);
            printf("enqueue: %d \n", i);
        }
    }

    for(int i=0; i<n; i++)
        printf("%d ", indegree[i]);
    printf("\n");

    while(!isEmpty())
    {
        int top= dequeue();
        printf("dequeue: %d \n", top);

        for(int i=0; i<n; i++)
        {
            if(adjMat[top][i]==1 && indegree[i]>0)
            {
                --indegree[i];
              /*  for(int k=0; k<n; k++)
                    printf("%d ", indegree[k]);
                printf("\n");*/
                if(indegree[i]==0)
                {
                    printf("enqueue: %d \n", i);

                    enqueue(i);
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);

    int n,e;
    printf("How many node and edges? ");
    scanf("%d %d", &n, &e);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            adjMat[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int s,d;
        scanf("%d %d", &s, &d);
        adjMat[s][d]=1;

    }

    printf("\n");
   /* for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }*/

    int indegree[n];
    for(int i=0; i<n; i++)
    {
        indegree[i]=0;
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            indegree[i]+= adjMat[j][i];
        }
    }

    topologicalSort(indegree,n);

    return 0;
}
