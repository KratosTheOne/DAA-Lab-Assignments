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

void SelectionSort(int* a, int n)
{
    int comparisons = 0, swaps = 0;
    for(int i = 0; i < n-1; i++)
    {
        swaps++;
        for(int j = i+1; j < n; j++)
        {
            comparisons++;
            if(a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printArray(a, n);
    cout << endl;
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
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
        SelectionSort(a, n);
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
Comparisons: 28
Swaps: 7
21 32 34 46 51 54 65 76 78 97
Comparisons: 45
Swaps: 9
-12 22 31 42 46 54 65 65 86 223 324 325 553 645 652
Comparisons: 105
Swaps: 14
*/


