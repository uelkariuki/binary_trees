#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * (full is when every node has either 0 or 2 child nodes)
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if full, or 0 if not
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if ((tree->left) && (tree->right))
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}
