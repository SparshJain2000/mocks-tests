/*
Write a program to construct BST from a given pre-order traversal.

Input format
The first input is the n value.

Next input is the pre-order traversal of the given tree.

Output format
The output prints the In-order traversal of the constructed tree.

Sample testcases
Input 1
6
10 5 1 7 40 50
Output 1
Inorder traversal of the constructed tree: 
1 5 7 10 40 50 
Input 2
8
20 12 14 35 46 66 25 30
Output 2
Inorder traversal of the constructed tree: 
12 14 20 35 46 25 30 66 
*/
// You are using GCC
//4/5 passing
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
Node* insert(Node* root, int data) {
    Node* temp = new Node(data);
    if (!root) {
        root = temp;
        return root;
    }
    if (root->data >= data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    cout << "Inorder traversal of the constructed tree: " << endl;
    inorder(root);
}