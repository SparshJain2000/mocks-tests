/*

Given a grid with each cell consisting of positive, negative or no points i.e, zero points. We can move across a cell only if we have positive points ( > 0 ). Whenever we pass through a cell, points in that cell are added to our overall points. We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :



1.From a cell (i, j) we can move to (i+1, j) or (i, j+1).

2.We cannot move from (i, j) if your overall points at (i, j) are <= 0.

3.We have to reach (n-1, m-1) with minimum positive points i.e., > 0.



Example:

Input: points[m][n] = { {-2, -3,  3}, 

                       {-5, -10, 1}, 

                       {10, 30, -5} 

                     };
Output: 7
Explanation: 
7 is the minimum value to reach destination with 
positive throughout the path. Below is the path.

(0,0) -> (0,1) -> (0,2) -> (1, 2) -> (2, 2)
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int grid[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    }
    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    dp[n][m] = grid[n - 1][m - 1] > 0 ? 1 : abs(grid[n - 1][m - 1]) + 1;
    for (int i = n - 1; i >= 1; i--) dp[i][m] = max(dp[i + 1][m] - grid[i - 1][m - 1], 1);
    for (int i = m - 1; i >= 1; i--) dp[n][i] = max(dp[n][i + 1] - grid[n - 1][i - 1], 1);
    for (int i = n - 1; i >= 1; i--) {
        for (int j = m - 1; j >= 1; j--) {
            int temp = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = max(temp - grid[i - 1][j - 1], 1);
        }
    }
    cout << dp[1][1];
}
