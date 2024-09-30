#include <stdio.h>

#define MAX_SIZE 50

int front = -1, rear = -1;
int Queue[MAX_SIZE];


void Enqueue(int item,int size) {
    if ((rear + 1) % size == front) {
        printf("Queue is full\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % size;
    }
    Queue[rear] = item;
    printf("Element successfully added to Queue\n");
}


void Dequeue(int size) {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
        return;
    } else if (front == rear) {
        printf("Dequeued element: %d\n", Queue[front]);
        front = -1;
        rear = -1;
    } else {
        printf("Dequeued element: %d\n", Queue[front]);
        front = (front + 1) % size;
    }
}


void display(int size) {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
        return;
    }
    int i = front;
    do {
        printf("%d, ", Queue[i]);
        i = (i + 1) % size;
    } while (i != rear);
    printf("%d\n", Queue[rear]);
}

int main() {
    int choice;
    int size;
    printf("Enter the maximum size of the Queue (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Maximum size cannot be greater than %d\n", MAX_SIZE);
        return 1;
    }

    printf("Menu:\n");
    printf("1.Insert an element \n");
    printf("2.Delete an element \n");
    printf("3.Display the elements\n");
    printf("4.Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int item;
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                Enqueue(item,size);
                break;
            }
            case 2: {
                Dequeue(size);
                break;
            }
            case 3: {
                display(size);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }

    return 0;
}
