#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "./../Data_Structures/min_heap_tree.c"


min_heap* calculate_frequencies(const char* str)
{
    int count[256] = {0};
    const size_t total_chars = strlen(str);

    for (int i = 0; i < total_chars; i++)
    {
        count[str[i]]++;
        printf("%d ", count[str[i]]);
     }

    printf("\n");
    double frequencies[256] = {0};

    int unique_chars = 0;
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            unique_chars++;
            frequencies[i] = (double)count[i] / total_chars;
            printf("%d ", frequencies[i]);
        }
    }

    min_heap *heap = create_heap(unique_chars);

    for (int i = 0; i < 256; i++)
    {

        if (frequencies[i] != 0)
        {
            node new_node;

            new_node.frequency = frequencies[i];
            new_node.character = i;
            new_node.left = NULL;
            new_node.right = NULL;

            push(heap, new_node);
        }

    }

    return heap;
}


node* create_huffman_tree(min_heap *heap)
{
    while (heap->size > 1)
    {
        node* new_node = (node*)malloc(sizeof(node));

        node* n1 = pop(heap);
        node* n2 = pop(heap);

        new_node->character = -1;
        new_node->frequency = n1->frequency + n2->frequency;
        
        new_node->left = n1;
        new_node->right = n2;

        push(heap, *new_node);
        free(new_node);
    }

    return pop(heap);
}

int decode_huffman_tree(char *code, node *tree)
{
    node *root = tree;
    while (code != '\0')
    {
        if (*code == '0') root = root->left;

        if (*code == '1') root = root->right;

        if (root->left == NULL && root->right == NULL)
        {
            printf("%c", root->character);
            root = tree;
        }
    }
}

int main()
{
    char *string = (char*)malloc(sizeof("lucaefti"));
    string = "lucaefti";
    min_heap* heap1 = calculate_frequencies(string);
    node *p1 = pop(heap1);
    node *p2 = pop(heap1);
    printf("%f, %c\n", p1->frequency, p1->character);
    printf("%f, %c",   p2->frequency, p2->character);

    // node *root = create_huffman_tree(heap1);
    // decode_huffman_tree("I like English Architecture", root);

    return 0;
}