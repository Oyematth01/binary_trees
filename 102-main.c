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
    int complete;

    root = binary_tree_node(NULL, 1);
    root->left = binary_tree_node(root, 2);
    root->right = binary_tree_node(root, 3);
    root->left->left = binary_tree_node(root->left, 4);
    root->left->right = binary_tree_node(root->left, 5);
    root->right->left = binary_tree_node(root->right, 6);

    complete = binary_tree_is_complete(root);
    printf("Is the tree complete? %d\n", complete); /* Should print 1 */

    root->right->right = binary_tree_node(root->right, 7);

    complete = binary_tree_is_complete(root);
    printf("Is the tree complete? %d\n", complete); /* Should print 0 */

    return (0);
}
