#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
    int left_height, right_height;

    if (tree == NULL)
        return (0);

    left_height = binary_tree_height(tree->left);
    right_height = binary_tree_height(tree->right);

    if (left_height > right_height)
        return (left_height + 1);
    else
        return (right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * is_bst_helper - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowed value
 * @max: Maximum allowed value
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (is_bst_helper(tree->left, min, tree->n) &&
            is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Helper function to check if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree)
{
    int balance;

    if (tree == NULL)
        return (1);

    if (!binary_tree_is_bst(tree))
        return (0);

    balance = binary_tree_balance(tree);

    if (balance > 1 || balance < -1)
        return (0);

    return (is_avl_helper(tree->left) && is_avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (is_avl_helper(tree));
}
