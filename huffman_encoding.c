#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int character;
    double probability;
    struct node *left;
    struct node *right;
}node;

int create_huffman_tree(const char* str)
{
    int count[256] = {0};
    size_t total_chars = strlen(str);

    for (int i = 0; i < total_chars; i++)
    {
        count[str[i]]++;
    }

    double probs[256] = {0};

    int unique_chars = 0;
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            unique_chars++;
            probs[i] = (double)count[i] / total_chars;
        }
    }

    node* leaves[unique_chars];
    int index = 0;
    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            node *new_leaf = (node*)malloc(sizeof(node));
            new_leaf->character = i;
            new_leaf->probability = probs[i];
            new_leaf->right = NULL;
            new_leaf->right = NULL;
            leaves[index] = new_leaf;
            index++;
        }
    }



}

int decode_huffman_code()
{

}