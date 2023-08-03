#include "binary_trees.h"

/**
 * binary_tree_rotate_left- function that performs a left-rotation on a
 * binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 *
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rotated_tree;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	rotated_tree = tree->right;
	tree->right = rotated_tree->left;

	if (rotated_tree->left != NULL)
		rotated_tree->left->parent = tree;

	rotated_tree->left = tree;
	rotated_tree->parent = tree->parent;

	tree->parent = rotated_tree;

	return (rotated_tree);
}
