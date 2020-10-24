#include <stdio.h>
#include <stdlib.h>
#define size 10 //Max size

int array[size]; //Declaring the array
int top = -1;    //base case ie. Stack is empty

int isEmpty() //If the stack is empty return True and if not then false
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int isFull() //If the stack uis full return True and if not then false
{
    if (top == size - 1)
        return 1;
    else
        return 0;
}

void push() //Pushing the element in the stack
{
    int num;

    if (isFull()) //If the stack is full it's stack overflow
    {
        printf("[!!] Stack Overflow\n");
        return;
    }
    else //Pushing the element in the stack
    {
        printf("[*] Enter the number: ");
        scanf("%d", &num);
        top++;
        array[top] = num;
        return;
    }
}

void pop() //Popping the element from the stack
{
    if (isEmpty()) //If the stack is empty it's stack underflow
    {
        printf("[!!] Stack Underflow\n");
        return;
    }

    else //Popping the element from the stack
    {
        printf("[-] Popped element: %d\n", array[top]);
        top--;
        return;
    }
}

void peek() //Peeking the top element
{
    if (isEmpty())
    {
        printf("[!!] Cant Peek. Stack Underflow\n");
        return;
    }
    else
    {
        printf("[+] Top: %d\n", array[top]);
        return;
    }
}

void print() //Printing the elements of the stack
{
    int i;
    for (i = 0; i <= top; i++)
        printf("%d\t", array[i]);

    printf("\n");
    return;
}

int main()
{
    int option;
    printf("*** Welcome to the Stack Implementation using Array ***\n");
    while (1) //While true
    {
        printf("[*] 1.Push  2.Pop  3.Peek  4.Print  5.Exit\n");
        printf("[+] Select the operation: ");
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
            printf("[+] Adios!!\n");
            exit(0);
        default:
            printf("[+] Please enter a valid option!!\n");
            break;
        }
    }
}