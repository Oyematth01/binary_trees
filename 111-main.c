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
    bst_t *root = NULL;
    bst_t *node;

    node = bst_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    
    node = bst_insert(&root, 402);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    
    node = bst_insert(&root, 12);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    
    node = bst_insert(&root, 46);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    
    node = bst_insert(&root, 128);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    
    node = bst_insert(&root, 256);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);
    
    node = bst_insert(&root, 512);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    node = bst_insert(&root, 1);
    printf("Inserted: %d\n", node->n);
    binary_tree_print(root);

    return (0);
}
