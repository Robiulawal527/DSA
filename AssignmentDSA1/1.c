#include <stdio.h>
#include <stdlib.h> 
struct Node  {
    int data;
    struct  Node *next;
};
typedef struct Node node;

void menu();  

node* insert_head(node *head, int v);
void printList(node *head);
node* insert_tail(node *head, int v);
node* insert_nth(node *head, int v, int n);
int getListSize(node *head);
node* delete_head(node *head);
node* delete_tail(node *head);
node* delete_nth(node *head, int n);
node* customOrder(node *head);

int main() {
    int ch, n, i, v, pos;
    node *head = NULL;

    while (1) {
        menu();
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter  data: ");
            scanf("%d", &v);
            head = insert_head(head, v);
        } else if (ch == 2) {
            printf("Enter  data: ");
            scanf("%d", &v);
            head = insert_tail(head, v);
        } else if (ch == 3) {
            printf("Enter  position: ");
            scanf("%d", &pos);
            if (pos >= 1 && pos <= getListSize(head) + 1) {
                printf("Enter  data: ");
                scanf("%d", &v);
                head = insert_nth(head, v, pos);
            } else {
                printf("Invalid  position.\n\n");
            }
        } else if (ch == 4) {
            if (head == NULL) {
                printf("List is empty. Nothing  to delete.\n\n");
            } else {
                printf("%d deleted.\n\n", head->data);
                head = delete_head(head);
            }
        } else if (ch == 5) {
            if (head == NULL) {
                printf("List is empty. Nothing to delete.\n\n");
            } else {
                head = delete_tail(head);
            }
        } else if (ch == 6) {
            if (head == NULL) {
                printf("List is empty. Nothing to delete.\n\n");
            } else {
                printf("Enter position: ");
                scanf("%d", &pos);
                if (pos >= 1 && pos <= getListSize(head)) {
                    head = delete_nth(head, pos);
                } else {
                    printf("Invalid position.\n\n");
                }
            }
        } else if (ch == 7) {
            printList(head);
        } else if (ch == 8) {
            printf("List size: %d\n\n", getListSize(head));
        } else if (ch == 9) {
            head = customOrder(head);
            printf("List reordered based on frequency.\n");
        } else if (ch == 0) {
            break;
        } else {
            printf("Invalid input. Please try again!!!\n\n");
        }
    }
}

void menu() {
    printf("1. Insert (head)\n");
    printf("2. Insert (tail)\n");
    printf("3. Insert (nth)\n");
    printf("4. Delete (head)\n");
    printf("5. Delete (tail)\n");
    printf("6. Delete (nth)\n");
    printf("7. Print list\n");
    printf("8. Print list size\n");
    printf("9. Reorder list by frequency\n");
    printf("0. Exit\n\n");
    printf("Enter choice: ");
}

node* createNode(int v) {
    node *nn =  (node*)malloc(sizeof(node)); 
    nn->data = v;
    nn->next =  NULL;
    return  nn;
}

node* insert_head(node *head, int v) {
    node *nn = createNode(v);
    nn->next = head;
    head = nn;
    return head;
}

void printList(node *head) {
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}

int getListSize(node *head) {
    node *temp = head;
    int lSize = 0;
    while (temp != NULL) {
        lSize++;
        temp = temp->next;
    }
    return lSize;
}

node* insert_tail(node *head, int v) {
    if (head == NULL) {
        return insert_head(head, v);
    }
    node *temp = head;
    node *nn = createNode(v);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = nn;
    return head;
}

node* insert_nth(node *head, int v, int n) {
    if (n == 1) {
        return insert_head(head, v);
    } else if (n == getListSize(head) + 1) {
        return insert_tail(head, v);
    } else {
        node *temp = head;
        node *nn = createNode(v);
        for (int i = 1; i <= n - 2; i++) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
        return head;
    }
}

node* delete_head(node *head) {
    if (head == NULL) return NULL;
    node *del = head;
    head =  head->next;
    free(del); 
    return head;
}

node*  delete_tail(node *head) {
    if (head == NULL) return NULL;
    if (getListSize(head) == 1) {
        return  delete_head(head);
    }
    node *temp = head;
    while (temp->next->next != NULL) {
        temp =  temp->next;
    }
    free(temp->next); 
    temp->next = NULL;
    return  head;
}

node* delete_nth(node *head, int n) {
    if (n == 1) {
        return delete_head(head);
    } else if (n == getListSize(head)) {
        return delete_tail(head);
    } else {
        node *temp = head;
        for (int i = 1; i <= n - 2; i++) {
            temp = temp->next;
        }
        node *del = temp->next;
        temp->next = del->next;
        free(del); 
        return head;
    }
}

node* customOrder(node *head) {
    if (head == NULL) return NULL;

    int freq[101] = {0};          
    int uniq[1000], uCount = 0;  
    int isSeen[101] = {0};

    node *temp = head;

   
    while (temp != NULL) {
        int val = temp->data;
        freq[val]++;

        if (!isSeen[val]) {
            uniq[uCount++] = val;
            isSeen[val] = 1;
        }
        temp = temp->next;
    }

 
    for (int i = 0; i < uCount - 1; i++) {
        for (int j = i + 1; j < uCount; j++) {
            if (freq[uniq[i]] < freq[uniq[j]]) {
                int tempVal = uniq[i];
                uniq[i] = uniq[j];
                uniq[j] =  tempVal;
            }
        }
    }

  
    node *newHead = NULL;
    for (int i = 0; i < uCount; i++) {
        int value = uniq[i];
        for (int j = 0; j < freq[value]; j++) {
            newHead =  insert_tail(newHead, value);
        }
    }

    return newHead;
}