/*
Write a program to insert the element at the beginning of the list and remove duplicates from the sorted linked list.

Note:

The last element from the user should be the first element in the linked list.

Input format
The first line of input consists of elements to be inserted in the linked list.

Output format
The first line of output consists of the linked list after insertion.

The second line of output consists of the linked list after the removal of duplicate elements.

Code constraints
Only six integer inputs.

Sample testcases
Input 1
80 78 65 50 50 12
Output 1
12 50 50 65 78 80 
12 50 65 78 80 
Input 2
100 100 98 76 54 32
Output 2
32 54 76 98 100 100 
32 54 76 98 100 
*/
// You are using GCC
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
int main() {
    int a;
    struct Node* head = NULL;
    while (cin >> a) {
        Node* temp = new Node(a);
        if (!head)
            head = temp;
        else {
            temp->next = head;
            head = temp;
        }
    }
    Node* temp = head;
    while (temp) cout << temp->data << " ", temp = temp->next;
    cout << endl;
    temp = head;
    while (temp) {
        if (temp->next && temp->data == temp->next->data) temp->next = temp->next->next;
        cout << temp->data << " ";
        temp = temp->next;
    }
}