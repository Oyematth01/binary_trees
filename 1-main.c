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

    /* Insert a left child node */
    node = binary_tree_insert_left(root, 42);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to insert left child node\n");
        free(root);
        return (1);
    }
    printf("Left child node inserted: %d\n", node->n);

    /* Insert another left child node to test replacement */
    node = binary_tree_insert_left(root, 21);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to insert left child node\n");
        free(root->left);
        free(root);
        return (1);
    }
    printf("Left child node inserted: %d\n", node->n);
    printf("New left child's left child node: %d\n", node->left->n);

    /* Clean up memory */
    free(node->left);
    free(root->left);
    free(root);

    return (0);
}
