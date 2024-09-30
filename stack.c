#include <stdio.h>

#define MAX_SIZE 100

int top = -1;
int stack[MAX_SIZE];

void push(int item) {
    if (top == MAX_SIZE-1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = item;
    printf("Element successfully added to stack\n");
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return 0;
    }
    int item = stack[top];
    top--;
    printf("Element successfully removed from the stack is %d\n", item);
    return item;
}

void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("The element at the top of the stack is %d\n", stack[top]);
}

void isFull(int size) {
    if (top == size - 1) {
        printf("The stack is full\n");
    } else {
        printf("Stack is not full\n");
    }
}

void isEmpty() {
    if (top == -1) {
        printf("The stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

int main() {
    int size;
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &size);

    if(size > MAX_SIZE) {
        printf("Maximum size cannot be greater than %d\n", MAX_SIZE);
        return 1;
    }

    while (1) {
        printf("Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if stack is full\n");
        printf("5. Check if stack is empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int item;
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            }
            case 2: {
               		 pop();
                	break;
            }
            case 3: {
                	peek();
                	break;
            }
            case 4: {
                	isFull(size);
                	break;
            }
            case 5: {
                	isEmpty();
                	break;
            }
            case 6: {
                return 0;
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
        if(choice == 'x' || choice == 'X'){
        	printf("Error.......");
        	break;
        }
    }

    return 0;
}

