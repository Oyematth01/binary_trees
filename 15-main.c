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
    binary_tree_t *right_right;

    /* Create the root node */
    root = binary_tree_node(NULL, 98);
    if (root == NULL)
    {
        fprintf(stderr, "Failed to create root node\n");
        return (1);
    }

    /* Insert left and right children */
    left = binary_tree_insert_left(root, 12);
    right = binary_tree_insert_right(root, 128);
    binary_tree_insert_left(left, 10);
    binary_tree_insert_right(left, 54);
    right_right = binary_tree_insert_right(right, 402);

    /* Print the tree (optional for debugging) */
    printf("       .-------(%03d)--.\n", root->n);
    printf("  .--(%03d)--.       (%03d)--.\n", left->n, right->n);
    printf("(%03d)     (%03d)          (%03d)\n", left->left->n, left->right->n, right_right->n);

    /* Check if the nodes are full */
    printf("Is %d full: %d\n", root->n, binary_tree_is_full(root));
    printf("Is %d full: %d\n", left->n, binary_tree_is_full(left));
    printf("Is %d full: %d\n", right->n, binary_tree_is_full(right));

    /* Delete the entire tree */
    binary_tree_delete(root);

    return (0);
}
