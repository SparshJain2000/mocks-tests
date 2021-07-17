/*
A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1,2,3,4,5] , then the array would become [3,4,5,1,2]. Given an array of n integers and a number d , 

Input format
The first line of the input consists of the value of n.

Next input is the array elements.

The last input is the d value.

Output format
The output prints the new array.

Sample testcases
Input 1
5
1 2 3 4 5
2
Output 1
3 4 5 1 2 
*/
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    reverse(v.begin(), v.begin() + k);
    reverse(v.begin() + k, v.end());
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) cout << v[i] << " ";
}
