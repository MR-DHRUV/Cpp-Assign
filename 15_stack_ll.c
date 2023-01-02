#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LLNode
{
    int data;
    struct LLNode *next;
} LLNode;

typedef struct Stack
{
    LLNode *top;
} Stack;

bool isEmpty(Stack *st)
{
    if (st->top == NULL)
    {
        return true;
    }

    return false;
}

int atTop(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty\n");
        return -1;
    }

    return st->top->data;
}

void push(Stack *st, int x)
{ 
    LLNode *newTop = (LLNode *)malloc(sizeof(LLNode));
    newTop->next = NULL;
    newTop->data = x;

    if (newTop == NULL)
    {
        printf("Heap is full\n");
        return;
    }

    newTop->next = st->top;
    st->top = newTop;
    return;
}

void pop(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Already empty \n");
        return;
    }

    LLNode *temp = st->top;
    st->top = st->top->next;
    free(temp);
    return;
}

int main()
{
    bool menu = true;

    Stack st;
    st.top = NULL;

    // menu
    while (menu)
    {
        printf("Press\n1 for push \n2 for pop\n3 to view top\n4 for exit\n");
        int i;
        scanf("%d", &i);

        if (i == 1)
        {
            int in;
            printf("enter the element you want to push : ");
            scanf("%d", &in);
            push(&st, in);
        }
        else if (i == 2)
        {
            pop(&st);
        }
        else if (i == 3)
        {
            int ans = atTop(&st);
            if (ans != -1)
                printf("Top : %d \n", ans);
        }
        else if (i == 4)
        {
            menu = false;
            break;
        }
        else
        {
            printf("Invalid Input\n");
        }
    }
}
