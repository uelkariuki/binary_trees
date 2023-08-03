#include "binary_trees.h"

/**
 * bst_remove- a function that removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree after removing the
 * desired value
 *
*/
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	if (value < root->n) /*if value less delete from the left*/
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else /*when the node to be deleted is found*/
	{
		if (root->left == NULL) /*if node to be deleted has only one child*/
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		/*if the node to be removed has two children*/
		temp = root->right;
		while (temp && temp->right != NULL)
			temp = temp->left;
		/*found the in-order successor, replace value of to be removed node*/
		/*with the value in the in-order successor*/
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n); /*remove the node*/
	}
	return (root);






}
