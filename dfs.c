#include <stdio.h>
int graph[20][20];


void dfs(int visited[], int n, int s)
{

    if(visited[s]==0)
    {
        printf("%d ", s);
        visited[s]=1;

        for(int i=0; i<n; i++){
            if(graph[s][i]==1 && visited[i]==0){
                dfs(visited,n, i);
            }
        }

    }
}
int main()
{
    int n, e;
    printf("How many node and edges? ");
    scanf("%d %d", &n, &e);

    int visited[n];
    for(int i=0; i<n; i++)
        visited[i]=0;

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
        printf("Enter source and destination: ");
        scanf("%d %d", &s, &d);
        graph[s][d]=1;
    }

    dfs(visited, n, 0);

    return 0;
}
