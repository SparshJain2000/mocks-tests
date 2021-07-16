/*
Robert is given a string that ends with a character or a number. He has to check the length of the given string and append it to the end in such a way that if the original string ends with a number then the new string with the appended value must have length of the string as the last two characters. If the string ends with a character then append the total length as the last character.

Also, the number to be appended must be a single positive digit. Write a code to implement the given scenario.

Input format
Input consist of a string

Output format
Output displays the single digit value to be appended. If the value is more than one digit or no digit is to be appended, then print -1.

Sample testcases
Input 1
abcdefghijklmnop1
Output 1
6
*/
// You are using GCC
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    if (isdigit(s[n - 1])) {
        if (n - 1 >= 100)
            ans = -1;
        else if (n - 1 < 10)
            ans = -1;
        else
            ans = (n - 1) % 10;
    } else {
        if (n >= 10)
            ans = -1;
        else
            ans = n;
    }
    cout << ans;
}
