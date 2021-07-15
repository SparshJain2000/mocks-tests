/*
Regina likes prefix and suffix sums, so Rakesh decided to give some to her as her birthday present. He created a sequence a1,a2,…,aN and calculated its prefix sums pre1,pre2,…,preN (for each valid i, prei is the sum of the first i elements of a) and suffix sums suf1,suf2,…,sufN (for each valid i, sufi is the sum of the last i elements of a). He arranged the elements of these sequences in a gift box and went to Regina's home.

When Regina opened the gift box, she found out that all the elements got shuffled when Rakesh was carrying the box. For each element, it is now impossible to determine if it belonged to the sequence pre or suf and what its index in the correct sequence was. The only thing we know is a sequence x1,x2,…,x2N, which contains all the elements of the sequences pre and suf, in no particular order.

Regina is now curious about the number of initial sequences a which Rakesh could have chosen, such that it is possible to obtain x by shuffling the prefix and suffix sums of a. Help Regina find this number. Since it could be very large, compute it modulo 1,000,000,007.

Input format
The first line of input contains a single integer N.

The second line contains 2N space-separated integers x1,x2,…,x2N .

Output format
 Print a single line containing one integer representing the number of possible initial sequences modulo 1,000,000,007 .

Code constraints
1 ≤ N ≤105

|xi| ≤109 for each valid i

The sum of N over all test cases does not exceed 2⋅106

Sample testcases
Input 1
3
5 3 7 10 5 10
Output 1
4
*/
// 4/5 testcase passing
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        int x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    if (v.back() != v[2 * n - 2]) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < 2 * n - 2; i++) {
        if (v[i] + v[2 * n - i - 3] != v.back()) {
            cout << 0;
            return 0;
        }
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        ans = ans * (i - 1);
        if (i & 1) ans *= 2;
    }
    cout << ans;
}
