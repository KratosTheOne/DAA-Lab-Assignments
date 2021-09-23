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

void printArray(int* a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int comparison = 0, inversions = 0;

void Merge(int* a, int l, int mid, int r)
{
    int n1 = mid-l+1, n2=r-mid;
    int Lefta[n1], Righta[n2], i, j, k;
    for(i = 0; i < n1; i++)
        Lefta[i] = a[l+i];
    for(j = 0; j < n2; j++)
        Righta[j] = a[mid+1+j];
    i = 0; j = 0; k = l;
    while(i < n1 && j < n2)
    {
        if(Lefta[i] <= Righta[j])
        {
            comparison++;
            a[k] = Lefta[i];
            i++;
        }
        else
        {
            comparison++;
            a[k] = Righta[j];
            j++;
            inversions += (mid+1) - (l+i);
        }
        k++;
    }
    while(i < n1)
    {
        a[k++] = Lefta[i++];
    }
    while(j < n2)
    {
        a[k++] = Righta[j++];
    }
}

void MergeSort(int* a, int l, int h)
{
    if(l < h)
    {
        int mid = l + (h - l) / 2;
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, h);
        Merge(a, l, mid, h);
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
            cin >> a[i];
        comparison = 0, inversions = 0;
        MergeSort(a, 0, n-1);
        printArray(a, n);
        cout << endl;
        cout << "comparisons: " << comparison << endl;
        cout << "inversions: " << inversions << endl;
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

-31 -23 32 45 46 65 76 89
comparisons: 16
inversions: 13
21 32 34 46 51 54 65 76 78 97
comparisons: 22
inversions: 28
-12 22 31 42 46 54 65 65 86 223 324 325 553 645 652
comparisons: 43
inversions: 54
*/



