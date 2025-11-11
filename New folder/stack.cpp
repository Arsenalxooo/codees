#include <stdio.h>
#include <stdlib.h>
#define size 10

void push(int);
void pop();
void display();

int stack[size], top = -1;

int main() {
    int value, choice;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice!");
        }
    }
}

void push(int value) {
    if (top == size - 1)
        printf("Stack is full (overflow)");
    else {
        top++;
        stack[top] = value;
        printf("Insertion successful");
    }
}

void pop() {
    if (top == -1)
        printf("Stack is empty (underflow)");
    else {
        printf("Deleted item: %d", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1)
        printf("Stack is empty");
    else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
}

