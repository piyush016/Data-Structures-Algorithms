#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head = NULL;

void insert(int x) //Insertion Function
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); //Creating new node
    temp->data = x; // x stored in temp -> data
    temp->link = head; // Whatever is stored in head is being passed to temp->link
    head = temp; //temp is the new head
}

void print() //Print Function
{
    struct Node *temp = head; //temp is to iterate through the loop

    while (temp != NULL) //Last node will be store Null in the link
    {
        printf("%d\t", temp->data); //Printing data

        temp = temp->link; // To go to the next link
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