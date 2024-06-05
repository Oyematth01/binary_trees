#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;
    binary_tree_t *node;

    /* Create the root node */
    root = binary_tree_node(NULL, 98);
    if (root == NULL)
    {
        fprintf(stderr, "Failed to create root node\n");
        return (1);
    }
    printf("Root node created: %d\n", root->n);

    /* Create a left child node */
    node = binary_tree_node(root, 42);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to create left child node\n");
        free(root);
        return (1);
    }
    root->left = node;
    printf("Left child node created: %d\n", node->n);

    /* Create a right child node */
    node = binary_tree_node(root, 128);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to create right child node\n");
        free(root->left);
        free(root);
        return (1);
    }
    root->right = node;
    printf("Right child node created: %d\n", node->n);

    /* Clean up memory */
    free(root->left);
    free(root->right);
    free(root);

    return (0);
}
