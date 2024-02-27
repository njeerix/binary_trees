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
	if (!tree)
		return (0);

	size_t size = binary_tree_size(tree);
	size_t i = 0;

	while (tree)
	{
		if (!tree->left && tree->right)
			return (0);
		if (i >= size)
			return (0);
		if (!tree->left || !tree->right)
			i++;
		if (tree->left)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (1);
}
