#include <stdio.h>
#include "_fun_.c"

int sum(Node node)
{
    if (node == NULL)
        return 0;
    int lv = sum(node->left);
    int rv = sum(node->right);
    return lv + rv + node->data;
}

int size(Node node)
{
    if (node == NULL)
        return 0;
    int lv = size(node->left);
    int rv = size(node->right);
    return lv + rv + 1;
}
int max(Node node)
{
    if (node == NULL)
        return 0;
    int lmax = max(node->left);
    int rmax = max(node->right);

    if ((lmax > rmax) && (lmax > node->data))
        return lmax;
    else if ((lmax < rmax) && (lmax < node->data))
        return rmax;
    else
        return node->data;
}

int height(Node node)
{
    if (node == NULL)
        return 0;
    int lh = height(node->left);
    int rh = height(node->right);
    return lh > rh ? lh : rh + 1;
}

void main()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
    Node root = createNode(arr[0], NULL, NULL);
    Pair rtp = createPair(1, root);
    Pair stack[sizeOfArray];
    int topIndex = -1;
    stack[++topIndex] = rtp;

    int idx = 0;
    while (topIndex >= 0)
    {
        Pair top = stack[topIndex];

        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->left = createNode(arr[idx], NULL, NULL);
                stack[++topIndex] = createPair(1, top->node->left);
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->right = createNode(arr[idx], NULL, NULL);
                stack[++topIndex] = createPair(1, top->node->right);
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else
        {

            topIndex--;
        }
    }

    printf("sum = %d\n", sum(root));
    printf("size = %d\n", size(root));
    printf("max = %d\n", max(root));
    printf("height = %d\n", height(root));
}
