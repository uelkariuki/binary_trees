#include "binary_trees.h"
/**
 * lowest_common_ancestor - finds the lowest common ancestor of two nodes
 * @root: the parent root of the binary tree
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the least common ancestor
*/
binary_tree_t *lowest_common_ancestor(binary_tree_t *root,
const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *left_ancestor, *right_ancestor;

	if (root == NULL || root == first || root == second)
		return (root);

	first = (binary_tree_t *)first;
	second = (binary_tree_t *)second;
	left_ancestor = lowest_common_ancestor(root->left, first,
	second);
	right_ancestor = lowest_common_ancestor(root->right, first,
	second);

	if (left_ancestor && right_ancestor)
		return (root);

	return (left_ancestor ? left_ancestor : right_ancestor);
}
/**
 * find_root - finds the root node of a binary tree
 * @node: pointer to the node
 *
 * Return: parent node(root) of the binary tree
*/
binary_tree_t *find_root(const binary_tree_t *node)
{
	binary_tree_t *temp, *curr;

	temp = NULL;
	curr = (binary_tree_t *) node;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->parent;
	}
	return (temp);
}
/**
 * binary_trees_ancestor -  finds the lowest common ancestor of two nodes
 * @first:	 a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *root_first, *root_second;

	root_first = find_root(first);
	root_second = find_root(second);
	if (root_first != root_second)
		return (NULL);
	return (lowest_common_ancestor(root_first, first,
	second));
}
