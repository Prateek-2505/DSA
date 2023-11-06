#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int capacity;
    int top;
    int *arr;
};

int peek(struct node *stack);
void push(struct node *stack, int value);
int pop(struct node *stack);
bool isStackEmpty(struct node *stack);
bool isStackFull(struct node *stack);
struct node *create(int capacity);

struct node *create(int capacity)
{
    struct node *stack = (struct node *)malloc(sizeof(struct node));
    stack->arr = (int *)calloc(capacity, sizeof(int));
    stack->top = -1;
    return (stack);
}

void push(struct node *stack, int value)
{
    if (!isStackFull(stack))
        stack->arr[++stack->top] = value;
    else
    {
        printf("Stack overflow\n");
        return;
    }
}

int pop(struct node *stack)
{
    if (isStackEmpty(stack))
    {
        printf("Stack is empty !! \n");
        return INT_MIN;
    }
    else
        return (stack->arr[(stack->top)--]);
}

int peek(struct node *stack)
{
    if (isStackEmpty(stack))
        return INT_MIN;
    else
        return (stack->arr[stack->top]);
}
bool isStackEmpty(struct node *stack)
{
    if (stack->top == -1)
        return true;
    else
        return false;
}
bool isStackFull(struct node *stack)
{
    if (stack->top == stack->capacity - 1)
        return true;
    else
        return false;
}

void main()
{
    printf("Enter the capacity of the stack\n");
    int cap;
    scanf("%d", &cap);
    struct node *stack = create(cap);
    if (stack == NULL)
    {
        printf("Stack could not be created\n");
        exit(0);
    }

    do
    {
        printf("choose any \n\t1. PUSH\n\t2. POP\n\t3. PEEK\n\t4. IS EMPTY\n\t5. IS FULL\n\t6. DISPLAY STACK\n\t");
        int option;
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the value to be pushed into the stack\n");
            int value;
            scanf("%d", &value);
            push(stack, value);
            break;

        case 2:
            printf("value poped = %d\n", pop(stack));
            break;

        case 3:
            printf("Value at top = %d\n", peek(stack));
            break;
        case 4:
            if (isStackEmpty(stack))
                printf("Stack is Empty!!\n");
            else
                printf("Stack is Not Empty!!\n");
            break;
        case 5:
            if (isStackFull(stack))
                printf("Stack is Full!!\n");
            else
                printf("Stack is Not Full!!\n");
            break;
        case 6:

        default:
            break;
        }
        printf("Do you want to continue... if yes enter 'y'\n");
        fflush(stdin);
    } while (getchar() == 'y');
}