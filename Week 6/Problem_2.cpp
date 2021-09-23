
#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

fastio()
{
     ios_base::sync_with_stdio(false);           //This will help clear
     cin.tie(0);                                 //the cin and cout
     cout.tie(0);                                //buffer and generate multiple
     cin.exceptions(ios::badbit | ios::failbit); //outputs together at the end.
}

bool isbipartite(vector<vector<int>>& graph, int s)
{
    int V = graph.size();
    vector<int> visited(V);
    for(int i = 0; i < V; i++)
        visited[i] = -1;
    visited[s] = 1;
    queue<int> qu;
    qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        if(graph[u][u] == 1)
            return false;
        for(int v = 0; v < V; v++)
        {
            if(graph[u][v] && visited[v] == -1)
            {
                visited[v] = 1 - visited[u];
                qu.push(v);
            }
            else if(graph[u][v] && visited[v] == visited[u])
                return false;
        }
    }
    return true;
}

int main()
{
    fastio();
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int> (n, 0));
    for(int i = 0;i < n; i++)
        for(int j = 0;j < n; j++)
            cin >> graph[i][j];
    if(isbipartite(graph, 0))
        cout << "Bipartite" << endl;
    else
        cout << "Not Bipartite" << endl;
    return 0;
}

/*
Test Cases
Input

5
0 1 1 0 0
1 0 1 1 1
1 1 0 1 0
0 1 1 0 1
0 1 0 1 0


Output

Not Bipartite

*/
