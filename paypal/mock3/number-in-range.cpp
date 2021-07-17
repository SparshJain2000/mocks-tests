/*

Write a program to count the number of array elements in the range [L,R] which divides all numbers in the range [L,R].

Input format
Input consists of integer 'N' denoting the size of the array, followed by 'N' number of array elements, followed by L and R respectively.

Output format
Displays the number of elements that divide (with remainder 0) all elements in the range L to R
Code constraints
0 < = L < = R < = N

Sample testcases
Input 1
5
2 4 8 64 16
1 4
Output 1
1
Input 2
6
4 2 4 2 4 2
1 6
Output 2
3
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int hcf(int a, int b) {
    if (!a) return b;
    return hcf(b % a, a);
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int l, r;
    cin >> l >> r;
    l--, r--;
    int ele = v[l];

    for (int i = l + 1; i <= r; i++)
        ele = hcf(ele, v[i]);

    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (ele % v[i] == 0) ans++;
    }
    cout << ans;
}
