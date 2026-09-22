#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

int preIndex = 0;
int postIndex;

struct Node *createNode(int data)
{
    struct Node *node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node *buildPostIn(int post[], int in[], int start, int end)
{
    if (start > end)
        return NULL;

    struct Node *root = createNode(post[postIndex--]);

    int pos = search(in, start, end, root->data);

    root->right = buildPostIn(post, in, pos + 1, end);
    root->left = buildPostIn(post, in, start, pos - 1);

    return root;
}

int main()
{
    printf("Question 1: Tree Reconstruction\n");

    int pre[] = {1, 2, 4, 5, 3};
    int in[] = {4, 2, 5, 1, 3};
    int post[] = {4, 5, 2, 3, 1};
    int n = 5;

    postIndex = n - 1;
    struct Node *root2 = buildPostIn(post, in, 0, n - 1);

    return 0;
}