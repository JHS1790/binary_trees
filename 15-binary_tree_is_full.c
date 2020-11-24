#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if full, 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t nodes = binary_tree_nodes(tree);
	size_t leaves = binary_tree_leaves(tree);

	if (leaves == nodes + 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of tree in size_t
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (
		binary_tree_leaves(tree->left) +
		binary_tree_leaves(tree->right)
	);
}

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: size of tree in size_t
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
	{
		return (
			binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right) +
			1
		);
	}
	else if (tree->left != NULL)
	{
		return (
			binary_tree_nodes(tree->left) +
			1
		);
	}
	else if (tree->right != NULL)
	{
		return (
			binary_tree_nodes(tree->right) +
			1
		);
	}
	else
		return (0);
}
