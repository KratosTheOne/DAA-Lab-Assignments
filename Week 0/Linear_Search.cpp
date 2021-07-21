/**
 Question-1:
 Given an array of nonnegative integers, design a linear algorithm and implement it using a program
 to find whether a given key element is present in the array or not.
 Also, find the total number of comparisons for each input case.
 (Time Complexity = O(n), where n is the size of input).
 Input Format:
 n - no. of test cases
 next n lines:
 x - size of array
 a1 a2 a3 .... asize - x spaced non-negative integers
 key - key element to find
 Output Format:
 YES or NO - if key is present or absent
 comparisions - no. of comparisons made
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);           //This will help clear
    cin.tie(0);                                 //the cin and cout
    cout.tie(0);                                //buffer and generate multiple
    cin.exceptions(ios::badbit | ios::failbit); //outputs together at the end.
    freopen("LS_input.txt", "r", stdin);
    int t; // No. of Test Cases
    cin >> t;
    while(t--)
    {
        int n; //limit
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int key;
        cin >> key; //the key to be founded
        bool found = true;
        int comparisons = 0;
        for(int i = 0; i < n; i++)
        {
            comparisons++;
            if(arr[i] == key)
            {
                found = true;
                break;
            }
            else
                found = false;
        }
        if(found)
            cout << "YES\n";
        else
            cout << "NO\n";
        cout << comparisons << "\n";
    }
    return 0;
}
// Overall complexity of the Program is O(n).
