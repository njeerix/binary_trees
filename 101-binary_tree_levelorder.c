#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = NULL;
	size_t front = 0, rear = 0;
	size_t size = 0;

	if (!tree || !func)
		return;

	size = binary_tree_height(tree);
	queue = malloc(sizeof(binary_tree_t *) * size);
	if (!queue)
		return;

	queue[rear] = (binary_tree_t *)tree;
	rear = (rear + 1) % size;

	while (front != rear)
	{
		binary_tree_t *tmp = queue[front];

		front = (front + 1) % size;
		func(tmp->n);

		if (tmp->left)
		{
			queue[rear] = tmp->left;
			rear = (rear + 1) % size;
		}
		if (tmp->right)
		{
			queue[rear] = tmp->right;
			rear = (rear + 1) % size;
		}
	}

	free(queue);
}

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree, or 0 if tree is Null.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
