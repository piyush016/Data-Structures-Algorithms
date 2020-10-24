#include <stdio.h>
#include <stdlib.h>

struct Node //Creating a Data Type
{
    int data; //Stores Value
    struct Node *link; //Stores address of the next node
};

struct Node *front; //Keeps a track of front element
struct Node *rear; //Keeps a track of rear element

void enqueue() 
{
    int num;
    printf("Enter the number: ");
    scanf("%d",&num); //Data to be enqueued 
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); //Dynamically assigned memory
    newNode->data = num; //Num to be stored in the data of newNode
    newNode->link = NULL; //NULL address stored in newNode link

    if (rear == NULL) //If it's the first node
    {
        //Both front and rear will point at newNode
        rear = newNode; 
        front = newNode;
    }
    //If any other node then it will be linked at the end and rear will be pointing at it
    else 
    {
        rear->link = newNode;
        rear = newNode;
    }
}

void dequeue()
{
    if (front == NULL) //If there is no node in the queue
        printf("[!!] Queue Underflow.\n");
    else if(front == rear) //If there is only 1 node and that is to dequeued, then after deletion we should return to base case
    {
        struct Node *temp = front; 
        printf("[-] Deleted Element: %d\n",front->data);
        free(temp);
        front = NULL;
        rear = NULL;
    }
    else //If there are more than one node in the queue, then head should be changed to the 2nd element
    {
        struct Node *temp = front;
        printf("[-] Deleted Element: %d\n",front->data);
        front = front->link;
        free(temp);
    }
}

void print() //Printing the queue
{
    if (front == NULL) //No node in the queue
    {
        printf("[!!] Queue Underflow.\n");
    }
    else
    {
        struct Node *temp = front;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

void isFront() //Front element
{
    if (front == NULL) //Empty queue
    printf("[!!] Queue Underflow.\n");
    else //For any other case
    printf("Front: %d\n",front->data);
}

int isRear() //Rear element
{
    if (front == NULL) //Empty queue
    printf("[!!] Queue Underflow.\n");
    else //For any other case
    printf("Rear: %d\n", rear->data);
}

int main()
{
    int option;
    printf("*** Welcome to Queue implementation using Linked List ***\n");

    while (1)
    {
        printf("[*] 1.Enqueue  2.Dequeue 3. Front  4.Rear  5.Print  6.Exit\n");
        printf("[+] Select the operation: ");
        scanf("%d", &option); //Storing the selected option in variable

        switch (option) //Switching options
        {
        case 1:
            enqueue(); //Calling function to push/enqueue
            break;
        case 2:
            dequeue(); //Calling function to pop/dequeue
            break;
        case 3:
            isFront(); //Printing the front element
            break;
        case 4:
            isRear(); //Printing the rear element
            break;
        case 5:
            print(); //Printing all the elements in the stack
            break;
        case 6:
            printf("[-] Adios!!\n");
            exit(0); //Exiting the program
        default:
            printf("[!!] Please enter a valid input.\n");
            break;
        }
    }
}