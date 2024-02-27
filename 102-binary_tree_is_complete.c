#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Apointer to the root node of the tree to measure the size of.
 *
 * Return: The size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer t othe root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;
	int i;
	binary_tree_t **queue, *node;
	int front = -1, rear = -1;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	queue = malloc(sizeof(binary_tree_t *) * size);

	if (!queue)
		return (0);

	queue[++rear] = (binary_tree_t *)tree;

	while (++front <= rear)
	{
		node = queue[front];
		if (!node->left)
			return (0);
		queue[++rear] = node->left;

		if (!node->right)
			return (0);
		queue[++rear] = node->right;
	}

	for (i = 0; i <= rear; i++)
		if (queue[i]->left || queue[i]->right)
			return (0);

	free(queue);
	return (1);
}
