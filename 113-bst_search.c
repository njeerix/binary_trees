#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search for in the tree
 *
 * Return: Pointer to the node containing a value equals to value, or
 * NULL if not found or tree is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
