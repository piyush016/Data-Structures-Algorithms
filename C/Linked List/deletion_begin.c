#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;

void delete () // Deletion function 
{
    struct Node *temp = head;

    if (temp == NULL) // No element in the linked list
        printf("[!!] List is empty!!\n");

    else
    {
        printf("[+] Deleted element: %d\n", temp->data); 
        head = head->link; // head now stores the 2nd element in the list
        free(temp); //1st element getting deleted
    }
}

void insert(int x) //Same as insertion program
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = x;
    temp->link = NULL;

    if (head == NULL)
        head = temp;

    else
    {
        struct Node *prev = head;
        while (prev->link != NULL)
            prev = prev->link;

        prev->link = temp;
    }
}

void print() //Same as insertion program
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    int option;
    printf("*** Welcome to Linked List Deletion Program ***\n");

    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    while (1)
    {
        printf("[*] Enter:  1.Delete  2.Print  3.Exit\n ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            delete();
            break;

        case 2:
            printf("[+] List is : \n");
            print();
            break;

        case 3:
            printf("[+] Adios!!");
            exit(0);
        }
    }
}