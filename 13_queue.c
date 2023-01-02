#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// if we only use 1 pointer that is back pointer then deletion of first element takes O(N) time as we have to shift all the elements at the back in the array

typedef struct Queue
{
    int *q;
    int front;
    int back;
    int size;
} Queue;

bool isEmpty(Queue *q)
{
    if (q->front == q->back)
    {
        return true;
    }

    return false;
}

bool isFull(Queue *q)
{
    if (q->back == q->size - 1)
    {
        return true;
    }

    return false;
}

void enqueue(Queue *q, int x)
{
    if (isFull(q) == false)
    {
        q->back++;
        q->q[q->back] = x;
    }
    else
    {
        printf("Queue is full \n");
    }
}

void dequeue(Queue *q)
{
    if (isEmpty(q) == false)
    {
        q->front++;
        q->q[q->front] = -1;
    }
    else
    {
        printf("Queue is empty \n");
    }
}

int atFornt(Queue *q)
{
    if (isEmpty(q) == false)
    {
        return q->q[q->front + 1];
    }
    else
    {
        printf("Queue is empty \n");
    }

    return -1;
}

int main()
{

    bool menu = true;

    printf("Enter the size of queue : ");
    int size;
    scanf("%d", &size);

    // init
    Queue qt;
    qt.q = (int *)malloc(sizeof(int) * size);
    qt.size = size;
    qt.back = -1;
    qt.front = -1;

    // menu
    while (menu)
    {
        printf("Press\n1 for enqueue \n2 for dequeue\n3 to view front\n4 for exit\n");
        int i;
        scanf("%d", &i);

        if (i == 1)
        {
            int in;
            printf("enter the element you want to push : ");
            scanf("%d", &in);
            enqueue(&qt,in);
        }
        else if (i == 2)
        {
            dequeue(&qt);
        }
        else if (i == 3)
        {
            int ans = atFornt(&qt);
            if(ans != -1)
                printf("Front : %d \n",ans);
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

    return 0;
}