#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};




// Function prototypes

void menu();


int main()
{
    menu();

    return 0; 
}

void menu()
{
    int choice;

    while(1)
    {
        printf("Menu: \n");
        printf("0. Exit \n");
        printf("1. makeList \n");
        printf("2. printList \n");
        printf("3. insertNode \n");
        printf("4. deleteNode \n");
        printf("5. sortList \n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0: 
                return;
            
        }
    }
}


//Function to create new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

//Function to create linked list with user input 

struct Node* createList(int n) {

    struct Node* head = NULL;
    struct Node* temp = NULL;


    for (int i=0; i<n; i++)
    {
        int value; 
        printf("Enter value for node %d: ",i +1  );

        
    }
}

