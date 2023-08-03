#include "binary_trees.h"
#include "9-binary_tree_height.c"
#include "110-binary_tree_is_bst.c"

/**
 * balanced_tree- helper function to help know if tree is balanced
 * @tree: a pointer to the root node of the tree to check
 * Return: true if balanced, otherwise false
*/

bool balanced_tree(const avl_t *tree)
{
	int l_height, r_height, balance_factor;

	if (tree == NULL)
		return (true);

	l_height = find_height(tree->left);
	r_height = find_height(tree->right);
	balance_factor = l_height - r_height;
	/*The difference between heights of left and right subtrees cannot be*/
	/*more than one*/
	if (balance_factor > 1 || balance_factor < -1)
		return (false);
	return (balanced_tree(tree->left) && balanced_tree(tree->right));

}

/**
 *binary_tree_is_avl- function that checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 *
*/
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (!valid_bst(tree, INT_MIN, INT_MAX))
		return (0);
	if (!balanced_tree(tree))
		return (0);

	return (1);
}
