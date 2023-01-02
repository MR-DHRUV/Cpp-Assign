#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void in(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // left
    in(p->left);

    // node
    printf("%d ", p->data);

    // right
    in(p->right);
};

void pre(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // node
    printf("%d ", p->data);

    // left
    in(p->left);

    // right
    in(p->right);
};

void post(Node *p)
{
    if (p == NULL)
    {
        return;
    }

    // left
    in(p->left);

    // right
    in(p->right);

    // node
    printf("%d ", p->data);
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
