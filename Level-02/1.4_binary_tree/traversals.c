#include <stdio.h>
#include "_fun_.c"

void traversal(Node node)
{
    if (node == NULL)
        return;
    // printf("%d, ", node->data); // pre order
    traversal(node->left);
    // printf("%d, ", node->data); // in order
    traversal(node->right);
    printf("%d, ", node->data); // post order
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

    traversal(root);
}
