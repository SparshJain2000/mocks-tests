/*

Keerthy encountered a binary tree traversal based problem while participating in one of the national level contest,. As tree concept is one of his weak links, she was unable to think of any solution for the problem and has become sad.

Can you help Keerthy and make him happy by writing a program to create a binary search tree and print the top view of a binary tree.
Note : Top view means when you look the tree from the top the nodes you will see will be called the top view of the tree.(8, 4, 2, 1, 3, 7 is the top view of the given binary tree)

Input format
Number of elements in first line(N)

N Tree elements in second line separted by space

Output format
Display the top view.



Refer sample input and output.

Sample testcases
Input 1
9
21 10 32 6 3 15 25 45 34
Output 1
3 6 10 21 32 45 
*/

// Working locallly, Not compiling on site 😑
// You are using GCC
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void top(Node* root, int level, map<int, int>& m) {
    if (!root) return;
    if (m.find(level) == m.end()) m[level] = root->data;
    top(root->right, level + 1, m);
    top(root->left, level - 1, m);
}
Node* insert(Node* root, int data) {
    Node* temp = new Node(data);
    if (!root) return root = temp;
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data >= root->data)
        root->right = insert(root->right, data);
    return root;
}
int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    map<int, int> m;
    top(root, 0, m);

    for (pair<int, int> p : m) {
        cout << p.second << " ";
    }
}
