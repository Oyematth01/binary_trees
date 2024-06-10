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
    binary_tree_t *root;
    int bst;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 128);
    root->left->right = binary_tree_node(root->left, 54);
    root->right->right = binary_tree_node(root->right, 402);
    root->left->left = binary_tree_node(root->left, 10);

    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d a BST: %d\n", root->n, bst);

    root->left->right->right = binary_tree_node(root->left->right, 130);
    binary_tree_print(root);
    bst = binary_tree_is_bst(root);
    printf("Is %d a BST: %d\n", root->n, bst);

    return (0);
}
