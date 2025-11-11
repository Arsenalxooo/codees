#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *front = NULL, *rear = NULL;

void insert(int value);
void deletenode();
void display();

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deletenode();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void insert(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if (front == NULL)
        front = rear = newnode;
    else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Inserted!\n");
}

void deletenode() {
    if (front == NULL)
        printf("Queue empty!\n");
    else {
        struct node* temp = front;
        printf("Deleted: %d\n", front->data);
        front = front->next;
        free(temp);
    }
}

void display() {
    if (front == NULL)
        printf("Queue empty!\n");
    else {
        struct node* temp = front;
        printf("Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

