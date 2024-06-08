#include "binary_trees.h"
#include <stdlib.h>

/**
 * struct queue_node_s - Node of a queue
 * @node: Pointer to a binary tree node
 * @next: Pointer to the next queue node
 */
typedef struct queue_node_s
{
    const binary_tree_t *node;
    struct queue_node_s *next;
} queue_node_t;

/**
 * enqueue - Adds a node to the end of the queue
 * @queue: Double pointer to the queue
 * @node: Pointer to the binary tree node to add
 */
void enqueue(queue_node_t **queue, const binary_tree_t *node)
{
    queue_node_t *new_node, *temp;

    if (!node)
        return;

    new_node = malloc(sizeof(queue_node_t));
    if (!new_node)
        return;

    new_node->node = node;
    new_node->next = NULL;

    if (*queue == NULL)
    {
        *queue = new_node;
    }
    else
    {
        temp = *queue;
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
}

/**
 * dequeue - Removes a node from the front of the queue
 * @queue: Double pointer to the queue
 * Return: Pointer to the binary tree node removed from the queue
 */
const binary_tree_t *dequeue(queue_node_t **queue)
{
    queue_node_t *temp;
    const binary_tree_t *node;

    if (!queue || !*queue)
        return (NULL);

    temp = *queue;
    node = temp->node;
    *queue = (*queue)->next;
    free(temp);

    return (node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    queue_node_t *queue = NULL;
    const binary_tree_t *current;
    int flag = 0;

    if (!tree)
        return (0);

    enqueue(&queue, tree);
    while (queue)
    {
        current = dequeue(&queue);

        if (current->left)
        {
            if (flag)
                return (0);
            enqueue(&queue, current->left);
        }
        else
        {
            flag = 1;
        }

        if (current->right)
        {
            if (flag)
                return (0);
            enqueue(&queue, current->right);
        }
        else
        {
            flag = 1;
        }
    }
    return (1);
}
