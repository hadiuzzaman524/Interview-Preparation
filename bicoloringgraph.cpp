#include <bits/stdc++.h>
using namespace std;

int num=0;

void total_cycle(vector< vector< int> > adj,bool visited[], int s, int n)
{
    int parent[n];

    if(visited[s]==false)
    {
        visited[s]=true;

        for(int i=0; i<adj[s].size(); i++)
        {

            int m= adj[s][i];

            if(visited[m]==false)
            {
                parent[m]= s;
                total_cycle(adj,visited,m,n);
            }
            else
            {
                if(parent[m]!=s)
                {
                    num++;
                }
            }
        }
    }


}

int main()
{

    freopen("input.txt", "r", stdin);

    int n,e;
    cin>>n>>e;

    vector< vector<int> > adj(n);

    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>> a>> b;
        adj[a].push_back(b);
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<adj[i].size(); j++)
            cout<< adj[i][j]<< " ";
        cout<<endl;
    }
    bool visited[n]= {false};
    total_cycle(adj, visited,0, n);
    cout<< num<<endl;

    return 0;
}
