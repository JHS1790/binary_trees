#include "binary_trees.h"

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: a pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *nav_node = tree;

	while (tree != NULL)
	{
		while (nav_node->left != NULL)
			nav_node = nav_node->left;
		while (nav_node->right != NULL)
			nav_node = nav_node->right;
		if (nav_node->left == NULL && nav_node->right == NULL)
		{
			if (nav_node != tree)
			{
				if (nav_node->parent->left == nav_node)
					nav_node->parent->left = NULL;
				if (nav_node->parent->right == nav_node)
					nav_node->parent->right = NULL;
			}
			free (nav_node);
			if (nav_node == tree)
				tree = NULL;
			else
				nav_node = tree;
		}
	}
}
