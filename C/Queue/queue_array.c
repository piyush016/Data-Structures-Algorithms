#include <stdio.h>
#include <stdlib.h>

#define size 10
int array[size]; //Declaring the array with max size
int front = -1, rear = -1; //When no elements in the queue

int isEmpty() //Checking if queue is empty
{
    if (front == -1 || front > rear) //In both these cases queue will be empty
        return 1; //Return True
    else
        return 0; //Else False
}

int isFull() //Checking if queue is full
{
    if (rear == size - 1) //If rear is equal to the size of the queue
        return 1; //Return True
    else
        return 0; //Else False
}

void enqueue() //Pushing the element in the array
{
    int num; 

    if (isFull()) //If the queue is full
    {
        printf("[!!] Queue Overflow.\n");
        return;
    }

    else if (isEmpty()) //For the first element
    {
        printf("[+] Enter the number: ");
        scanf("%d", &num);
        rear++; 
        front++; //Increasing the front
        array[rear] = num;
        return;
    }

    else
    {
        printf("[+] Enter the number: "); //For any other element
        scanf("%d", &num);
        rear++;
        array[rear] = num;
        return;
    }
}

void dequeue()
{
    if (isEmpty()) //If the queue is empty
    {
        printf("[!!] Queue Underflow.\n");
        return;
    }
    else
    {
        printf("[+] Deleted element: %d.\n",array[front]);
        front++;
        return;
    }
}

void isFront()
{
    if (isEmpty())
    {
        printf("[!!] No elements in the array.\n");
        return;
    }

    else
    {
        printf("Front Element: %d\n", array[front]);
        return;
    }
}
void isRear()
{
    if (isEmpty())
    {
        printf("[!!] No elements in the array.\n");
        return;
    }

    else
    {
        printf("Rear Element: %d\n", array[rear]);
        return;
    }
}

void print()
{
    int i;

    if (isEmpty())
        printf("[!!] No element in the array.");

    else
    {
        for (i = front; i <= rear; i++)
            printf("%d\t", array[i]);
    }

    printf("\n");

    return;
}

int main()
{
    int option; //To store the selected option

    printf("*** Welcome to the Queue Implemenation using Array ***\n");

    while (1)
    {
        printf("[+] 1.Enqueue  2.Dequeue  3.Front  4.Rear  5.Print  6.Exit \n"); //Operations that can be performed on the queue
        printf("[+] Select the operation: ");
        scanf("%d", &option);  //Storing the selected option in variable

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
            print(); //Printing all the elements in the array
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