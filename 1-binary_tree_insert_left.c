#include "binary_trees.h"
/**
* binary_tree_insert_left - inserts a node as the left-child of another node
* @parent: pointer to the node to insert the left-child in
* @value: value to store in the new node
* Return: pointer to the created node or NULL on failure
* or if parent is NULL
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *left;
	int old_left;

	if (parent == NULL)
		return (NULL);
	new_node = binary_tree_node(parent, value);
	if (new_node == NULL)
		return (NULL);
	if (parent->left != NULL)
	{
		old_left = parent->left->n;
		parent->left = new_node;
		left = binary_tree_node(new_node, old_left);
		if (left == NULL)
			return (NULL);
		new_node->left = left;
	}
	else
		parent->left = new_node;

	return (new_node);
}
