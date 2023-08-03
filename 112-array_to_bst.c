#include "binary_trees.h"


/**
 * array_to_bst- a function that builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created BST, or NULL on failure
 *
*/

bst_t *array_to_bst(int *array, size_t size)
{
	size_t q;
	bst_t *tree = NULL;


	if (array == NULL)
		return (NULL);

	if (size == 0)
		return (NULL);

	for (q = 0; q < size; q++)
	{
		bst_insert(&tree, array[q]);

	}
	return (tree);
}
