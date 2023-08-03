#include "binary_trees.h"

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
