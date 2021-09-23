#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

// fastio()
// {
//     ios_base::sync_with_stdio(false);           //This will help clear
//     cin.tie(0);                                 //the cin and cout
//     cout.tie(0);                                //buffer and generate multiple
//     cin.exceptions(ios::badbit | ios::failbit); //outputs together at the end.
//     return 0;
// }

int main()
{
    //fastio();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin>>a[i];
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                for(int k = j+1; k < n; k++)
                {
                    if(a[i] + a[j] == a[k])
                    {
                        flag = true;
                        cout << i+1 << "," << j+1 << "," << k+1 << endl;
                        break;
                    }
                }
            }
        }
        if(!flag)
            cout << "No sequence found!" << endl;
    }
    return 0;
}

/*
Test Cases
Input
3
5
1 5 84 209 341
10
24 28 48 71 86 89 92 120 194 201
15
64 69 82 95 99 107 113 141 171 350 369 400 511 590 666
Output
﻿No sequence found!
2,7,8
1,6,9
*/
