#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Helper function to create a new binary tree node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);
    new_node->n = value;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->parent = parent;
    return (new_node);
}

int main(void)
{
    binary_tree_t *root;
    binary_tree_t *ancestor;

    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->left->right = binary_tree_node(root->left, 5);
    root->right->left = binary_tree_node(root->right, 6);
    root->right->right = binary_tree_node(root->right, 7);
    root->left->left->left = binary_tree_node(root->left->left, 8);
    root->left->left->right = binary_tree_node(root->left->left, 9);

    ancestor = binary_trees_ancestor(root->left->left->left, root->left->left->right);
    if (ancestor)
        printf("Lowest common ancestor of %d and %d is %d\n", root->left->left->left->n, root->left->left->right->n, ancestor->n);
    else
        printf("No common ancestor found\n");

    return (0);
}
