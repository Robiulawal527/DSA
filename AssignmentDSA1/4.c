#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
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

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to create a linked list with user input
struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode; // Set the first node as the head
        } else {
            temp->next = newNode; // Link the previous node to the new node
        }
        temp = newNode; // Move temp to the new node
    }

    return head;
}

int main() {
    int n;

    // Ask the user for the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Create the linked list
    struct Node* head = createList(n);

    // Print the linked list
    printf("Linked List: ");
    printList(head);

    // Free the allocated memory
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}