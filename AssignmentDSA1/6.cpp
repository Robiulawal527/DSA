
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
    node *tmp;

    tmp = head;

    while(tmp != NULL)
    {
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");

}

int getListSize(node *head)
{
    node *tmp;
    int lSize = 0;

    tmp = head;

    while(tmp != NULL)
    {
        lSize++;
        tmp = tmp->next;
    }
    return lSize;

}

node* insert_tail(node *head, int v)
{
    node *tmp = head;
    if(tmp == NULL)
    {
        head = insert_head(head, v);
    }
    else
    {
        node *nn;
        nn = createNode(v);

        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = nn;
    }

    return head;
}

node* insert_nth(node *head, int v, int n)
{
    node *tmp = head;
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
            tmp = tmp->next;
        }

        nn->next = tmp->next;
        tmp->next = nn;
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
    node *tmp;
    tmp = head;

    if(getListSize(head)==1)
    {
        head = delete_head(head);
    }
    else
    {
        while(tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        delete(tmp->next);
        tmp->next = NULL;
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
        node *tmp, *del;
        int i;

        tmp = head;

        for(i = 1; i<= n-2; i++)
        {
            tmp = tmp->next;
        }
        del = tmp->next;

        tmp->next = del->next;
        delete(del);


    }
    return head;
}

node* delete_first_occurrence(node *head, int val)
{
    node *tmp = head, *prev = NULL;

    while (tmp != NULL)
    {
        if (tmp->data == val)
        {
            if (prev == NULL)
            {
                // First node
                head = head->next;
                delete(tmp);
            }
            else
            {
                prev->next = tmp->next;
                delete(tmp);
            }
            return head;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return head;
}

node* notMoreThanTwo(node *head, int value, int *freq)
{
    if (freq[value] == 0)
    {
        head = insert_head(head, value);
        printf("%d inserted\n", value);
    }
    else if (freq[value] == 1)
    {
        head = insert_tail(head, value);
        printf("%d inserted\n", value);
    }
    else
    {
        head = delete_first_occurrence(head, value);
        printf("%d deleted\n", value);
    }

    freq[value]++;
    return head;
}
