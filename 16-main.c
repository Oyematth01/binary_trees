#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Helper function to create a new binary tree node */
binary_tree_t *binary_tree_node(int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

int main(void)
{
    binary_tree_t *root;
    int perfect;

    root = binary_tree_node(1);
    root->left = binary_tree_node(2);
    root->right = binary_tree_node(3);
    root->left->left = binary_tree_node(4);
    root->left->right = binary_tree_node(5);
    root->right->left = binary_tree_node(6);
    root->right->right = binary_tree_node(7);

    perfect = binary_tree_is_perfect(root);
    printf("Is the tree perfect? %d\n", perfect);

    return (0);
}
