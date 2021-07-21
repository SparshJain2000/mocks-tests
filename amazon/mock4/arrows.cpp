/*
There are X balloons drifting in the air in a spacious room, ordered up from left to right. Jessica likes to play with arrows and prepare his hunting skills. He launches an arrow from the left to the right side of the room from a random peak (height) he prefers. The arrow goes from left to right, at a preferred peak P until it detects a balloon. When an arrow hits a balloon, the balloon blows and fades, and the arrow maintains its way from left to right at a peak reduced by 1. Thus, if the arrow was going at peak P, after blowing the balloon it goes on peak P−1.



Jessica’s target is to blow all the balloons using as little arrows as possible.

Input format
The first line of input contains the integer X. The second line of input contains an array of X integers Pi. Each integer Pi is the peak at which the ith balloon floats, respectively from left to right.

Output format
Display the minimal number of times Jessica needs to shoot an arrow so that all balloons are blown.

Code constraints
1≤X≤106
1≤Pi≤106
Sample testcases
Input 1
5
2 1 5 4 3
Output 1
2
Input 2
5
1 2 3 4 5
Output 2
5
Input 3
5
4 5 2 1 4
Output 3
3
*/
// You are using GCC
#include <bits/stdc++.h>

#include <tr1/unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    tr1::unordered_map<int, vector<int> > m;
    for (int i = 0; i < n; i++) cin >> v[i], m[v[i]].push_back(i);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        // cout<<m[v[i]].size()<<endl;
        if (m[v[i]].size() > 0 && find(m[v[i]].begin(), m[v[i]].end(), i) != m[v[i]].end()) {
            int p = v[i];
            int temp = i;
            while (p && m.find(p - 1) != m.end() && m[p - 1].size() > 0) {
                vector<int> vec = m[p - 1];
                for (int j = 0; j < m[p - 1].size(); j++) {
                    if (m[p - 1][j] > temp) {
                        temp = m[p - 1][j];
                        m[p - 1].erase(m[p - 1].begin() + j);
                        break;
                    }
                }
                p--;
            }
            ans++;
        }
    }
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m[v[i]].size();j++) cout<<v[i]<<" "<<m[v[i]][j]<<" ";
    //     cout<<endl;
    // }
    cout << ans;
}

// You are using GCC
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[i] = {x, i};
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second != -1) {
            int p = v[i].first;

            for (int j = i + 1; j < n; j++) {
                if (v[j].first == p - 1 && v[j].second != -1) p--, v[j].second = -1;
            }
            v[i].second = -1;
            ans++;
        }
    }

    cout << ans;
}