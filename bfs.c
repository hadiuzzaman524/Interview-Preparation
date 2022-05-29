/*#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int value;
    struct queue *next;
} queue;

queue *front= NULL;
queue *rear= NULL;

void push(int val)  // a-> b->
{

    queue *temp= (queue*) malloc(sizeof(queue));
    temp->value= val;
    temp->next= NULL;

    if((front==NULL) && (rear==NULL))
    {
        front=rear=temp;
    }
    else
    {
        rear->next= temp;
        rear= temp;
    }
}

int pop()
{

    int val;

    if(front==rear)
    {
        rear=NULL;

    }

    if(front!=NULL)
    {

        queue *temp= (queue*) malloc(sizeof(queue));
        temp= front;

        val=front->value;
        front=front->next;
        free(temp);
    }




    return val;
}

void display()
{


    queue *temp= (queue*) malloc(sizeof(queue));
    temp= front;

    while(temp!=NULL)
    {
        printf("%d ", temp->value);
        temp=temp->next;
    }

}

int isEmpty()
{

    int  c=0;

    queue *temp= (queue *) malloc(sizeof(queue));

    temp= front;

    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }

    if(c==0)
    {
        return 1;
        //  free(front);
        // free(rear);
    }


    return 0;

}


int main()
{
    push(55);
    push(60);
    push(79);
    push(22);

    pop();
    pop();
    pop();
    pop();

    push(423);
    push(32);
    pop();
    pop();
    push(34);


    display();

    if(isEmpty())
    {
        printf("Empty");
    }
    else
    {
        printf("Not Empty");
    }

    return 0 ;
}

/*
void bfs(int adjMat[][8], int s)
{

    int visited[8]= {0};
    visited[s]=1;

    queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        int top= q.pop();

        for(int j=0; j<n; j++)
        {
            if(adjMat[top][j]==1 && visited[j]==0)
            {
                visited[j]=1;
                q.push(j);
            }
        }
    }
}
int main()
{
    pirntf("How many node and edges? ");
    int n, e;
    scanf("%d %d", &n, &e);

    int adjMat[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            adjMat[i][j]=0;

    for(int i=0; i<e; i++)
    {
        printf("Enter Source and Destination %d: ", i);
        int s, d;
        scanf("%d %d", &s, &d);

        adjMat[s][d]=1;
    }

    bfs(adjMat,0);


    return 0;
}
*/

#include <stdio.h>

typedef struct queue
{

    int data;
    struct queue *next;
} queue;

queue *front=NULL;
queue *rear= NULL;

void enqueue(int data)
{

    queue *temp= (queue *) malloc(sizeof(queue));
    temp->data=data;
    temp->next=NULL;

    if(front==NULL && rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->next= temp;
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
        queue *temp= (queue *) malloc(sizeof(queue));
        temp= front;
        val=front->data;
        front=front->next;
        free(temp);

    }

    return val;
}

int isEmpty()
{

    int c=0;

    queue *temp= (queue *) malloc(sizeof(queue));
    temp= front;

    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    if(c==0)
        return 1;
    return 0;
}

#define total 7
void bfs(int adjMat[][total], int s)
{

    int visited[total]= {0};
    visited[s]=1;

    enqueue(s);

    while(!isEmpty())
    {
        int i= dequeue();
        printf("%d ", i);
        for(int j=0; j<total; j++)
        {

            if(adjMat[i][j]==1 && visited[j]==0)
            {

                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

int main()
{

    int n,e;
    printf("How many edges: ");
    scanf("%d", &e);

    int adjMat[total][total];

    for(int i=0; i<total; i++)
        for(int j=0; j<total; j++)
            adjMat[i][j]=0;

    for(int i=0; i<e; i++)
    {
        int s, d;
        printf("Enter source and destination: ");
        scanf("%d %d", &s, &d);
        adjMat[s][d]=1;

    }

    for(int i=0; i<total; i++)
    {
        for(int j=0; j<total; j++)
        {
            printf("%d ", adjMat[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    bfs(adjMat, 1);

}
