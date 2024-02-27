#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @node: Apointer to the node to measure the depth of.
 *
 * Return: The depth of the node, or 0 if node is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	if (!node)
		return (0);

	return (1 + binary_tree_depth(node->parent));
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of  two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node,
 * or NULL if no common ancestor found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	const binary_tree_t *p1 = first;
	const binary_tree_t *p2 = second;

	size_t d1 = binary_tree_depth(p1);
	size_t d2 = binary_tree_depth(p2);
	int diff = d1 - d2;

	while (diff > 0)
	{
		p1 = p1->parent;
		diff--;
	}

	while (diff < 0)
	{
		p2 = p2->parent;
		diff++;
	}

	while (p1 && p2)
	{
		if (p1 == p2)
			return ((binary_tree_t *)p1);
		p1 = p1->parent;
		p2 = p2->parent;
	}

	return (NULL);
}
