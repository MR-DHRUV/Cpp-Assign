#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

int count(struct Node *head)
{
    int c = 0;
    
    while (head != NULL)
    {
        c++;
        head = head->next;
    }

    return c;
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];

    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}



void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = 9;

    create(arr,n);
    Display(first);

    Insert(first,4,560);
    Display(first);

    Delete(first,2);
    Display(first);

    return 0;
}
