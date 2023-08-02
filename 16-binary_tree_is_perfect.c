#include "binary_trees.h"
#include <stdbool.h>


/**
 * maximum- helper function to know the maximum value
 * @i: integer i
 * @j: integer j
 * Return: maximum of the two values
 *
*/
int maximum(int i, int j)
{
	if (i > j)
		return (1);
	return (j);
}

/**
 * depth- helper function to determine the depth of the binary tree
 * @tree: is a pointer to the root node of the tree to check
 * Return: the maximum depth of the binary tree
*/
int depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);

	return (maximum(depth(tree->left), depth(tree->right)) + 1);
}

/**
 * is_perfect- recursive function to determine if the binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * @depth: the depth of the binary tree
 * @level: the level at which to start the check
 * Return: True if the binary tree is perfect, otherwise False
*/
bool is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (true);

	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);

	if (tree->left == NULL || tree->right == NULL)
		return (false);

	return (is_perfect(tree->left, depth, level + 1) &&
			is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect- function that checks if a binary tree is perfect
 * @tree: is a pointer to the root node of the tree to check
 * Return: 1 if binary tree is perfect, otherwise 0
 *
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int real_depth;

	if (tree == NULL)
		return (0);
	real_depth = depth(tree);
	return (is_perfect(tree, real_depth, 0));

}
