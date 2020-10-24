#include <stdio.h> 
int stack[20]; //Stack to push pop element
int top = -1; //base case

void push(int num) 
{
    stack[++top] = num; //Increasing top value and then storing the num in the stack
    return;
}

int pop()
{
    return stack[top--]; //Returning the top element in the stack and then top is pointing 1 element below
}

int isDigit(char e) //To check if the character is digit or an operator 
{
    if (e == '+' || e == '-' || e == '*' || e == '/')
    {
        return 0; //Returning false value that it is not a digit
    }

    else
        return 1; //Returning true value that it is a digit
}

int evaluate(char operation, int n1, int n2) //Evaluating the operator and operand to an integer value
{
    int ans; 
    switch (operation) //Checking which operation we have to perform on the given operands
    {
    case '+':
        ans = n2 + n1;
        break;
    case '-':
        ans = n2 - n1;
        break;
    case '/':
        ans = n2 / n1;
        break;
    case '*':
        ans = n2 * n1;
        break;
    }

    return ans;
}

int main()
{
    char exp[20];
    char *e; //Pointer to point the current value in the expression array
    int n1, n2, num, result;

    printf("*** Welcome to PostFix Evaluation ***\n");
    printf("[*] Enter the expression: \n");
    scanf("%s", exp);
    e = exp; //e pointing to the base address of the array

    while (*e != '\0') //While loop until we hit enter
    {
        if (isDigit(*e)) //Checking if it's a digit or not
        {
            num = *e - 48; //If it's a digit, we are converting it from str to int
            push(num); //pushing the num in the stack
        }

        else //If it's not a digit, that means it's a operator
        {
            //popping last 2 element from the stack 
            n1 = pop(); 
            n2 = pop();
            //Evaluating the expression with the operator
            result = evaluate(*e, n1, n2);
            push(result); //pushing the result in the stack so we can perform further evaluation(if any) further
        }
        e++; //Traversing in the string
    }

    printf("[+] Result: %d", pop()); //Printing the one and only present value in the stack
}