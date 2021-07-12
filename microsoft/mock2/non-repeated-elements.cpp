/*
You are given an array A containing 2*N+2 positive numbers, out of which N numbers are repeated exactly once and the other two numbers occur exactly once and are distinct. You need to find the other two numbers and print them in ascending order.



Input format
The input contains an integer N denoting the size of the array. The next line contains 2*N+2 space separated integers.

Output format
Print in a new line the two numbers in ascending order.

Code constraints
1<=N<=10^6

1<=A[i]<=5*10^8

Sample testcases
Input 1
2 1 2 3 2 1 4
Output 1
3 4
*/

// Testcase 2/5
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(2 * n + 1);
    for (int i = 0; i < ((2 * n) + 2); i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < ((2 * n) + 2); i++) {
        if (i == ((2 * n) + 1) || v[i] != v[i + 1])
            cout << v[i] << " ";
        else
            i++;
    }
}