#include <stdio.h>
#define MAX 4
int stack_arr[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    top++;
    stack_arr[top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate stack underflow
    }
    int x = stack_arr[top];
    top--;
    return x;
}

void traverse() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are: ");
    int i;
    for ( i = 0; i <= top; i++) {
        printf("%d ", stack_arr[i]);
    }
    printf("\n");
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    traverse();
     printf("Popped element: %d\n", pop());
    traverse();

    return 0;
}

