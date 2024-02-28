#include "binary_trees.h"

heap_t *heap_insert(heap_t **root, int value);
heap_t *find_parent(heap_t *root);
heap_t *heapify(heap_t *node);
void swap_nodes(heap_t *a, heap_t *b);

/**
 * heap_insert - Inserts a value in Max Binary Heap
 * @root: Pointer to a pointer to the root node of the Heap to insert the value
 * Return: A pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(*root, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	parent = find_parent(*root);
	if (!parent->left)
		parent->left = new_node;
	else if (!parent->right)
		parent->right = new_node;
	else
	{
		free(new_node);
		return (NULL);
	}

	new_node->parent = parent;

	return (heapify(new_node));
}

/**
 * find_parent - Finds the parent node of a new node in a heap
 * @root: Pointer to the root node of the heap
 * @value: The value of the new node
 *
 * Return: A pointer to the patrent node
 */
heap_t *find_parent(heap_t *root)
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
		{
			queue[++rear] = temp->left;
			if (!temp->left->left || !temp->left->right)
				return (temp);
		}
		else
			return (temp);
		if (temp->right)
		{
			queue[++rear] = temp->right;
			if (!temp->right->left || !temp->right->right)
				return (temp);
		}
		else
			return (temp);
	}

	return (NULL);
}

/**
 * heapify - Moves a newly inserted node to its correct position in the heap
 * @node: The newly inserted node
 *
 * Return: A pointer to the new root of the heap
 */
heap_t *heapify(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * swap_nodes - Swaps the posititons of two in heap
 * @a: The first node
 * @b: The second node
 */
void swap_nodes(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}
