/*

The Global Statistics Board has recorded the falling of mangoes in a fruit field for S successive years. The fruit field can be expressed as a matrix with dimensions M×N. Each field of the matrix can comprise over one mango tree.

Interestingly enough, every year there was strictly one mango fall, so the Board decided to write down S pairs of numbers (mi,ni) that denote the row and column of the spot where the mango fell during the ith year. By next year, a new tree grew at that spot.

Your task is to figure out the squared distance between the nearest tree and the mango that fell, measured in unit fields of the matrix (we assume it is that tree from which the mango fell).

The distance between fields (m1,n1) and (m2,n2) in the matrix are calculated as,

Input format
The first line of input contains two integers, M and N, the number of rows and columns of the matrix.

Each of the following M lines contains N characters ’x’ or ’.’. The character ’.’ denotes an empty field, and the character ’x’ denotes a field with at least one tree.

The fruit field will initially contain at least one tree.
After that, an integer S follows, the number of years the fruit field has been under observation.
Each of the following S lines describes the falls of the mangoes. Each line contains a pair of space-separated integers mi, ni that denote the row and column of the spot where the mango fell in the ith year.

Output format
Display S numbers, the required squared distances from the task, each in its own line.

Code constraints
1<=M,N<=500
1<=S<=105
1<=mi≤M
1<=ni<=N
Sample testcases
Input 1
3 3
x..
...
...
3
1 3
1 1
3 2
Output 1
4
0
5
Input 2
5 5
..x..
....x
.....
.....
.....
4
3 1
5 3
4 5
3 5
Output 2
8
8
4
1
*/
// You are using GCC
// 4/5 testcase passing
#include <bits/stdc++.h>
using namespace std;

int dist(int a, int b, int m, int n) {
    return pow(a - m, 2) + pow(b - n, 2);
}
int dfs(vector<string>& grid, vector<vector<bool> >& vis, int i, int j, int a, int b) {
    // int n=
    int temp = INT_MAX;
    if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size()) {
        if (vis[i][j]) return temp;
        vis[i][j] = true;

        if (grid[i][j] == 'x') return dist(i, j, a, b);
        temp = min(temp, dfs(grid, vis, i + 1, j, a, b));
        temp = min(temp, dfs(grid, vis, i, j + 1, a, b));
        temp = min(temp, dfs(grid, vis, i - 1, j, a, b));
        temp = min(temp, dfs(grid, vis, i, j - 1, a, b));
        return temp;
    }
    return temp;
}
int main() {
    int r, c;
    cin >> r >> c;
    vector<string> grid(r);

    for (int i = 0; i < r; i++)
        cin >> grid[i];

    int n;
    cin >> n;

    while (n--) {
        vector<vector<bool> > vis(r, vector<bool>(c, false));
        int a, b;
        cin >> a >> b;
        a--, b--;
        cout << dfs(grid, vis, a, b, a, b) << "\n";
        grid[a][b] = 'x';
    }
}
