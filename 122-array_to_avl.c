#include "binary_trees.h"

/**
 * array_to_avl- function that builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return:  a pointer to the root node of the created AVL tree, or
 * NULL on failure
 *
*/
avl_t *array_to_avl(int *array, size_t size)
{
	size_t q;
	avl_t *tree = NULL;


	if (array == NULL)
		return (NULL);

	if (size == 0)
		return (NULL);

	for (q = 0; q < size; q++)
	{
		avl_insert(&tree, array[q]);

	}
	return (tree);


}
