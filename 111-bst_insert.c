#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *new_node, *current, *parent = NULL;

    if (tree == NULL)
        return (NULL);

    current = *tree;
    while (current != NULL)
    {
        parent = current;
        if (value < current->n)
            current = current->left;
        else if (value > current->n)
            current = current->right;
        else
            return (NULL); /* Value is already in the tree, ignore it */
    }

    new_node = malloc(sizeof(bst_t));
    if (new_node == NULL)
        return (NULL);
    
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;

    if (parent == NULL)
        *tree = new_node; /* Tree was empty, new node is the root */
    else if (value < parent->n)
        parent->left = new_node;
    else
        parent->right = new_node;

    return (new_node);
}
