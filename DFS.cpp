
#include <bits/stdc++.h>
using namespace std;

void bfs(vector< vector<int> > adj, int s, int n)
{
    int visited[n]= {false};
    stack<int> stk;
    stk.push(s);
    visited[s]=true;
    int level[n];
    level[s]=0;

    cout<< "DFS result: "<<endl;
    while(!stk.empty())
    {
        int top= stk.top();
        stk.pop();
        cout<< top<< " ";

        for(int i=0; i< adj[top].size(); i++)
        {

            int temp= adj[top][i];

            if(visited[temp]==false)
            {
                stk.push(temp);
                visited[temp]=true;
                level[temp]= level[top]+1;
            }
        }
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
