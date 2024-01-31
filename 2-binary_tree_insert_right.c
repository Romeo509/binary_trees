#include <stdlib.h>
#include "binary_trees.h"

/**
 *binary_tree_insert_right - Inserts a node as the right child of another node.
 *@parent: Pointer to the parent node to insert the right child in.
 *@value: Value to store in the new node.
 *
 *Return: Pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* Check if parent is NULL */
	if (parent == NULL)
		return (NULL);

	/* Create a new node and check for allocation failure */
	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	/* If parent already has a right child, adjust pointers accordingly */
	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	/* Update parent's right pointer to the new node */
	parent->right = new_node;

	/* Return a pointer to the newly created node */
	return (new_node);
}
