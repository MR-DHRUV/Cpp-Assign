#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct Queue
{
    int *q;
    int front;
    int back;
    int size;
}Queue;


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
    // in circular queue there can be 2 cases for full
    // case1 : _ 2 2 4 6 7
    // case1 : 2 2 _ 4 6 7

    // both are same , if we see circulary, the next position of back is 0 only, so this condiation handles all of the cases
    if ((q->back + 1) % q->size == q->front)
    {
        return true;
    }

    return false;
}

void enqueue(Queue *q,int x)
{
    if (isFull(q) == false)
    {
        // aisa isilie kara taaki range se bahar na jaye
        // if array size is 7 and back is at last index that is 6 and we have space at front
        // new back will be (6+1)%7 = 0, which is what we want
        q->back = (q->back + 1) % q->size;
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
        q->front = (q->front + 1) % q->size;
        q->q[q->front] = -1;
    }
    else
    {
        printf("Queue is empty\n");
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
        printf("Queue is empty\n");
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
    qt.back = 0;
    qt.front = 0;

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
            enqueue(&qt, in);
        }
        else if (i == 2)
        {
            dequeue(&qt);
        }
        else if (i == 3)
        {
            int ans = atFornt(&qt);
            if (ans != -1)
                printf("Front : %d \n", ans);
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