#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: a pointer to the sibling of the node or
 * NULL if it doesn't exist or node has no parent
 *
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	parent = node->parent;
	if (parent->left != NULL && parent->right != NULL)
	{
		if (parent->left == node)
			return (parent->right);
		return (parent->left);
	}
	return (NULL);
}
