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

void printarray(int* a, int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

void InsertionSort(int* a, int n)
{
    int key, i, j, comparisons = 0, shifts = 0;
    for(int i = 1; i < n; i++)
    {
        shifts++;
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
            comparisons++;
            shifts++;
        }
        a[j+1] = key;
    }
    printarray(a,n);
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Shifts: " << shifts << endl;
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
        InsertionSort(a, n);
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
Comparisons: 13
Shifts: 20
21 32 34 46 51 54 65 76 78 97
Comparisons: 28
Shifts: 37
-12 22 31 42 46 54 65 65 86 223 324 325 553 645 652
Comparisons: 54
Shifts: 68
*/

