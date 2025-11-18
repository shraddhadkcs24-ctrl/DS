#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

char peek() {
    return stack[top];
}

int precedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default:  return 0;
    }
}

// Check if operator is left associative
int isLeftAssociative(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

int isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If operand, add to output
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push to stack
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // If operator
        else if (isOperator(c)) {
            while (top != -1 &&
                (precedence(peek()) > precedence(c) ||
                (precedence(peek()) == precedence(c) && isLeftAssociative(c))) &&
                peek() != '(') {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
