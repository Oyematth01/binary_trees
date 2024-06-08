#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/* Function to create a new node */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
        return (NULL);
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

/* Main function to test the BST check function */
int main(void)
{
    binary_tree_t *root = binary_tree_node(NULL, 10);
    root->left = binary_tree_node(root, 5);
    root->right = binary_tree_node(root, 20);
    root->left->left = binary_tree_node(root->left, 3);
    root->left->right = binary_tree_node(root->left, 7);
    root->right->left = binary_tree_node(root->right, 15);
    root->right->right = binary_tree_node(root->right, 25);

    printf("Is the tree a valid BST? %d\n", binary_tree_is_bst(root));

    /* Create an invalid BST */
    root->right->left->n = 5;
    printf("Is the tree a valid BST? %d\n", binary_tree_is_bst(root));

    return (0);
}
