#include <stdio.h>
#include <stdlib.h>

struct Node //Creating a new data type
{
    int data; //This will store data
    struct Node *link; //This will store address of data type Node 
};

struct Node *top = NULL; //Last element
struct Node *head = NULL; //First element
int count = 0; //Total element in stack

void push() //We will change the address of last element in the stack from NULL to temp node thus linking it
{
    int num; //Variable to store the num to be pushed
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("[+] Enter a number: ");
    scanf("%d", &num);

    temp->data = num; //num stored in data of data type temp
    temp->link = NULL; //Pointing to Null thus making it the last element. But it is still not in the stack

    if(head == NULL) //For adding the first element in the stack
        head = temp; //Making temp as head

    else //To link the last element with newly added element
    {
        struct Node *prev = head;

        while(prev->link != NULL) //Traversing till the last node of the stack as it will be pointing to NULL
        prev = prev->link; 

        prev->link = temp; //Giving the address of temp to the former last node thus making it 2nd last element and temp as last element
    }    
    top = temp; //Making temp as the top element
    count++; //Increasing the count
}

void pop() // We will change the 2nd last element link to NULL thus it won't be pointing to the last element and 2nd last element will become top now
{
    int i;
    struct Node *prev = head; 
    
    if (count == 0) //No element in the stack
    {
        printf("[!!] Stack Underflow!!\n");
        return;
    }
    else if(count == 1) //For popping the 1st element (special case)
    {
        free(prev); //deleting the node
        head = NULL; //Tells head is pointing nowhere
        count = 0; //Number of elements are 0
    }
    else
    {
        for(i = 0; i< count-2; i++) //For popping the element from any place other than head
        prev = prev->link; //Traversing to the nd last element so we can change link to NULL

        prev->link = NULL; //Changing the link of 2nd last element to NULL so that it doesn't point anywhere and link between the 2nd last and last element is broken
        top = prev; //2nd last element is now last or top element
        count--; //Decreasing the count 
    }
}

void peek() //Getting the top element
{
    struct Node *temp = top;
    if (top == NULL || count == 0) //No element in the stack
    {
        printf("[!!] Stack Underflow. No elements in the Stack\n");
        return;
    }
    else //Returning the top element
    {
        printf("Top: %d\n", temp->data);
        return;
    }
}

void print() //Print Function
{
    struct Node *temp = head;
    while (temp != NULL) //Travering in the stack until we get the last node
    {
        printf("%d\t", temp->data); //Simultaneously we are printing the data
        temp = temp->link; //Going to the next node for the while loop
    }
    printf("\n");
}

int main()
{
    int option;

    printf("*** Welcome to the Stack implementation using Linked List ***\n");
    while (1)
    {
        printf("1.Push  2.Pop  3.Peek  4.Print  5.Exit  \n");
        printf("Select the operation: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            print();
            break;
        case 5:
            printf("\n[+] Adios!!\n");
            exit(0);
        default:
            printf("[+] Please enter a valid option!!\n");
            break;
        }
    }
}