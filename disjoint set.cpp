#include <bits/stdc++.h>
using namespace std;

vector<int> connectedSet[100];

typedef struct Node
{
    int parent, rankk;
} Node;

void makeSet(Node obj[], int x)
{
    obj[x].parent= x;
    obj[x].rankk=0;
    return;
}

int findSet(Node obj[], int x)
{

    if(obj[x].parent!=x)

      obj[x].parent= findSet(obj, obj[x].parent);

    return obj[x].parent;
}
void link(Node obj[], int u, int v)
{
    if(obj[u].rankk> obj[v].rankk)
    {
        obj[v].parent= u;
        connectedSet[u].push_back(v);
    }
    else
    {
        obj[u].parent= v;
        connectedSet[v].push_back(u);

        if(obj[u].rankk==obj[v].rankk)
        {
            obj[v].rankk++;
        }
    }
}
void setUnion(Node obj[], int x, int y)
{

    int u= findSet(obj, x);
    int v= findSet(obj, y);

    if(u!=v)
    {
        link(obj, u, v);
    }

}



int main()
{
    freopen("input4.txt","r",stdin);

    int n,e;
    cin>>n>>e;

    Node obj[n];
    for(int i=0; i<n; i++)
    {
        makeSet(obj, i);
    }

    for(int i=0; i<e; i++)
    {
        int u,v;
        cin>>u>>v;
        setUnion(obj, u, v);
    }


    for(int i=0; i<n;i++){
            cout<< i<< ": ";
        for(int j=0; j<connectedSet[i].size(); j++){
            cout<< connectedSet[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;
}
