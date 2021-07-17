/*
Write a program to find the longest palindromic sub-sequence. If more than one such sequence is found, print the last one.

Input format
To get a string.

Output format
Displays the sequence.

Code constraints
Strings only.

Sample testcases
Input 1
apple
Output 1
pp
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    string p = s;
    reverse(p.begin(), p.end());
    int n = p.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    string ans = "";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == p[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // for(int i=n;i>=1;i--){
    //     for(int j=n;j>=1;j--){
    //         if()
    //     }
    // }
    int i = n, j = n;
    while (i > 0 && j > 0) {
        // cout<<s[i-1];
        if (dp[i][j] > dp[i - 1][j] && dp[i][j] > dp[i][j - 1])
            ans += (s[i - 1]), i--, j--;
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    cout << ans << " " << endl;
}
