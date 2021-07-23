#include<bits/stdc++.h>
using namespace std;
fastio()
{
    ios_base::sync_with_stdio(false);           //This will help clear
    cin.tie(0);                                 //the cin and cout
    cout.tie(0);                                //buffer and generate multiple
    cin.exceptions(ios::badbit | ios::failbit); //outputs together at the end.
}
int firstOccurence(int a[], int low, int high, int x, int n)
{
    if(high >= low)
    {
        int mid = (low + high) / 2;
        if((mid == 0 || x > a[mid-1]) && a[mid] == x)
            return mid;
        else if(x > a[mid])
            return firstOccurence(a, (mid+1), high, x, n);
        else
            return firstOccurence(a, low, (mid-1), x ,n);
    }
    return -1;
}
int lastOccurence(int a[], int low, int high, int x, int n)
{
    if(high >= low)
    {
        int mid = (low + high) / 2;
        if((mid == n-1 || x < a[mid+1]) && a[mid] == x)
            return mid;
        else if(x < a[mid])
            return lastOccurence(a, low, (mid-1), x, n);
        else
            return lastOccurence(a, (mid+1), high, x ,n);
    }
    return -1;
}
int countOccurence(int a[], int x, int n)
{
    int first, last;
    first = firstOccurence(a, 0, n-1, x, n);
    if(first == -1)
        return first;
    last = lastOccurence(a, first, n-1, x, n);
    return last - first + 1;
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
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int key;
        cin >> key;
        int counter = countOccurence(a, key, n);
        if(counter == -1)
            cout << "Key not present" << "\n";
        else
            cout << key << " - " << counter << "\n";
    }
    return 0;
}
/*
Test Cases
Input
2
10
235 235 278 278 763 764 790 853 981 981
981
15
1 2 2 3 3 5 5 5 25 75 75 75 97 97 97
75
Output
981 - 2
75 - 3
*/
