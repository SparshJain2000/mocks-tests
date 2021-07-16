/*
An art therapist conducts a workshop to teach the importance of colors in every aspect of life. According to her, the priority of each problem/situation is unique. So it is important to prioritize our problems and solve it level by level.

For demonstrating this, she gave a sheets to every participant and access to unlimited number of color pencils. Each sheet had concentric squares of varied sizes. The participants were asked to color the squares in the each sheet with different colors. Suppose a participant got a sheet of 5 squares, he/she has to use 5 colors.

Write a code to implement this pattern.

Input format
Single line input which has a positive integer.

Output format
Output displays the concentric squares as shown in sample test case.

Sample testcases
Input 1
6
Output 1
6 6 6 6 6 6 6 6 6 6 6 
6 5 5 5 5 5 5 5 5 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 2 1 2 3 4 5 6 
6 5 4 3 2 2 2 3 4 5 6 
6 5 4 3 3 3 3 3 4 5 6 
6 5 4 4 4 4 4 4 4 5 6 
6 5 5 5 5 5 5 5 5 5 6 
6 6 6 6 6 6 6 6 6 6 6 
*/
// 3/5 test case passing 😥
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int temp = n;
        for (int j = 0; j < 2 * n - 1; j++) {
            if (i > j)
                cout << (temp--) << " ";
            else if (j + i >= 2 * n - 2)
                cout << (temp++) << " ";
            else
                cout << temp << " ";
        }
        cout << '\n';
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = n;
        for (int j = 0; j < 2 * n - 1; j++) {
            if (i > j)
                cout << temp-- << " ";
            else if (j + i >= 2 * n - 2)
                cout << temp++ << " ";
            else
                cout << temp << " ";
        }
        cout << "\n";
    }
}
