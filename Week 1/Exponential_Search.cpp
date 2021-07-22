// Exponential Search

#include<bits/stdc++.h>
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
        int a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int key;
        cin >> key;
        int comparisons = 0;
        bool present = false;
        if(a[0] == key)
        {
            comparisons = 1;
            cout << "Present" << " " << comparisons << "\n";
        }
        int j = 1;
        while(j < n && a[j] <= key)
        {
            comparisons++;
            j *= 2;
        }
        // binary search to find key
        int low = j / 2;
        int high = min(j, n - 1);
        int mid;
        while(high >= low)
        {
            comparisons++;
            mid = (high + low) / 2;
            if(a[mid] == key)
            {
                present=true;
                break;
            }
            else if(a[mid] > key)
            {
                high = mid - 1;
            }
            else if(a[mid] < key)
            {
                low = mid + 1;
            }
        }
        if(present)
            cout << "Present" << " " << comparisons << "\n";
        else
            cout << "Not Present" << " " << comparisons << "\n";
    }
    return 0;
}
/*
example. Input
3
5
10 20 40 45 55
45
5
10 15 25 45 55
15
8
1 2 5 7 12 35 55 98
200
Output
Present 3
Present 2
Not Present 6
*/
