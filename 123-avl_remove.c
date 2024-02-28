#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree
 * @value: Value to be removed
 *
 * Return: Pointer to the new root of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		avl_t *left_child = root->left;
		avl_t *right_child = root->right;
		avl_t *minimum = NULL;

		free(root);

		if (right_child == NULL)
			return (left_child);

		minimum = binary_tree_minimum(right_child);

		minimum->right = avl_remove(right_child, minimum->n);
		minimum->left = left_child;

		return (balance(minimum));
	}

	return (balance(root));
}

/**
 * binary_tree_minimum - find the minimum node in BST
 *
 * @tree: A pointer to the root node of the tree to search
 *
 * Return: A pointer to the node containing the minimum value
 */
avl_t *binary_tree_minimum(const avl_t *tree)
{
	if (!tree)
		return (NULL);

	while (tree->left)
		tree = tree->left;

	return ((avl_t *)tree);
}
