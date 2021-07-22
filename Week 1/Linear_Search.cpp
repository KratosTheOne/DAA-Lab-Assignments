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
/*
Test Cases
4
5
1 2 3 4 5
4
10
10 20 30 40 50 60 70 80 90 100
55
6
39 41 97 113 198 21
21
50
64 23 38 67 22 25 87 45 28 40 27 39 21 30 64 6 93 25 8 38 1 74 40 50 50 30 30 68 40 14 79 50 4 76 51 57 11 94 91 50 20 44 51 79 41 10 86 2 36 40
45
*/
