#include "binary_trees.h"
/**
 * count_nodes - counts the number of nodes in a tree
 * @root: pointer to the root of the tree
 *
 * Return: number of nodes
*/
int count_nodes(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}
/**
 * check_complete - checks if a binary tree is complete
 * @root: pointer to the root of the tree
 * @index: index of the tree
 * @count: number of nodes int the tree
 * Return: 1 if complete, 0 if not
*/
int check_complete(const binary_tree_t *root, int index, int count)
{
	if (root == NULL)
		return (1);

	if (index >= count)
		return (0);

	return (check_complete(root->left, 2 * index + 1, count) &&
	check_complete(root->right, 2 * index + 2, count));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root of the tree
 * Return: 1 if complete, 0 if not or if tree is NULL
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int count = 0;

	if (tree == NULL)
		return (0);

	count = count_nodes(tree);
	return (check_complete(tree, 0, count));
}
