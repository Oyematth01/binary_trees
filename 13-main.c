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
    binary_tree_t *left_left;
    binary_tree_t *left_right;

    /* Create the root node */
    root = binary_tree_node(NULL, 98);
    if (root == NULL)
    {
        fprintf(stderr, "Failed to create root node\n");
        return (1);
    }

    /* Insert left and right children */
    left = binary_tree_insert_left(root, 42);
    right = binary_tree_insert_right(root, 84);
    left_left = binary_tree_insert_left(left, 21);
    left_right = binary_tree_insert_right(left, 36);

    /* Count nodes with at least 1 child */
    printf("Number of nodes with at least 1 child: %lu\n", binary_tree_nodes(root));

    /* Delete the entire tree */
    binary_tree_delete(root);

    return (0);
}
