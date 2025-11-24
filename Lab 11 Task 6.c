#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node *search(Node *root, int value)
{
    if (root == NULL || root->value == value)
    {
        return root;
    }

    if (value < root->value)
    {
        return search(root->left, value);
    }

    return search(root->right, value);
}

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->value);
    inorderTraversal(root->right);
}

int main()
{
    Node *root = NULL;
    int choice, value;

    printf("Building a Binary Search Tree with at least 10 nodes\n\n");

    int initialValues[] = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 65};
    int n = 11;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, initialValues[i]);
        printf("Inserted %d\n", initialValues[i]);
    }

    while (1)
    {
        printf("\n=== BST Operations ===\n");
        printf("1. Insert a node\n");
        printf("2. Search for a value\n");
        printf("3. Find height of tree\n");
        printf("4. Count total nodes\n");
        printf("5. Display in-order traversal\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Value inserted.\n");
        }
        else if (choice == 2)
        {
            printf("Enter value to search: ");
            scanf("%d", &value);
            Node *result = search(root, value);
            if (result != NULL)
            {
                printf("Value %d found in the tree.\n", value);
            }
            else
            {
                printf("Value %d not found in the tree.\n", value);
            }
        }
        else if (choice == 3)
        {
            printf("Height of tree: %d\n", height(root));
        }
        else if (choice == 4)
        {
            printf("Total nodes: %d\n", countNodes(root));
        }
        else if (choice == 5)
        {
            printf("In-order traversal: ");
            inorderTraversal(root);
            printf("\n");
        }
        else if (choice == 6)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}