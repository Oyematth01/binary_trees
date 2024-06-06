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
    binary_tree_t *left;
    binary_tree_t *right;

    /* Create the root node */
    root = binary_tree_node(NULL, 98);
    if (root == NULL)
    {
        fprintf(stderr, "Failed to create root node\n");
        return (1);
    }
    printf("Root node created: %d\n", root->n);

    /* Insert a left child node */
    left = binary_tree_insert_left(root, 42);
    if (left == NULL)
    {
        fprintf(stderr, "Failed to insert left child node\n");
        binary_tree_delete(root);
        return (1);
    }
    printf("Left child node inserted: %d\n", left->n);

    /* Insert a right child node */
    right = binary_tree_insert_right(root, 84);
    if (right == NULL)
    {
        fprintf(stderr, "Failed to insert right child node\n");
        binary_tree_delete(root);
        return (1);
    }
    printf("Right child node inserted: %d\n", right->n);

    /* Delete the entire tree */
    binary_tree_delete(root);
    printf("Binary tree deleted\n");

    return (0);
}
