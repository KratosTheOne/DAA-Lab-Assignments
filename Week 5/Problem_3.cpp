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

int main()
{
    fastio();
    int n, i, j;
    cin >> n;
    int a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    int m;
    cin >> m;
    int b[m];
    for(j = 0;j < m; j++)
        cin >> b[j];
    i = 0; j = 0;
    while(i < n && j < m)
    {
        if(a[i] == b[j])
        {
            cout << a[i++] << " ";
        }
        else if(a[i] < b[j])
            i++;
        else
            j++;
    }
    return 0;
}

/*
Test Cases
Input

7
10 10 34 39 55 76 85
12
10 10 11 30 30 34 34 51 55 69 72 89


Output

10 10 34 55

*/






