
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

void merger(int* a, int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2], i, j, k;
    for(i = 0; i < n1; i++)
        L[i] = a[l+i];
    for(j = 0;j < n2; j++)
        R[j] = a[m+1+j];
    i = 0; j = 0; k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void Sort(int* a, int l, int h)
{
    if(l < h)
    {
        int mid = l + (h - l) / 2;
        Sort(a, l, mid);
        Sort(a ,mid+1 , h);
        merger(a, l, mid, h);
    }
}

int BinarySearch(int* a, int l, int h)
{
    int mid, flag = 1;
    while(h >= l)
    {
        mid = (h+l) / 2;
        if(a[mid] == a[mid+1])
        {
            flag = 0;
            break;
        }
        else if(a[mid] > a[mid+1])
            h = mid - 1;
        else if(a[mid] < a[mid+1])
            l = mid + 1;
    }
    return flag;
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
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Sort(a, 0, n-1);
        int flag = BinarySearch(a, 0, n-1);
        if(flag)
            cout << "NO" << endl;
        else
            cout << "YES" <<endl;
    }
    return 0;
}

/*
Test Cases
Input
3
8
-23 65 -31 76 46 89 45 32
10
54 65 34 76 78 97 46 32 51 21
15
65 42 223 645 652 31 324 22 553 -12 54 65 86 46 325
Output
﻿﻿NO
NO
NO
*/

