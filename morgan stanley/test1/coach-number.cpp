/*
A train from Delhi to Bangalore is standing on platform number 2 for half an hour. Passengers to the train receive a message from the train authorities that the coach numbers have been changed and are now allocated some random numbers. Also, from that day onward all trains have such kind of arrangement irrespective of the number of coaches. It is also said that the order to the the coaches will be printed on the board near the engine coach.



Given a specific coach number, every passenger has to enter into the first first coach after the engine and move forward until his/her respective coach is reached. If the train does not have the respective coach number, then the passenger must get out of the last coach.

Input format
First line has the number of coaches in the train. Second line has the coach numbers in order separated by a space. Third line has the coach number to be found.

Output format
Output displays the coach number along with a Yes or No answer as shown in sample test cases

Sample testcases
Input 1
10
1 23 5 12 8 7984 1 654 46 51 
21
Output 1
21: No
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];
    int x;
    cin >> x;

    for (int i = 0; i < n; i++)
        if (v[i] == x) {
            cout << x << ": "
                 << "Yes";
            return 0;
        }
    cout << x << ": "
         << "No";
}