#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: The height of the binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is valid AVL tree
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is a valid AVL tree, otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int is_bst = binary_tree_is_bst(tree);
	size_t left_height, right_height;

	if (!is_bst)
		return (0);

	if (tree == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if ((left_height > right_height ? left_height - right_height :
				right_height - left_height) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) &&
			binary_tree_is_avl(tree->right));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is valid
 * Binary Search Tree (BST)
 * @tree: Pointer to the root node of the binary tree
 *
 * Return: 1 if the binary tree is valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->left != NULL && tree->left->n >= tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n <= tree->n)
		return (0);

	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}
