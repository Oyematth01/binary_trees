#include "binary_trees.h"

/**
 * min_value_node - Finds the node with the smallest value greater than the given node
 * @node: Pointer to the node to start from
 *
 * Return: Pointer to the node with the smallest value
 */
bst_t *min_value_node(bst_t *node)
{
    bst_t *current = node;

    while (current && current->left != NULL)
        current = current->left;

    return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where the node will be removed
 * @value: The value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *temp;

    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else
    {
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return (temp);
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return (temp);
        }

        temp = min_value_node(root->right);
        root->n = temp->n;
        root->right = bst_remove(root->right, temp->n);
    }
    return (root);
}
