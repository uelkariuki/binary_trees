#include "binary_trees.h"

/**
 * binary_tree_uncle- a function that finds the uncle of a node
 * @node: is a pointer to the node to find the uncle
 * Return: a pointer to the uncle node
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/*grandparent->left or grandparent->right could be uncle*/
	binary_tree_t *parent, *grandparent;
	/*if node is NULL,the parent (NULL) or grandparent (NULL) means no uncle*/
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	parent = node->parent; /*parent of the node*/
	grandparent = parent->parent; /*the parent's parent is the grandparent*/


	if (grandparent->left == parent)
		return (grandparent->right); /*one uncle*/
	return (grandparent->left); /*the other uncle*/

}
