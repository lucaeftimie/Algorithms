#include<stdio.h>
#include<string.h>
#include "./../../Data_Structures/min_heap_node.c"

void preorder(const node *root)
{
    if (root != NULL)
    {

        preorder(root->left);
        printf("%f ", root->frequency);
        preorder(root->right);
    }

}

double* calculate_frequencies(const char* str)
{
    int count[256] = {0};
    const size_t total_chars = strlen(str);

    for (int i = 0; i < total_chars; i++)
    {
        count[str[i]]++;
     }

    printf("\n");
    double* frequencies = (double*)malloc(sizeof(double) * 256);

    for (int i = 0; i < 256; i++)
        if (count[i] != 0)
            frequencies[i] = (double)count[i] / (double)total_chars;

    return frequencies;
}

node* create_huffman_tree(min_heap *heap)
{
    node *root = NULL;
    while (heap->size >= 2)
    {
        
        node *n1 = NULL, *n2 = NULL, *temp1, *temp2;
        
        if ((temp1 = pop(heap)))
        {
            n1 = (node*)malloc(sizeof(node));
            n1->character = temp1->character;
            n1->frequency = temp1->frequency;
            n1->left = temp1->left;
            n1->right = temp1->right;
        }

        if ((temp2 = pop(heap)))
        {
            n2 = (node*)malloc(sizeof(node));
            n2->character = temp2->character;
            n2->frequency = temp2->frequency;
            n2->left = temp2->left;
            n2->right = temp2->right;
        }

        node * new_node = (node*)malloc(sizeof(node));
        new_node->character = -1;
        new_node->frequency = n1->frequency + n2->frequency;
        new_node->left = n1;
        new_node->right = n2;

       
        push(heap, *new_node);
        root = new_node;
    }

    return root;
}

void decode_huffman_tree(const char *code, node *tree)
{
    const node *root = tree;

    const unsigned long len = strlen(code);

    for (int i = 0; i < len; i++)
    {
        if (code[i] == '0')
            root = root->left;

        if (code[i] == '1')
            root = root->right;

        if (root->left == NULL)
        {
            printf("%c", root->character);
            root = tree;
        }
    }
}

int main()
{
    const char *string = "abbcccdddd";
    const double *frequencies = calculate_frequencies(string);

    int unique_chars = 0;
    for (int i = 0; i < 256; i++)
        if (frequencies[i] != 0)
            unique_chars++;

    min_heap* heap = create_heap(unique_chars);

    for (int i = 0; i < 256; i++)
        if (frequencies[i] != 0)
        {
            node new_node;
            new_node.character = i;
            new_node.frequency = frequencies[i];
            new_node.left = NULL;
            new_node.right = NULL;

            push(heap, new_node);
        }

    node *root = create_huffman_tree(heap);

    decode_huffman_tree("1101111111010100000", root);

    return 0;
}