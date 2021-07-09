/*
Amazon Fresh is a grocery delivery service that offers consumers the option of purchasing their groceries online and having them delivered on schedule. The Amazon Fresh team is planning a route for a delivery truck to deliver customer orders in the city of Techlandia. The planner will create a delivery area for each order to effectively plan the route. The area is abstracted as a grid. Not all locations are accessible by road. The truck only needs to make a single delivery
Write an algorithm to determine the minimum distance required for the truck to deliver the order.

ASSUMPTIONS:

Some places in the delivery area cannot be accessed by the deliver, as there are no roads in those locations.
The delivery area can be represented as a two-dimensional grid of integers, where each integer represents one cell.
The truck must start from the top left. corner of the area, which is always accessible and can move one cell up, down, left, or right at a time. The truck must navigate around the areas without roads and cannot leave the area.
- The accessible areas are represented as 1 areas without roads are represented by 0 and the order destination is represented by 9.

* Input format
The first line of input denotes the matrix size. The following lines denote the value of each row

* Output format
Return an integer representing the total distance traversed to deliver the order else return-1

* Code constraints
1 <= rows, columns <= 10^3

* Sample testcases
Input 1
3
1 0 0
1 0 0
1 9 1
Output 1
3

*/
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