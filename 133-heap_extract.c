#include "binary_trees.h"

/**
 * heap_extract - Removes the root node from a Max Binary Heap
 * @root: Pointer to a pointer to the root node of the heap
 *
 * Return: The value of the removed root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *prev_node;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	last_node = find_last_node(*root);
	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	swap_nodes(*root, last_node);

	if (last_node->parent->right == last_node)
		last_node->parent->right = NULL;
	else
		last_node->parent->left = NULL;

	prev_node = last_node->parent;
	free(last_node);

	prev_node = balance(prev_node);

	return (value);
}

/**
 * find_last_node - Finds the last level-order node in a heap
 * @root: Pointer to the root node of the heap
 *
 * Return: A pointer to the last node, or NULL if root is NULL
 */
heap_t *find_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = -1;
	heap_t *temp;

	if (!root)
		return (NULL);

	queue[++rear] = root;
	while (front <= rear)
	{
		temp = queue[front++];
		if (temp->left)
			queue[++rear] = temp->left;
		if (temp->right)
			queue[++rear] = temp->right;
	}

	return (temp);
}

/**
 * swap_nodes - Swaps two nodes in abinary tree
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}
/**
 * balance - Balances a binary heap
 * @root: Pointer to the root node of the heap
 *
 * Return: The new root of the heap
 */
heap_t *balance(heap_t *root)
{
	heap_t *largest = root, *left = root->left, *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;
	if (largest != root)
	{
		swap_nodes(root, largest);
		return (balance(largest));
	}
	return (root);
}
