#include <stdio.h>

void rightanglewithnumber(int n);
void pyramidwithstar(int n);
void pyramidwithalphabet(int n);
void diamondwithnumber(int n);

int main() {
    int n;
    printf("Enter rows: ");
    scanf("%d", &n);
    rightanglewithnumber(n);
    pyramidwithstar(n);
    pyramidwithalphabet(n);
    diamondwithnumber(n);
}

void rightanglewithnumber(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("%d", i);
        printf("\n");
    }
}

void pyramidwithstar(int n) {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
}

void pyramidwithalphabet(int n) {
    char ch = 'A';
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= i; j++)
            printf("%c", ch++);
        ch = 'A';
        printf("\n");
    }
}

void diamondwithnumber(int n) {
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%d", i);
        printf("\n");
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int s = 1; s <= n - i; s++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%d", i);
        printf("\n");
    }
}

