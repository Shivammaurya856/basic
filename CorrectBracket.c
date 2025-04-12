#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // Define maximum stack size

typedef struct {
    char items[MAX];
    int top;
} Stack;

// Initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// Check if the stack is empty
int isEmpty(Stack* s) {
    return s->top == -1;
}

// Push an item to the stack
void push(Stack* s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop an item from the stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->items[s->top--];
}

// Check if characters are matching pairs
int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

// Function to check if brackets are balanced
int areBracketsBalanced(const char* expression) {
    Stack s;
    initStack(&s);
     int i;
    for ( i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        // If the character is an opening bracket, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        }
        // If it's a closing bracket, check for matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (isEmpty(&s)) {
                return 0;  // Unmatched closing bracket
            }
            char top = pop(&s);
            if (!isMatchingPair(top, ch)) {
                return 0;  // Mismatched brackets
            }
        }
    }

    // If the stack is empty, brackets are balanced
    return isEmpty(&s);
}

int main() {
    char expression[MAX];

    printf("Enter an expression with brackets: ");
    scanf("%s", expression);

    if (areBracketsBalanced(expression)) {
        printf("The brackets are balanced and correctly ordered.\n");
    } else {
        printf("The brackets are not balanced or are incorrectly ordered.\n");
    }

    return 0;
}

