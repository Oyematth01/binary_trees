#include <stdio.h>
#include "binary_trees.h"

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    avl_t *root;
    avl_t *node;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->left = binary_tree_node(root->left, 8);
    root->left->right = binary_tree_node(root->left, 18);
    root->right->right = binary_tree_node(root->right, 256);

    binary_tree_print(root);

    if (binary_tree_is_avl(root))
        printf("The tree is a valid AVL tree\n");
    else
        printf("The tree is not a valid AVL tree\n");

    return (0);
}
