#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LLNode
{
    struct Node *data;
    struct LLNode *next;
} LLNode;

typedef struct Stack
{
    LLNode *top;
    int count;
} Stack;

void init(Stack *st)
{
    st->count = 0;
}

bool isEmpty(Stack *st)
{
    if (st->count == 0)
    {
        return true;
    }

    return false;
}

Node *atTop(Stack *st)
{
    if (isEmpty(st))
    {
        printf("Stack is empty\n");
        return NULL;
    }

    return st->top->data;
}

void push(Stack *st, Node *x)
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
    st->count++;
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
    st->count--;

    if(st->count == 0)
    {
        st->top = NULL;
    }

    return;
}

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *insert(Node *root, int i)
{
    if (root == NULL)
    {
        Node *t = (Node *)malloc(sizeof(Node));
        t->data = i;
        t->left = NULL;
        t->right = NULL;

        return t;
    }

    if (root->data > i)
    {
        root->left = insert(root->left, i);
    }
    else if (root->data < i)
    {
        root->right = insert(root->right, i);
    }

    return root;
}

void pre(Node *head)
{
    Node *t = head;
    Stack st;
    init(&st);

    while (t != NULL || isEmpty(&st) == false)
    {
        if (t != NULL)
        {
            printf("%d ", t->data);
            push(&st, t);
            t = t->left;
        }
        else
        {
            t = atTop(&st);
            pop(&st);

            if (t == NULL)
            {
                break;
            }
            t = t->right;
        }
    }

    printf("\n");
};

void in(Node *head)
{
    Node *t = head;
    Stack st;
    init(&st);

    while (t != NULL || isEmpty(&st) == false)
    {

        if (t != NULL)
        {
            push(&st, t);
            t = t->left;
        }
        else
        {
            t = atTop(&st);
            pop(&st);

            if (t == NULL)
            {
                break;
            }

            printf("%d ", t->data);

            t = t->right;
        }
    }

    printf("\n");
};

void post(Node *head)
{
    Node *t = head;
    Stack st;
    long long int temp;
    init(&st);

    while (t != NULL || isEmpty(&st) == false)
    {
        if (t != NULL)
        {
            push(&st, t);

            t = t->left;
        }
        else
        {
            temp = (long long int)atTop(&st);
            pop(&st);

            if (temp == NULL)
            {
                break;
            }

            if (temp > 0)
            {
                Node *c = (Node *)(temp * (-1));
                push(&st, c);

                t = ((Node *)temp)->right;
            }
            else
            {
                printf("%d ", ((Node *)(temp * (-1)))->data);
                t = NULL;
            }
        }
    }

    printf("\n");
};

int heightCalc(Node *h)
{
    // base condition
    if (h == NULL)
    {
        return 0;
    }

    int x = heightCalc(h->left);
    int y = heightCalc(h->right);

    if (x > y)
        return x + 1;

    return y + 1;
}

Node *search(Node *t, int target)
{
    if (t == NULL)
    {
        return NULL;
    }

    // equal
    if (t->data == target)
    {
        return t;
    }
    else if (t->data > target)
    {
        // left will have smaller elements
        return search(t->left, target);
    }
    else
    {
        // right will have smaller elements
        return search(t->right, target);
    }
}

Node *del(Node *root, int target, const Node *head)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL && root->data == target)
    {
        if (root == head)
        {
            head = NULL;
        }
        else
        {
            free(root);
        }

        return NULL;
    }

    if (root->data > target)
    {
        root->left = del(root->left, target, head);
    }
    else if (root->data < target)
    {
        root->right = del(root->right, target, head);
    }
    else
    {

        if (heightCalc(root->left) > heightCalc(root->right))
        {
            Node *pre = root->left;
            while (pre->right != NULL)
            {
                pre = pre->right;
            }

            root->data = pre->data;

            root->left = del(root->left, pre->data, head);
        }
        else
        {
            Node *pre = root->right;
            while (pre->left != NULL)
            {
                pre = pre->left;
            }

            root->data = pre->data;

            root->right = del(root->right, pre->data, head);
        }
    }

    return root;
}

int main()
{
    bool menu = true;

    Node *root = NULL;

    // menu
    while (menu)
    {
        printf("Press\n1 for insert \n2 for delete\n3 to search a value\n4 for Preorder\n5 for Inorder\n6 for Postorder\n7 for exit\n");
        int i;
        scanf("%d", &i);

        if (i == 1)
        {
            int in;
            printf("enter the element you want to insert : ");
            scanf("%d", &in);
            root = insert(root, in);
        }
        else if (i == 2)
        {
            int in;
            printf("enter the element you want to delete : ");
            scanf("%d", &in);
            root = del(root, in, root);
        }
        else if (i == 3)
        {
            int in;
            printf("enter the element you want to search : ");
            scanf("%d", &in);
            Node *isPresent = search(root, in);

            if (isPresent != NULL)
                printf("The given value is present in the bst\n");
            else
                printf("The given value is not present in the bst\n");
        }
        else if (i == 4)
        {
            pre(root);
        }
        else if (i == 5)
        {
            in(root);
        }
        else if (i == 6)
        {
            post(root);
        }
        else if (i == 7)
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
