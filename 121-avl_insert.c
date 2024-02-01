#include "binary_trees.h"

/**
 * avl_recursive_insert - Recursively inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @parent: Pointer to the parent node.
 * @new_node: Double pointer to the newly inserted node.
 * @value: The value to store in the node to be inserted.
 * Return: The current node after the insertion.
 */
avl_t *avl_recursive_insert(avl_t **tree, avl_t *parent,
avl_t **new_node, int value)
{
	int bf;

	if (!*tree)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_recursive_insert(&(*tree)->left, *tree, new_node, value);
		if (!(*tree)->left)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_recursive_insert(&(*tree)->right,
		*tree, new_node, value);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);

	bf = binary_tree_balance(*tree);

	if (bf > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bf > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bf < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bf < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: The value to store in the node to be inserted.
 * Return: The inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	avl_recursive_insert(tree, *tree, &new_node, value);

	return (new_node);
}

