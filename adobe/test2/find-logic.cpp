/*
Find the logic behind the given series



Series:

6 28 66 120 190 276....



The numbers in the series should be used to create a Pyramid. The base of the Pyramid will be the widest and will start converging towards the top where there will only be one element. Each successive layer will have one number less than that on the layer below it. The width of the Pyramid is specified by an input parameter N., In other words, there will be N numbers on the bottom layer of the pyramid.



The Pyramid construction rules are as follows

1.  The first number in the series should be at the top of the Pyramid

2.  Last N number of the series should be on the bottom-most layer of the Pyramid, with the Nth number being the right-most number of this layer.

3.  Numbers less than 5-digits must be padded with zeroes to maintain the sanctity of a Pyramid when printed. Have a look at the examples below to get a pictorial understanding of what this rule actually means.



Note : Use printf("%10.5d",variable_name);

Input format
The first line of input will contain number N that corresponds to the width of the bottom-most layer of the Pyramid 

Output format
The Pyramid constructed out of numbers in the series as per stated construction rules (Each output is separated by 5 spaces)

Code constraints
0 < N <= 14

Sample testcases
Input 1
3
Output 1
     00006
     00028     00066
     00120     00190     00276
*/

// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int i = 6;
    int d = 22;

    for (int j = 0; j < n; j++) {
        for (int k = 0; k <= j; k++) {
            printf("%10.5d", i);
            i += d;
            d += 16;
        }
        cout << '\n';
    }
}
