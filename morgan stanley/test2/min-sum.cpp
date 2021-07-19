/*
Sulekha loves playing with words. She has the habit of finding various combinations of letters and numbers that can be formed on seeing a word. During on of these times, she tried finding out the value of a particular word after removing some letters in it. And then she improvised it by finding the sum of squares of the frequency of each letter in the word. She then ended up finding the minimum of the above found sum values after removing some letters.



Once, she mentioned about this amazing discovery to one of her geek friend with an example.

Word: happiness

Characters to be removed: 3

Frequency of each letter: h=1, a=1, p=2, i=1, n=1, e=1, s=2

Minimum sum: 6

Explanation: 3 characters have to be removed. Following are the possibilities

It can be either (2 s and 1 p) or (1 s and 2 p) or (1 s, 1 p and 1 other character) which would reduce the frequency of every word to 1.
Hence 1^2+1^2+1^2+1^2+1^2+1^2 = 6
He was so fascinated upon hearing this problem and decided to solve it using queue concept in programming with a time complexity of O(n).

Input format
Single line input that consists of a word and an integer representing the number of character to be removed.

Output format
Output displays the minimum sum of squares of the frequency of each letter after removing a certain number of characters.

Sample testcases
Input 1
happiness 3
Output 1
6
*/
// You are using GCC
//3/5 passing
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int n;
    cin >> s >> n;
    int arr[27] = {0};
    for (int i = 0; i < s.length(); i++) arr[s[i] - 'a']++;
    // for(int i=0;i<26;i++) cout<<arr[i]<<" ";
    // cout<<distance(arr,max_element(arr,arr+26))<<" ";
    while (n) {
        int x = max_element(arr, arr + 26) - arr;
        // cout<<x<<" ";
        if (arr[x] == 0) break;
        if (arr[x] == 1) arr[x] = 0, n--;
        if (n > arr[x])
            n -= (arr[x] - 1), arr[x] = 1;
        else
            arr[x] -= n, n = 0;
    }
    int sum = 0;
    for (int i = 0; i < 26; i++) sum += arr[i] * arr[i];
    cout << sum;
}