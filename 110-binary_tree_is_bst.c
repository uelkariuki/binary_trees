#include "binary_trees.h"
#include <limits.h>

/**
 * valid_bst- helper function to determine if the bst is valid
 * @tree: a pointer to the root node of the tree to check
 * @minimum: the minimum value to be within the range
 * @maximum: the maximum value to be within the range
 * Return: True if valid bst, false otherwise
*/

bool valid_bst(const binary_tree_t *tree, int minimum, int maximum)
{
	if (tree == NULL)
		return (true);
	if (tree->n < minimum || tree->n > maximum)
		return (false);

	bool left = valid_bst(tree->left, minimum, tree->n - 1);
	bool right = valid_bst(tree->right, tree->n + 1, maximum);

	 /*both left and right must be true for it to be a valid bst*/
	if (left == true && right == true)
		return (true);
	return (false);


}
/**
 * binary_tree_is_bst-  function that checks if a binary tree is a
 * valid Binary Search Tree
 * @tree:  a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 *
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (valid_bst(tree, INT_MIN, INT_MAX))
		return (1);
	return (0);
}
