/*
Given an array of integers and a sum, the task is to count all subsets of given array with the sum equal to given sum.





Input format
The input consists of two integers n and s, denoting the size of the array and the checksum value. It is followed by space-separated array elements in the same line.



Output format
Count all the subsets of given array with the sum equal to given sum.

Code constraints
1<=n<=10^5

1<=a[i]<=10^5

1<=sum<=10^5

Sample testcases
Input 1
4 10 3 5 6 7
Output 1
1
*/
//testcase 4/5
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int> > dp(n + 1, vector<int>(s + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n + 1; i++) dp[i][0] = 1;
    for (int i = 1; i <= s; i++) dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            if (v[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
        }
    }
    cout << dp[n][s];
}
