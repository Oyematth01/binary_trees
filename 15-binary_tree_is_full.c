#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    /* If a node has both children or no children */
    if ((tree->left == NULL && tree->right == NULL) ||
        (tree->left != NULL && tree->right != NULL))
    {
        /* Recursively check the left and right subtrees */
        int left_full = binary_tree_is_full(tree->left);
        int right_full = binary_tree_is_full(tree->right);

        return (left_full && right_full);
    }

    /* If a node has only one child, the tree is not full */
    return (0);
}
