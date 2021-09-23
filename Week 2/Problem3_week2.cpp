
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
            cin >> a[i];
        int k, counter = 0;
        cin >> k;
        for(int i = 0;i < n-1; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(abs(a[i] - a[j]) == k)
                    counter++;
            }
        }
        cout << counter << endl;
    }
    return 0;
}

/*
Test Cases
Input
2
5
1 51 84 21 31
20
10
24 71 16 92 12 28 48 14 20 22
4
Output
2
4
*/
