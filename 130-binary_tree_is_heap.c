#include "binary_trees.h"

/**
 * is_heap- helper function to help know if is heap
 * @tree: a pointer to the root node of the tree to check
 * Return: True if is heap otherwise false
 *
*/
bool is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (true);

	if (tree->left && tree->left->n >= tree->n)
		return (false);

	if (tree->right && tree->right->n <= tree->n)
		return (false);


	return (is_heap(tree->left) && is_heap(tree->right));
}
/**
 * binary_tree_is_heap- function that checks if a binary tree is a valid
 * Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 *
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{

	if (tree == NULL)
		return (0);

	return (is_heap(tree));

}
