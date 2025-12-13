
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
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


node* seperateOddEven(node *head, int direction);

int main()
{
    int ch, n, i, v, pos;
    node *head = NULL;



    while(1)
    {
        menu();
        scanf("%d",&ch);

        if(ch == 1)
        {
            printf("enter data: ");
            scanf("%d",&v);
            head = insert_head(head, v);
        }
        else if(ch == 2)
        {
            printf("enter data: ");
            scanf("%d",&v);
            head = insert_tail(head, v);
        }
        else if(ch == 3)
        {
            printf("enter position: ");
            scanf("%d",&pos);
            if(pos >= 1 && pos <= getListSize(head)+1)
            {
                printf("enter data: ");
                scanf("%d",&v);
                head = insert_nth(head, v, pos);
            }
            else
            {
                printf("invalid position.\n\n");
            }
        }
        else if(ch == 4)
        {
            node *del;
            if(head == NULL)
            {
                printf("list is empty. nothing to delete.\n\n");
            }
            else
            {
                printf("%d deleted.\n\n", head->data);
                head = delete_head(head);
            }
        }
        else if(ch == 5)
        {
            if(head == NULL)
            {
                printf("list is empty. nothing to delete.\n\n");
            }

            else
            {
                head = delete_tail(head);
            }
        }
        else if(ch == 6)
        {
            if(head == NULL)
            {
                printf("list is empty. nothing to delete.\n\n");
            }
            else
            {
                printf("enter position: ");
                scanf("%d",&pos);
                if(pos >= 1 && pos <= getListSize(head))
                {
                    head = delete_nth(head, pos);
                }
                else
                {
                    printf("invalid position.\n\n");
                }
            }
        }
        else if(ch == 7)
        {
            printList(head);
        }
        else if(ch == 8)
        {
            printf("List size: %d\n\n",getListSize(head));
        }
        else if(ch == 0)
        {
            break;
        }
        else
        {
            printf("Invalid input. Please try again!!!\n\n");
        }
    }





}

void menu()
{
    printf("1. insert (head)\n");
    printf("2. insert (tail)\n");
    printf("3. insert (nth)\n");
    printf("4. delete (head)\n");
    printf("5. delete (tail)\n");
    printf("6. delete (nth)\n");
    printf("7. print list\n");
    printf("8. print list size\n");
    printf("0. Exit\n\n");

    printf("Enter choice: ");
}

node* createNode(int v)
{
    node *nn = new node();

    nn->data = v;
    nn->next = NULL;

    return nn;
}

node* insert_head(node *head, int v)
{
    node *nn;


    nn = createNode(v);

    nn->next = head;
    head = nn;
    return head;
}

void printList(node *head)
{
    node *temp;

    temp = head;

    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");

}

int getListSize(node *head)
{
    node *temp;
    int lSize = 0;

    temp = head;

    while(temp != NULL)
    {
        lSize++;
        temp = temp->next;
    }
    return lSize;

}

node* insert_tail(node *head, int v)
{
    node *temp = head;
    if(temp == NULL)
    {
        head = insert_head(head, v);
    }
    else
    {
        node *nn;
        nn = createNode(v);

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = nn;
    }

    return head;
}

node* insert_nth(node *head, int v, int n)
{
    node *temp = head;
    int i;

    if(n == 1)
    {
        head = insert_head(head, v);
    }
    else if(n == getListSize(head)+1)
    {
        head = insert_tail(head, v);
    }
    else
    {
        node *nn;
        nn = createNode(v);

        for(i = 1; i <= n-2; i++)
        {
            temp = temp->next;
        }

        nn->next = temp->next;
        temp->next = nn;
    }
    return head;
}

node* delete_head(node *head)
{
    node *del;
    del = head;
    head = head->next;
    delete(del);
    return head;
}

node* delete_tail(node *head)
{
    node *temp;
    temp = head;

    if(getListSize(head)==1)
    {
        head = delete_head(head);
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }
    return head;
}

node* delete_nth(node *head, int n)
{
    if(n == 1)
    {
        head = delete_head(head);
    }
    else if(n == getListSize(head))
    {
        head = delete_tail(head);
    }
    else
    {
        node *temp, *del;
        int i;

        temp = head;

        for(i = 1; i<= n-2; i++)
        {
            temp = temp->next;
        }
        del = temp->next;

        temp->next = del->next;
        delete(del);


    }
    return head;
}

node* seperateOddEven(node *head, int direction)
{
    node *evenHead = NULL, *oddT = NULL;
    node *evenH = NULL, *mostFreqail = NULL;
    node *temp = head;

    while (temp != NULL)
    {
        node *nn = createNode(temp->data);

        if (temp->data % 2 == 0)  // even
        {
            if (evenH == NULL)
            {
                evenH = mostFreqail = nn;
            }
            else
            {
                mostFreqail->next = nn;
                mostFreqail = nn;
            }
        }
        else  // odd
        {
            if (evenHead == NULL)
            {
                evenHead = oddT = nn;
            }
            else
            {
                oddT->next = nn;
                oddT = nn;
            }
        }

        temp = temp->next;
    }

   
    if (direction == 1) 
    {
        if (oddT != NULL)
            oddT->next = evenH;
        return (evenHead != NULL) ? evenHead : evenH;
    }
    else if (direction == 2) 
    {
        if (mostFreqail != NULL)
            mostFreqail->next = evenHead;
        return (evenH != NULL) ? evenH : evenHead;
    }

    return head; 
}
