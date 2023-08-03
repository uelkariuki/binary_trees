#include "binary_trees.h"
/**
 * bst_search - searches for a node in a tree
 * @tree: pointer to the root of the tree
 * @value: value of the node to look for
 *
 * Return: pointer to the node if found or
 * NULL otherwise
*/
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *current = (bst_t *)tree;

	if (tree == NULL)
		return (NULL);

	while (current->n != value)
	{
		if (current != NULL)
		{
			if (value > current->n)
				current = current->right;
			else
				current = current->left;
			if (current == NULL)
				return (NULL);
		}

	}
	return (current);
}
