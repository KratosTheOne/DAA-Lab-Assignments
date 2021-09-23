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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        char a[n];
        multimap<int, char> mape;
        map<char, int> freq;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            freq[a[i]]++;
        }
        int flag = 0;
        for(auto i: freq)
            mape.insert({i.second, i.first});
        if(mape.rbegin()->first > 1)
        {
            cout << mape.rbegin()->second << "-" <<mape.rbegin()->first << endl;
            flag = 1;
        }
        if(!flag)
            cout << "No Duplicate Present" << endl;
    }
    return 0;
}

/*
Test Cases
Input

3
10
a e d w a d q a f p
15
r k p g v y u m q a d j c z e
20
g t l l t c w a w g l c w d s a a v c l

Output

a-3
No Duplicate Present
l-4

*/





