#include <stdio.h>
#include "_fun_.c"

void main()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int size = sizeof(arr) / sizeof(arr[0]);
    Node root = createNode(arr[0], NULL, NULL);
    Pair rtp = createPair(1, root);
    Pair stack[size];
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

    display(root);
}
