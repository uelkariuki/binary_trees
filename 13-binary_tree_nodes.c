#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: 0 if tree is NULL or number of nodes with
 * at least one child in the tree
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count_left = 0, count_right = 0, count = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
	{
		count_left = binary_tree_nodes(tree->left);
		count_right = binary_tree_nodes(tree->right);
		count++;
	}
	return (count_left + count_right + count);
}
