// Binary Search
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
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int key;
        cin >> key;
        int comparisons = 0;
        bool present = false;
        int l = 0, r = n - 1, mid;
        while(r >= l)
        {
            comparisons++;
            mid = (r + l) / 2;
            if(arr[mid] == key)
            {
                present = true;
                break;
            }
            else if(arr[mid] > key)
                r = mid - 1;
            else if(arr[mid] < key)
                l = mid + 1;
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
2
5
2 3 4 10 40
10
5
1 2 3 5 10
1
Output
Present 2
Present 2
*/
