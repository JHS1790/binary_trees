#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if perfect, 0 if not.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int nodes = binary_tree_all_nodes(tree);
	int height = recursiveSearch(tree) - 1;

	if (nodes == _pow_recursion(2, height + 1) - 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_all_nodes - counts all nodes
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of tree in size_t
 */
size_t binary_tree_all_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
	{
		return (
			binary_tree_all_nodes(tree->left) +
			binary_tree_all_nodes(tree->right) +
			1
		);
	}
	else if (tree->left != NULL)
	{
		return (
			binary_tree_all_nodes(tree->left) +
			1
		);
	}
	else if (tree->right != NULL)
	{
		return (
			binary_tree_all_nodes(tree->right) +
			1
		);
	}
	else
		return (1);
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

/**
 * _pow_recursion - raises to the power
 * @x: number to raise
 * @y: power
 * Return: RAISED, HALLELUJAH
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	y--;
	return (x * _pow_recursion(x, y));
}
