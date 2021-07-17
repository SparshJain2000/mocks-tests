/*

Nisha is learning to count the number of letters in a word. In order to improve, her mother gave a sentence each day and Nisha has to arrange them in ascending order based upon the number of letters in each word.

Input format
First line has the total number of words in the sentence. Second line has the sentence.

Output format
Output displays the words in the sentence in the ascending order of the number of letters in each word separated by space

Sample testcases
Input 1
4
what are you doing
Output 1
are you what doing 
*/

// You are using GCC

#include <bits/stdc++.h>
using namespace std;
//lambda not working on site😑
bool comparator(string a, string b) {
    return a.length() < b.length();
}
int main() {
    int n;
    vector<string> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), comparator);
    for (int i = 0; i < n; i++) cout << v[i] << " ";
}
