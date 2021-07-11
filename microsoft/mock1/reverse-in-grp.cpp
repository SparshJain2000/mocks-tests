/*
Write a C program to reverse every k node in the given linked list.


Input format
Single line input consists of two integers denoting the array size N and K value respectively. It is followed by space-separated list elements in the same line.

Output format
Print the list after reversing the k elements.

Code constraints
Integers only.

Sample testcases
Input 1
 9 3 1 2 3 4 5 6 7 8 9
Output 1
7 8 9 4 5 6 1 2 3 
*/

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
Node* reverse(Node* head, int k) {
    Node* ptr = head;
    Node* pre = NULL;
    while (k-- && ptr) {
        Node* temp = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = temp;
    }
    head->next = ptr;
    head = pre;
    return head;
}
int main() {
    int n, k;
    cin >> n >> k;
    Node* head = NULL;
    Node* curr = head;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* temp = new Node(x);
        if (head)

            curr->next = temp;
        else
            head = temp;
        curr = temp;
    }
    head = reverse(head, n);
    Node* temp = head;
    Node *t1, *t2 = NULL;
    int i = 0;

    while (temp) {
        t1 = temp;
        temp = reverse(temp, k);
        if (t2)
            t2->next = temp;
        else
            head = temp;

        temp = t1->next;
        t2 = t1;
        i += k;
    }
    while (head) cout << head->data << " ", head = head->next;
    return 0;
}