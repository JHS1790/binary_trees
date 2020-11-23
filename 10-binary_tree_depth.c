#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: a pointer to the node to measure the depth
 * Return: depth or 0 if NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (depth_search(tree->parent));
}

size_t depth_search(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (depth_search(tree->parent) + 1);
}
