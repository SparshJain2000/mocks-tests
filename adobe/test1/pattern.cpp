/*Keerthi, a receptionist of Hotel Benzz Park rearranges the chairs in the reception daily. Suresh, manager of the same hotel writes a program to display the arrangement on the reception TV screen. Today, Keerthi arranged the chairs as shown in the sample output(like Z shape). Help Suresh to write a program to display the arrangement pattern.



Note : Each chair has a number and there is more than one chair with the same number.



1 2 3 4 5 
      4
    3
  2
1 2 3 4 5 


Input format
Total number of chairs in first line

Output format
Display Z pattern as shown in sample output

Sample testcases
Input 1
5
Output 1
1 2 3 4 5 
      4
    3
  2
1 2 3 4 5 
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cout << i << " ";
    }
    cout << n << endl;
    int temp = n - 1;
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i; j <= n - 2; j++) {
            cout << "  ";
        }
        cout << temp << endl;
        temp--;
    }
    for (int i = 1; i < n; i++) {
        cout << i << " ";
    }
    cout << n;
}

//OR
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cout << i << " ";
    cout << '\n';
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j == n)
                cout << j;
            else
                cout << " ";
            cout << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) cout << i << " ";
}
