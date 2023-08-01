#include "binary_trees.h"

/**
 * binary_tree_insert_right- a function that inserts a node as the
 * right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: is the value to store in the new node
 * Return: a pointer to the created node, or NULL on failure
 * or if parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_new_node;

	if (parent == NULL)
		return (NULL);

	right_new_node = binary_tree_node(parent, value);

	if (right_new_node == NULL)
		return (NULL);

	if (parent->right == NULL)
	{
		parent->right = right_new_node;

	}
	else
	{
		right_new_node->right = parent->right;
		right_new_node->right->parent = right_new_node;
		parent->right = right_new_node;
	}

	return (right_new_node);
}
