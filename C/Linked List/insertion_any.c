#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *link;
};

struct Node *head; // Keeps a track of head

void insert(int x, int pos) // Passing value and the position at which we want to insert
{
    int i;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); //Creating new node

    temp->data = x; // Data stored in the temp node
    temp->link = NULL; // NULL is being stored in temp link

    if (pos == 1) // Inserting first node
    {
        temp->link = head; 
        head = temp; //Creating the first node as head as first node can also be inserted later in the program
        return;
    }

    struct Node *prev = (struct Node *)malloc(sizeof(struct Node)); //Creating new node if pos != 1

    prev = head; 

    for (i = 0; i<pos-2; i++) //Traversing to the position before the the position passed 
    {
        prev = prev->link;
    }
    temp->link = prev->link; //Since temp will be linked just after the prev node so temp needs to store the address where prev was pointing to complete the list
    prev->link = temp; //prev needs to point to temp to complete the linked list
}

void print() // Print Function
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    int num, pos, option;
    printf("*** Welcome to Linked List Insertion Program ***\n");

    while (1)
    {
        printf("[*] Enter:  1.Insert  2.Print  3.Exit\n ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("[+] Enter the element and position: \n");
            scanf("%d %d", &num, &pos);
            insert(num, pos);
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