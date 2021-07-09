/*
Amazon Media Encoder is a highly scalable, easy to use and cost-effective way for developers and businesses to convert media files from their source format Into versions that will playback on devices like smartphones. Whenever a media file needs to be processed by the encoder it partitions the media file into N sub files. Each sub-file is processed independently. During this process each sub file gets compressed These compressed sub-files are their merged by the encoder.

The encoder can merge only two files at a time. The time required to merge the two file is equal to the sum of their sizes. The size of this merged file is also equal to the sum of their sizes. The process is repeated until the N sub files are merged into a single output file.

Write an algorithm to output the minimum possible time to merge the given N sub files into a single file.

* Input format
The input to the function/mentioned consists of one argument- file sizes a list of integers representing the size of the compressed sub files

* Output format
Return an integer representing the minimum time required to merge all the sub-file

* Code constraints

1 <= number of sub-files <= 10^6
1 <= file sizes[i] <= 10^6 
0 <= i < number of sub files

* Sample testcases
Input 1
4
4 8 6 12
Output 1
58

*/
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