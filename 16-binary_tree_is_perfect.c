#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the binary tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + (binary_tree_height(tree->left), binary_tree_height(tree->right)
		? binary_tree_height(tree->left) : binary_tree_height(tree->right)));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If the tree is perfect - 1, otherwise - 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = binary_tree_height(tree);
	int size = binary_tree_size(tree);

	if (size == 0 || height == 0)
		return (0);

	if ((1 << height) - 1 == size)
		return (1);

	return (0);
}
