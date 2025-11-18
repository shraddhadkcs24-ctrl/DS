#include <stdio.h>

#define MAX 100

typedef struct {
    char arr[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}


int isFull(Stack *s) {
    return s->top == MAX - 1;
}


void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %c\n", item);
        return;
    }
    s->arr[++s->top] = item;
}


char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop.\n");
        return '\0';
    }
    return s->arr[s->top--];
}


char top(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty! No top element.\n");
        return '\0';
    }
    return s->arr[s->top];
}


char seek(Stack *s) {
    return top(s);
}


int main() {
    Stack s;
    initStack(&s);

    push(&s, 'A');
    push(&s, 'B');
    push(&s, 'C');

    printf("Top element: %c\n", top(&s));

    printf("Popped: %c\n", pop(&s));
    printf("Top after pop: %c\n", top(&s));

    return 0;
}
