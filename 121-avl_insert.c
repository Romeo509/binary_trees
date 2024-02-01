#include "binary_trees.h"

/**
 * avl_insert_recursive - Recursive helper function for AVL tree insertion.
 * @tree: A double pointer to the current node in the AVL tree.
 * @parent: A pointer to the parent of the current node.
 * @new: A double pointer to the newly inserted node.
 * @value: The value to be inserted.
 * Return: The current node after the insertion.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
avl_t **new, int value)
{
int balance;

if (*tree == NULL)
return (*new = binary_tree_node(parent, value));

if ((*tree)->n > value)
{
(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
if ((*tree)->left == NULL)
return (NULL);
}
else if ((*tree)->n < value)
{
(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
if ((*tree)->right == NULL)
return (NULL);
}
else
{
return (*tree);
}

balance = binary_tree_balance(*tree);

if (balance > 1 && (*tree)->left->n > value)
{
*tree = binary_tree_rotate_right(*tree);
}
else if (balance > 1 && (*tree)->left->n < value)
{
(*tree)->left = binary_tree_rotate_left((*tree)->left);
*tree = binary_tree_rotate_right(*tree);
}
else if (balance < -1 && (*tree)->right->n < value)
{
*tree = binary_tree_rotate_left(*tree);
}
else if (balance < -1 && (*tree)->right->n > value)
{
(*tree)->right = binary_tree_rotate_right((*tree)->right);
*tree = binary_tree_rotate_left(*tree);
}

return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to store in the node to be inserted.
 * Return: The inserted node, or NULL if fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
avl_t *new = NULL;

if (*tree == NULL)
{
*tree = binary_tree_node(NULL, value);
return (*tree);
}

avl_insert_recursive(tree, *tree, &new, value);

return (new);
}

