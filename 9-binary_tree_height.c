#include "binary_trees.h"
/**
 * find_height - measures the height of a binary tree recursively
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the node passed
*/
size_t find_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (-1);

	left_height = find_height(tree->left);
	right_height = find_height(tree->right);
	if (left_height >= right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
/**
 * binary_tree_height - calls find_height to calculate height
 * of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (find_height(tree));
}
