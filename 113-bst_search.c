#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: The value to search in the tree
 *
 * Return: Pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (tree == NULL)
        return (NULL);

    while (tree != NULL)
    {
        if (value == tree->n)
            return ((bst_t *)tree);
        else if (value < tree->n)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return (NULL);
}

