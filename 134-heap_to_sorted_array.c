#include "binary_trees.h"

/**
 * tree_size - function measures the sum of
 * heights of a binary tree
 * @tree: pointer to the root node
 *
 * Return: height or 0
 */
size_t tree_size(const binary_tree_t *tree)
{
    size_t height_l = 0;
    size_t height_r = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_l = 1 + tree_size(tree->left);

    if (tree->right)
        height_r = 1 + tree_size(tree->right);

    return (height_l + height_r);
}

/**
 * heap_to_sorted_array - binary heap converstion
 *
 * @heap: pointer
 * @size: address for storage
 *
 * Return: array
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int i, *array = NULL;

    if (!heap || !size)
        return (NULL);

    *size = tree_size(heap) + 1;

    array = malloc(sizeof(int) * (*size));

    if (!array)
        return (NULL);

    for (i = 0; heap; i++)
        array[i] = heap_extract(&heap);

    return (array);
}

