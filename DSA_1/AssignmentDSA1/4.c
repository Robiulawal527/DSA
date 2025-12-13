#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void printList(struct Node* head) {
    struct Node* tmp = head;
    while (tmp != NULL) {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

struct Node* createList(int n) {
    struct Node* head = NULL;
    struct Node* tmp = NULL;

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode; 
        } else {
            tmp->next = newNode; 
        }
        tmp = newNode; 
    }

    return head;
}

int main() {
    int n;

   
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    
    struct Node* head = createList(n);

    
    printf("Linked List: ");
    printList(head);

   
    struct Node* tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}