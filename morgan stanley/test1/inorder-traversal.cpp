/*
Write a program to do Inorder-traversal in a binary tree.

Input format
First line contains the input N.

The second line contains the N space-separated integers.

Output format
Inorder traversal elements.

Sample testcases
Input 1
4
1 2 3 4
Output 1
INORDER = 1  2  3  4  
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout << "INORDER = ";
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i] << "  ";
}
