#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head;

void insert(int x) //Insertion Function
{
    struct Node *next = (struct Node *)malloc(sizeof(struct Node)); //Creating new node
    next->data = x; // x stored next -> data
    next->link = NULL; //That node is storing address NULL which means it will be added at the end

    if (head == NULL) //If head was storing nothing that means we are adding the 1st node
        head = next; //Then the node is the head

    else // If the node was other than 1st node then
    {
        struct Node *prev = head; 
        while (prev->link != NULL) //Traversing to the end of the existing linked list and then adding new node 
            prev = prev->link; 

        prev->link = next; //prev node which is the last node will be storing the address of the next node
    }
}

void print() //Print function
{
    struct Node *temp = head; 
    printf("List is: \n");
    while (temp != NULL) //Traversing to the end of the function
    {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    int num, option;
    printf("*** Welcome to Linked List Insertion Program ***\n");

    while (1)
    {
        printf("[*] Enter:  1.Insert  2.Print  3.Exit\n ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("[+] Enter the element: \n");
            scanf("%d", &num);
            insert(num);
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