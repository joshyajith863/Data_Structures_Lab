#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the front of the list
void insertFront(struct Node** head_ref, int data, int* size) {
    struct Node* newNode = createNode(data);
    newNode->next = *head_ref;
    *head_ref = newNode;
    (*size)++; // Increment the size
    printf("%d has been inserted at the front.\n", data);
}

// Insert at the rear (end) of the list
void insertRear(struct Node** head_ref, int data, int* size) {
    struct Node* newNode = createNode(data);
    struct Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        (*size)++; // Increment the size
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    (*size)++; // Increment the size
    printf("%d has been inserted at the rear.\n", data);
}

// Insert at a specific position
void insertAtPosition(struct Node** head_ref, int data, int position, int* size) {
    if (position < 1 || position > *size + 1) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* temp = *head_ref;

    if (position == 1) {
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("%d has been inserted at position %d.\n", data, position);
    }

    (*size)++; // Increment the size
}

// Delete from the front of the list
void deleteFront(struct Node** head_ref, int* size) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
    (*size)--; // Decrement the size
    printf("Front node deleted.\n");
}

// Delete from the rear (end) of the list
void deleteRear(struct Node** head_ref, int* size) {
    if (*head_ref == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If there's only one node
    if (temp->next == NULL) {
        *head_ref = NULL;
        free(temp);
        (*size)--; // Decrement the size
        return;
    }

    // Traverse to the second-to-last node
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    (*size)--; // Decrement the size
    printf("Rear node deleted.\n");
}

// Delete from a specific position
void deleteAtPosition(struct Node** head_ref, int position, int* size) {
    if (*head_ref == NULL || position < 1 || position > *size) {
        printf("Position out of bounds or list is empty.\n");
        return;
    }

    struct Node* temp = *head_ref;

    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
    } else {
        struct Node* prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        free(temp);
    }

    (*size)--; // Decrement the size
    printf("Node at position %d deleted.\n", position);
}

// Function to display the linked list and index each node
void displayList(struct Node* node, int size) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }

    int index = 1;
    while (node != NULL) {
        printf("Index %d: %d -> ", index, node->data);
        node = node->next;
        index++;
    }
    printf("NULL\n");
    printf("Size of the list: %d\n", size);
}

int main() {
    struct Node* head = NULL;
    int size = 0;  // Variable to keep track of the size of the linked list
    int choice, value, position;

    while (1) {
        // Menu options for the user
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Front\n");
        printf("5. Delete from Rear\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display the Linked List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Insert at the front
                printf("Enter the value to insert at front: ");
                scanf("%d", &value);
                insertFront(&head, value, &size);
                displayList(head,size);
                break;

            case 2:
                // Insert at the rear
                printf("Enter the value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&head, value, &size);
                displayList(head,size);
                break;

            case 3:
                // Insert at a specific position
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position, &size);
                displayList(head,size);
                break;

            case 4:
                // Delete from the front
                deleteFront(&head, &size);
                displayList(head,size);
                break;
                
            case 5:
                // Delete from the rear
                deleteRear(&head, &size);
                displayList(head,size);
                break;

            case 6:
                // Delete from a specific position
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position, &size);
                displayList(head,size);
                break;

            case 7:
                // Display the linked list
                printf("Current Linked List: ");
                displayList(head, size);
                break;

            case 8:
                // Exit the program
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }

    return 0;
}
