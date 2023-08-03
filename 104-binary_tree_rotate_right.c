#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotates a binary tree to the right
 * @tree: pointer to the root of the tree
 *
 * Return: pointer to the flipped tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rotated_tree;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	rotated_tree = tree->left;
	tree->left = rotated_tree->right;
	if (tree->left != NULL)
		tree->left->parent = tree;
	rotated_tree->right = tree;
	rotated_tree->parent = tree->parent;
	tree->parent = rotated_tree;

	return (rotated_tree);
}
