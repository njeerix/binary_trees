#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 *
 * Return: A pointer to the root node of the created AVL tree, or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		avl_t *node = avl_insert(&root, array[i]);

		if (!node)
			return (NULL);
	}

	return (root);
}
