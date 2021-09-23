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

void swapHelper(int* a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int part(int* a, int l, int h)
{
    int pivot_ele = a[h], i = l;
    for(int j = l; j <= h; j++)
    {
        if(a[j] < pivot_ele)
        {
            i++;
            swapHelper(a,j,i);
        }
    }
    swapHelper(a,h,i);
    return i;
}

int kthSmallest(int* a, int l,int h, int k)
{
    int p = part(a, l, h);
    if(p == k-1)
        return a[p];
    else if(p < k-1)
        return kthSmallest(a, p+1, h, k);
    else
        return kthSmallest(a, l, p-1, k);
    return INT_MIN;
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
        int a[n];
        for(int i=0; i<n; i++)
            cin >> a[i];
        int k;
        cin >> k;
        int ans = kthSmallest(a, 0, n-1, k);
        if(k < n)
            cout << ans << endl;
        else
            cout << "Not present" << endl;
    }
    return 0;
}

/*
Test Cases
Input

2
10
123 656 54 765 344 514 765 34 765 234
3
15
43 64 13 78 864 346 786 456 21 19 8 434 76 270 601
8

Output

﻿123
78

*/




