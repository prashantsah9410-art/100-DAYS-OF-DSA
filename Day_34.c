// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
// - Print the integer result

// Example:
// Input:
// 2 3 1 * + 9 -

// Output:
// -4

// Explanation:
// Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Top pointer
struct Node* top = NULL;

// Push operation
void push(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

// Pop operation
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

// Evaluate postfix
int evaluatePostfix(char* exp) {
    int i = 0;

    while (exp[i] != '\0') {

        // If operand (digit)
        if (isdigit(exp[i])) {
            int num = 0;

            // Handle multi-digit numbers
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
            i--; // adjust index
        }

        // If operator
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int val2 = pop();
            int val1 = pop();

            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }

        i++;
    }

    return pop();
}

// Main function
int main() {
    char exp[] = "2 3 1 * + 9 -";

    int result = evaluatePostfix(exp);

    printf("Result = %d\n", result);

    return 0;
}