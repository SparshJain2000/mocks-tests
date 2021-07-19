/*
Write a program to insert elements in the stack and display the topmost element.

Input format
Number of stack elements in first line

Stack elements in second line separated by space

Output format
Topmost element in the stack

Sample testcases
Input 1
5
3 9 4 7 6
Output 1
6
*/
#include <stdio.h>
#include <stdlib.h>
int *stack = (int *)malloc(sizeof(int) * 100);
int top = -1;
void push(int *stack, int val);
int peek(int *stack);
int main() {
    int val, n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(stack, val);
    }

    val = peek(stack);
    if (val != -1)
        printf("%d", val);
}
int peek(int *stack) {
    return stack[top];
}
void push(int *stack, int val) {
    if (top == 100 - 1) {
        printf("STACK OVERFLOW");
    } else {
        top++;
        *(stack + top) = val;
    }
}