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
    bst_t *tree;
    bst_t *node;
    int array[] = {
        98, 402, 12, 46, 128, 256, 512, 1, 128, 98
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_bst(array, n);
    if (tree)
        binary_tree_print(tree);

    node = bst_search(tree, 128);
    if (node)
        printf("Found: %d\n", node->n);
    else
        printf("Value not found\n");

    printf("Removing 128\n");
    tree = bst_remove(tree, 128);
    binary_tree_print(tree);

    printf("Removing 98\n");
    tree = bst_remove(tree, 98);
    binary_tree_print(tree);

    printf("Removing 402\n");
    tree = bst_remove(tree, 402);
    binary_tree_print(tree);

    return (0);
}
