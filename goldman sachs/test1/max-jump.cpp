/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Input format
Single line input consists of the array size followed by array elements.

Output format
Print an integer value denoting the minimum number of steps required to reach the end of the array. If 0 is encountered in the path then print the largest (most positive) value that can be stored in an int i.e, INT_MAX.

Sample testcases
Input 1
8 1 3 4 2 1 5 7 9
Output 1
4
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int max_jmp = i + v[i];
        int max_j = i + v[i];
        for (int j = i; j <= i + v[i]; j++) {
            if (j + v[j] > max_jmp) {
                max_jmp = v[j] + j;
                max_j = j;
            }
        }
        if (max_j == i) {
            cout << INT_MAX;
            return 0;
        }
        i = max_j - 1;
        ans++;
    }
    cout << ans;
}
