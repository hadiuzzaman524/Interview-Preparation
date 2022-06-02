#include <stdio.h>
typedef struct stack
{
    int data;
    struct stack *next;
} stack;

stack *head= NULL;
int graph[20][20];
void push(int val)
{

    stack *temp= (stack*)malloc(sizeof(stack));
    temp->data=val;
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next= head;
        head=temp;
    }
}

int pop()
{

    if(head!=NULL)
    {
        int val= head->data;
        stack *temp= (stack*) malloc(sizeof(stack));
        head=head->next;
        free(temp);
        return val;
    }

}

int isEmpty()
{

    if(head==NULL)
        return 1;
    return 0;
}

void dfs(int visited[], int n, int s)
{

    if(visited[s]==0)
    {
        visited[s]=1;
        printf("%d ", s);

        for(int i=0; i<n; i++)
        {

            int dest= graph[s][i];
            if(dest==1 && visited[i]==0)
            {

                dfs(visited,n,i);

            }
        }

    }
    push(s);
}


int main()
{
    freopen("input.txt", "r", stdin);
    int n, e;
    printf("How many node and edges? ");
    scanf("%d %d", &n, &e);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            graph[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int s, d;
        scanf("%d %d", &s, &d);
        graph[s][d]=1;
    }
    int visited[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=0;
    }

    for(int i=0; i<n; i++)
    {
        if(visited[i]==0)
        {
            dfs(visited, n,i);
        }
    }


    printf("\n\nTopological Sort Result: ");
    while(!isEmpty())
    {
        int top= pop();
        printf("%d ", top);
    }

    return 0;
}
