#include "binary_trees.h"

/**
 * create_new_node - Creates a new node for AVL tree
 * @value: The value to store in the node
 * Return: A pointer to the created node, or NULL on failure
 */
static avl_t *create_new_node(int value)
{
	avl_t *node = binary_tree_node(NULL, value);

	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * insert_left - Recursively inserts a value to the left of a node
 * @tree: The tree to insert the value into
 * @value: The value to insert
 * Return: A pointer to the newly inserted node, or NULL on failure
 */
static avl_t *insert_left(avl_t **tree, int value)
{
	avl_t *node;

	if (*tree == NULL)
		return (NULL);

	node = avl_insert(&((*tree)->left), value);
	if (!node)
		return (NULL);

	if (binary_tree_balance((*tree)->left) - binary_tree_balance
			((*tree)->right) == 2)
	{
		if (value < (*tree)->left->n)
			*tree = binary_tree_rotate_right(*tree);
		else
		{
			(*tree)->left = binary_tree_rotate_left((*tree)->left);
			*tree = binary_tree_rotate_right(*tree);
		}
	}
	return (node);
}

/**
 * insert_right - Recursively inserts a value to the right of a node
 * @tree: The tree to insert the value into
 * @value: The value to insert
 * Return: A pointer to the newly inserted node, or NULL on failure
 */
static avl_t *insert_right(avl_t **tree, int value)
{
	avl_t *node;

	if (*tree == NULL)
		return (NULL);

	node = avl_insert(&((*tree)->right), value);
	if (!node)
		return (NULL);

	if (binary_tree_balance((*tree)->right) - binary_tree_balance
			((*tree)->left) == 2)
	{
		if (value > (*tree)->right->n)
			*tree = binary_tree_rotate_left(*tree);
		else
		{
			(*tree)->right =  binary_tree_rotate_right((*tree)->right);
			*tree = binary_tree_rotate_left(*tree);
		}
	}
	return (node);
}

/**
 * avl_insert - Inserts a value in an AVL Tree
 *
 * @tree: Double pointer to the root node of the AVL tree for inserting
 * the value
 * @value: The value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node;

	if (*tree == NULL)
	{
		*tree = create_new_node(value);
		return (*tree);
	}

	if (value < (*tree)->n)
		node = insert_left(tree, value);
	else if (value > (*tree)->n)
		node = insert_right(tree, value);
	else
		return (NULL);
	return (node);
}
