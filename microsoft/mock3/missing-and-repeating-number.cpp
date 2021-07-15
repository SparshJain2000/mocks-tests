/*
Write a program to find the missing and repeating element in the array. Consider array contains element from 1 to N.

Input format
The single line input contains the number of elements followed by the elements of array.

Output format
You need to print the missing element at the first and followed by repeating element, use space as delimiter.

Code constraints
Integers only.

Sample testcases
Input 1
5
1 5 2 3 1
Output 1
4 1
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    long long int prod = 1;
    long long int prod2 = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        prod *= x;
        prod2 *= (i + 1);
    }
    int rep = (double)((n * (n + 1) / 2) - accumulate(v.begin(), v.end(), 0)) / ((double)prod2 / prod - 1);
    cout << (rep * prod2 / prod) << " " << rep;
    return 0;
}
