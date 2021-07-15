/*
Given two numbers 'x' and 'y', write a program to print number of digits needed to be flipped to convert 'x' to 'y'.

Input: 7 10

Output: 3

Explanation: Binary representation of 7 is 00000111 Binary representation of 10 is 00001010 We need to flip three bits in a to make it b.

Input format
Single line input consists of two space-separated integers.

Output format
Print an integer denoting the number of integers to be flipped.

Sample testcases
Input 1
7 10
Output 1
3
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    cout << __builtin_popcount(a ^ b);
}
