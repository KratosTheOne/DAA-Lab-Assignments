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

int comparison = 0, swaps = 0;

void printArray(int* a, int n){
    for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
}

void swapHelper(int* a, int i, int j){
    a[i] = a[i] + a[j];
    a[j] = a[i] - a[j];
    a[i] = a[i] - a[j];
    swaps++;
}

int part(int* a, int l, int h){
    int pivot_ele = a[l],i=l-1;
    for(int j=l; j <=h-1 ; j++){
        if(a[j]<pivot_ele){
            i++;
            swapHelper(a,i,j);
        }
        comparison++;
    }
    swapHelper(a,i+1,h);
    return (i+1);
}

void Sort(int* a, int l,int h){
    if(l<h){
        int p = part(a,l,h);
        Sort(a,l,p-1);
        Sort(a,p+1,h);
    }
}

int main()
{
    fastio();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin>>a[i];
        comparison=0,swaps=0;
        Sort(a,0,n-1);
        printArray(a,n);
        cout<<"\ncomparison: "<<comparison<<endl;
        cout<<"swaps: "<<swaps<<endl;
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

﻿21 32 65 45 46 23 89 76
comparison: 18
swaps: 8
32 51 46 34 21 54 76 65 78 97
comparison: 19
swaps: 14
22 12 31 46 42 54 325 63 65 86 324 652 223 553 645
comparison: 38
swaps: 23
*/



