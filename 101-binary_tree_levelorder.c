#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * present_level- function to find the present level to
 * to help in traversing all the nodes
 * @tree: a pointer to the root node of the tree to traverse
 * @level: the level we are currently at
 * @func: a pointer to a function to call for each node.
 *
*/
void present_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		present_level(tree->left, level - 1, func);
		present_level(tree->right, level - 1, func);

	}
}
/**
 * binary_tree_levelorder- a function that goes through a binary tree
 * using level-order traversal
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height, q;

	if (tree == NULL || func == NULL)
		return;

	height = find_height(tree) + 1;


	for (q = 1; q <= height; q++)
		present_level(tree, q, func);
}
