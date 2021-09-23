
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

bool isPathDFS(vector<vector<int>>& graphMatrix, int source, int des, int Size){
    bool visited[Size];
    stack<int> mainstack;
    visited[source-1] = true;
    mainstack.push(source-1);
    while(!mainstack.empty())
    {
        int curr = mainstack.top();
        mainstack.pop();
        if(curr+1 == des)
            return true;
        for(int i = 0;i < Size; i++)
        {
            if(graphMatrix[source][i] == 1 && !visited[i])
            {
               visited[i] = true;
               mainstack.push(i);
            }
        }
    }
    return false;
}

int main()
{
    fastio();
    int v;
    cin >> v;
    vector<vector<int>> graphMatrix(v, vector<int>(v));
    for(int i = 0; i < v; i++)
        for(int j = 0; j < v; j++)
            cin >> graphMatrix[i][j];
    int source, des;
    cin >> source;
    cin >> des;
    if(isPathDFS(graphMatrix, source, des, v))
        cout << "Yes path exixts" << endl;
    else
        cout << "No such path exixts" << endl;
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
1 5


Output

Yes path exixts

*/
