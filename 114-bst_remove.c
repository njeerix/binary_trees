#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search for in the tree
 *
 * Return: Pointer to the node containing a value equals to value,
 * or NULL if not found or tree is NULL.
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

/**
 * bst_find_successor - Finds the in-order successor of a node in a BST
 * @root: Pointer to the root node of the BST
 *
 * Return: Pointer to the in-order successor node
 */
bst_t *bst_find_successor(bst_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST)
 * @root: Pointer to the root node of the BST where you will remove a node
 * @value: Value to remove in the tree
 *
 * Return: Pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp = NULL;

	if (root == NULL)
		return (root);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}
		else
		{
			tmp = bst_find_successor(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}

	return (root);
}
