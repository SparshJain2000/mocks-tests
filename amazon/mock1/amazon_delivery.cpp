#include <bits/stdc++.h>
using namespace std;
int util(vector<vector<int> > &grid, int i, int j, vector<vector<bool> > &vis) {
    int n = grid.size();
    if (i >= 0 && j >= 0 && i < n && j < n) {
        if (vis[i][j]) return INT_MAX - 1;
        vis[i][j] = true;
        if (grid[i][j] == 9) return 0;
        if (grid[i][j] == 0) return INT_MAX - 1;
        int temp = INT_MAX - 1;

        temp = min(temp, 1 + util(grid, i + 1, j, vis));
        temp = min(temp, 1 + util(grid, i - 1, j, vis));
        temp = min(temp, 1 + util(grid, i, j - 1, vis));
        temp = min(temp, 1 + util(grid, i, j + 1, vis));
        return temp;
    }
    return INT_MAX - 1;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int> > grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            grid[i][j] = temp;
        }
    vector<vector<bool> > vis(n, vector<bool>(n, false));
    cout << util(grid, 0, 0, vis);
    return 0;
}