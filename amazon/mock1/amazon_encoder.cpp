#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> p;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        p.push(temp);
    }
    int ans = 0;
    while (p.size() != 1) {
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        ans += a + b;
        p.push(a + b);
    }
    cout << ans;
    return 0;
}