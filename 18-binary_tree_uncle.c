#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree
 * @tree: Pointer to the root node of the tree to measure the depth
 * Return: Depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    while (tree)
    {
        depth++;
        tree = tree->left;
    }
    return (depth);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * @depth: The depth of the tree
 * @level: The current level in the tree
 * Return: 1 if perfect, otherwise 0
 */
int is_perfect(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (!tree)
        return (0);

    if (!tree->left && !tree->right)
        return (depth == level + 1);

    if (!tree->left || !tree->right)
        return (0);

    return (is_perfect(tree->left, depth, level + 1) &&
            is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t depth;

    if (!tree)
        return (0);

    depth = binary_tree_depth(tree);

    return (is_perfect(tree, depth, 0));
}

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: Pointer to the sibling node, or NULL if no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (!node || !node->parent)
        return (NULL);

    if (node == node->parent->left)
        return (node->parent->right);
    else if (node == node->parent->right)
        return (node->parent->left);

    return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 * Return: Pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (!node || !node->parent || !node->parent->parent)
        return (NULL);

    return (binary_tree_sibling(node->parent));
}
