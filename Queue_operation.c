#include <stdio.h>

#define MAX_SIZE 50

int front = -1, rear = -1, top = -1;
int Queue[MAX_SIZE] ;

void Enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    Queue[rear] = item;
    printf("Element successfully added to Queue\n");
}

void dequeue() {
    int item;
    if ((front == -1 && rear == -1)||(front < 0||front > rear) ){
        printf("Queue is Empty");
        return;
    } else {
        item = Queue[front];
        front++;
        return;
    }
}

void peek() {
    if (rear == -1 && front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("The element at the top of the Queue is %d\n", Queue[rear]);
}

void isFull(int size) {
    if (rear == size - 1) {
        printf("The Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
}

void isEmpty() {
    if ((front == -1 && rear == -1)||(front < 0||front > rear)) {
        printf("The Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}
void display(){
	int i =front;
	if((front == -1 &&rear == -1)||(front < 0|| rear <front)){
		printf("Queue is Empty");
		return;
	}
	
	for(;i <= rear;i++){
		printf("%d,",Queue[i]);
	}
	}

int main() {
    int size,choice;
    printf("Enter the maximum size of the Queue: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Maximum size cannot be greater than %d\n", MAX_SIZE);
        return 1;
    }
    printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Check if Queue is full\n");
        printf("5. Check if Queue is empty\n");
        printf("6. display\n");
        printf("7. exit\n");
        
    while (1) {
    	printf("Enter your choice: ");
        scanf("%d", &choice);
       

        switch (choice) {
            case 1: {
                int item;
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                Enqueue(item);
                break;
            }
            case 2: { dequeue();
                	break;
            }
            case 3: { peek();
                	break;
            }
            case 4: { isFull(size);
                	break;
            }
            case 5: { isEmpty();
	                break;
            }
            case 6: {printf("\n");
            		display();
            		break;
	    }
	    case 7:{	return 0;
	    		break;	
	    }
            default: { printf("Invalid choice\n");
	                break;
            }
        }
    }

    return 0;
}
