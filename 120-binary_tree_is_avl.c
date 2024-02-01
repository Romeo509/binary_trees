#include "binary_trees.h"
#include <limits.h>

/**
 * max - Finds the maximum of two integers.
 * @a: First integer.
 * @b: Second integer.
 * Return: The maximum of a and b.
 */
int max(int a, int b)
{
return (a > b ? a : b);
}

/**
 * height - Computes the height of a binary tree.
 * @tree: Pointer to the root of the tree.
 * Return: The height of the tree.
 */
size_t height(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * bal_avl - Auxiliar function to compare each subtree if its AVL.
 * @tree: node that points to the tree to check.
 * @lower: lower limit of the valid range.
 * @high: upper limit of the valid range.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
size_t height_l, height_r, balancer;

if (tree != NULL)
{
if (tree->n > high || tree->n < lower)
{
return (0);
}

height_l = height(tree->left);
height_r = height(tree->right);
balancer = height_l > height_r ? height_l - height_r : height_r - height_l;

if (balancer > 1)
{
return (0);
}

return (bal_avl(tree->left, lower, tree->n - 1) &&
bal_avl(tree->right, tree->n + 1, high));
}

return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree.
 * @tree: node that points to the tree to check.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}

return (bal_avl(tree, INT_MIN, INT_MAX));
}

