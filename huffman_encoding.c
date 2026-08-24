#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    char *name;
    struct node *left;
    struct node *right;
};

int create_huffman_tree(const char* str)
{
    int count[256] = {0};
    size_t total_chars = strlen(str);

    for (int i = 0; i < total_chars; i++)
    {
        count[str[i]]++;
    }

    double probs[256] = {0};

    for (int i = 0; i < 256; i++)
    {
        if (count[i] != 0)
        {
            probs[i] = (double)counts[i] / total_chars;
        }
    }

}

int decode_huffman_code()
{

}