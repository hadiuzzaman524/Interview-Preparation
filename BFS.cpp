#include <bits/stdc++.h>
using namespace std;

void bfs(vector< vector<int> > adj, int s, int n)
{
    int visited[n]= {false};
    queue<int> q;
    q.push(s);
    visited[s]=true;
    int level[n];
    level[s]=0;

    cout<< "BFS result: "<<endl;
    while(!q.empty())
    {
        int top= q.front();
        q.pop();
        cout<< top<< " ";

        for(int i=0; i< adj[top].size(); i++)
        {

            int temp= adj[top][i];

            if(visited[temp]==false)
            {
                q.push(temp);
                visited[temp]=true;
                level[temp]= level[top]+1;
            }
        }
    }
    cout<< endl<< "Level: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<s<< " To Destination "<< i << " : "<< level[i]<< endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);

    int n, e;
    // cout<< "How many node and edge? ";
    cin>>n>>e;

    vector< vector<int> > adj(n);

    for(int i=0; i<e; i++)
    {
        int a, b;
        // cout<< "Enter source and destination "<< i+1<< ": ";
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<< "Adjacency List: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<< adj[i][j]<< " ";
        }
        cout<<endl;
    }

    cout<<endl;
    bfs(adj, 0, n);


    return 0;
}
