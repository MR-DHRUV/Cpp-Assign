#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct Queue
{
    Node *front;
    Node *back;
} Queue;

bool isEmpty(Queue *q)
{
    if (q->front == NULL)
    {
        return true;
    }

    return false;
}

void enqueue(Queue *q, int x)
{
    Node *nextNode = (Node *)malloc(sizeof(Node));
    nextNode->data = x;
    nextNode->next = NULL;

    // checking if heap is full or not
    if (nextNode == NULL)
    {
        printf("Heap is full\n");
        return;
    }

    if (q->front == NULL)
    {
        q->front = q->back = nextNode;
    }

    q->back->next = nextNode;
    q->back = q->back->next;
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    if (q->front == q->back)
    {
        free(q->front);
        q->front = q->back = NULL;
        return;
    }

    Node *temp = q->front;
    q->front = q->front->next;
    free(temp);
}

int atFornt(Queue *q)
{
    if (isEmpty(q))
    {
        return -1;
    }

    return q->front->data;
}

int main()
{
    bool menu = true;

    Queue qt;
    qt.front = NULL;
    qt.back = NULL;

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
            else
                printf("Queue is empty \n");
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
