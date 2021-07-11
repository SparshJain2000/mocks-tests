/*
Write a program to find the Run Length Encoded string for the input string.

Input format
The single line input contains a string.

Output format
You need to print the Run Length Encoded string.

Code constraints
Strings only.

Sample testcases

Input 1
PlacementSeason

Output 1
P1l1a1c1e1m1e1n1t1s1e1a1s1o1n1
*/
#include <bits/stdc++.h>

#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int i = 0;
    string ans = "";

    while (i < s.length()) {
        int temp = 1;
        while (i + 1 < s.length() && s[i] == s[i + 1]) {
            i++, temp++;
        }
        ans += s[i];
        ans += (temp + '0');
        i++;
    }
    cout << ans;
    return 0;
}