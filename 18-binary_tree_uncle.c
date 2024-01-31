#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find the uncle
 *
 * Return: A pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent->parent->left && node->parent->parent->right)
	{
		if (node->parent->parent->left == node->parent)
			return (node->parent->parent->right);
		else
			return (node->parent->parent->left);
	}

	return (NULL);
}

