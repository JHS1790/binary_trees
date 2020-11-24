#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: height but we're doing that weird 0 thing
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (recursiveSearch(tree) - 1);
}

/**
 * recursiveSearch - recursive function to find height
 * @tree: current working node
 * Return: actual height
 */
size_t recursiveSearch(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (
		findMax(
			recursiveSearch(tree->left),
			recursiveSearch(tree->right)
			) + 1
		);
}

/**
 * findMax - find the bigger of two numbers
 * @a: first number
 * @b: second number
 * Return: the larger of the two
 */
size_t findMax(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}
