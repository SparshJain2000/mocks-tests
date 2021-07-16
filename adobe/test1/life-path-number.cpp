/*
Life path number is calculated as follows
Write a C program to get day, month and year and calculate the life path number.

Input format
Input should be in below foramt

Date-Month-Year

Output format
Life path number

Code constraints
1<=Date<=31

1<=Month<=12

1<=Year<=9999

Sample testcases
Input 1
29-11-2019
Output 1
7
Input 2
17-12-1986
Output 2
8
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int d = 0;
    int m = 0;
    int y = 0;
    int i = 0;
    int n = s.length();
    while (i < n && s[i] != '-') d = d + s[i++] - '0';
    i++;
    while (i < n && s[i] != '-') m = m + s[i++] - '0';
    i++;
    while (i < n) y = y + s[i++] - '0';
    int sum = d + m + y;
    while (sum > 10) {
        int ans = 0;
        while (sum) ans += sum % 10, sum /= 10;
        sum = ans;
    }
    cout << sum;
}
