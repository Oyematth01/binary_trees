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

/* Function to print the tree - for testing purposes */
void binary_tree_print(const binary_tree_t *tree)
{
    if (tree != NULL)
    {
        binary_tree_print(tree->left);
        printf("%d ", tree->n);
        binary_tree_print(tree->right);
    }
}

/* Main function to test the rotation */
int main(void)
{
    binary_tree_t *root = binary_tree_node(NULL, 10);
    root->right = binary_tree_node(root, 15);
    root->right->left = binary_tree_node(root->right, 12);
    root->right->right = binary_tree_node(root->right, 20);

    printf("Original tree:\n");
    binary_tree_print(root);
    printf("\n");

    root = binary_tree_rotate_left(root);

    printf("Rotated tree:\n");
    binary_tree_print(root);
    printf("\n");

    return (0);
}
