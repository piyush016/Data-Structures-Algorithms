#include <stdio.h>
#include <stdlib.h>

#define size 5             //Max Size if the array
int array[size];           //Declaring array
int front = -1, rear = -1; //No element in the queue

int isEmpty() //To check if the queue is empty
{
    if (front == -1 && rear == -1) //base case
        return 1;                  //Return True
    else
        return 0; //Return False
}

int isFull() //To check if the queue is full
{
    //If the queue is full, then rear+1 will be equal to the front most element index
    if ((rear + 1) % size == front)
        return 1; //Return True
    else
        return 0; //Return False
}

void enqueue() //Pushing the element
{
    int num; //Variable to store the number which we will push

    if (isFull()) //Checking if the queue is full
    {
        printf("[!!] Queue Overflow\n");
        return;
    }
    else if (isEmpty()) //base case
    {
        printf("[+] Enter the number:  ");
        scanf("%d", &num);

        front = rear = 0;  //Making the front and rear both to point at 0th index
        array[rear] = num; //Passing the num to the end of the queue

        return;
    }

    else
    {
        //For any other case
        printf("[+] Enter the number:  ");
        scanf("%d", &num);

        rear = (rear + 1) % size; //Getting the rear index for a circular queue

        array[rear] = num; //Passing the num to the end of the queue

        return;
    }
}

void dequeue()
{
    if (isEmpty()) //Checking if the queue is empty
    {
        printf("[!!] Queue Underflow\n");
        return;
    }
    else if (front == rear) //If only 1 element was inserted and being removed later, therfore the queue is empty ie. base case
    {
        printf("[+] Deleted Element: %d\n", array[front]); //Element gets removed from the front
        rear = front = -1;                                 //Going back to base case
        return;
    }
    else
    {
        //For any other case
        printf("[+] Deleted Element: %d\n", array[front]);
        front++; //Changing front therfore it element before front will be over-written by other element
        return;
    }
}

void isFront()
{
    if (isEmpty()) //If empty then no element at front
    {
        printf("[!!] No element in the queue.\n");
        return;
    }
    else
    {
        printf("[+] Front: %d\n", array[front]);
        return;
    }
}

void isRear()
{
    if (isEmpty()) //If empty then no element at rear
    {
        printf("[!!] No element in the queue.\n");
        return;
    }
    else
    {
        printf("[+] Rear: %d\n", array[rear]);
        return;
    }
}

void print()
{
    int i;
    int length = (rear + size - front) % size + 1; //To get the length of the queue. 
    
    if (isEmpty())
        printf("[!!] Queue is empty\n");
    else
    {
        for (i = 0; i < length; i++)
            printf("%d\t", array[(front + i) % size]); //Printing the elements from the front element to the rear element
    }
    printf("\n");

    return;
}

int main()
{
    int option;
    printf("*** Welcome to Circular Array Implementation ***\n");

    while (1)
    {
        printf("[+] 1.Enqueue  2.Dequeue  3.Front  4.Rear  5.Print  6.Exit \n");
        printf("[+] Select the operation: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            isFront();
            break;
        case 4:
            isRear();
            break;
        case 5:
            print();
            break;
        case 6:
            printf("[-] Adios!!\n");
            exit(0);
        default:
            printf("[!!] Please enter a valid option.\n");
            break;
        }
    }
}