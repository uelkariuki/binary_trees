#include "binary_trees.h"
#include "9-binary_tree_height.c"

/**
 * binary_tree_balance- a function that measures the balance factor of a
 * binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: the balance factor of a binary tree
 *
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_factor;

	if (tree == NULL)
		return (0);

	balance_factor = find_height(tree->left) - find_height(tree->right);

	return (balance_factor);


}
