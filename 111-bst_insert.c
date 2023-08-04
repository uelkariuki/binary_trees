#include "binary_trees.h"
/**
 * free_node - frees a node
 * @node: node to free
 * Return: NULL after freeing
*/
void *free_node(bst_t *node)
{
	free(node);
	return (NULL);
}
/**
 * bst_insert - insert into a binary search tree
 * @tree: double pointer to the tree
 * @value: value of the node to insert
 *
 * Return: pointer to the inserted node
*/

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *temp, *parent = NULL;

	new_node = binary_tree_node(NULL, value);
	if (tree == NULL || *tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	else
	{
		temp = *tree;
		while (temp != NULL)
		{
			parent = temp;
			if (value < parent->n)
			{
				temp = temp->left;
				if (temp == NULL)
				{
					parent->left = new_node;
					new_node->parent = parent;
					return (new_node);
				}
			}
			else if (value > parent->n)
			{
				temp = temp->right;

				if (temp == NULL)
				{
					parent->right = new_node;
					new_node->parent = parent;
					return (new_node);
				}
			}
			else
				return (free_node(new_node));
		}
	}
	return (NULL);
}
