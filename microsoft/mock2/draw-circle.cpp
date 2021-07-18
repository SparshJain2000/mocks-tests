/*
Write a program to draw a circle using dots with radius N.
Input format
The single line input contains a single integer value of N.

Output format
You need to print the dotted circle.

Code constraints
Integers only.

Sample testcases
Input 1
2
Output 1
  . . .   
. . . . . 
. . . . . 
. . . . . 
  . . .   
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
double dist(int i, int j, int n, int m) {
    return sqrt(pow(n - i, 2) + pow(m - j, 2));
}
int main() {
    int n;
    cin >> n;
    int lim = 2 * n + 1;
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < lim; j++) {
            char c = ' ';
            if (dist(i, j, n, n) <= n + (sqrt(n * n + 1) - n)) c = '.';
            cout << c << ' ';
        }
        cout << '\n';
    }
}