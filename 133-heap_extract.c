#include "binary_trees.h"
#include <stdlib.h>

/**
 * tree_height - Measure the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The height of the tree or 0 if the tree is NULL.
 */
size_t tree_height(const heap_t *tree)
{
    size_t height_l = 0, height_r = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_l = 1 + tree_height(tree->left);

    if (tree->right)
        height_r = 1 + tree_height(tree->right);

    return ((height_l > height_r) ? height_l : height_r);
}

/**
 * tree_size_h - Measure the sum of heights of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The sum of heights or 0 if the tree is NULL.
 */
size_t tree_size_h(const binary_tree_t *tree)
{
    size_t height_l = 0, height_r = 0;

    if (!tree)
        return (0);

    if (tree->left)
        height_l = 1 + tree_size_h(tree->left);

    if (tree->right)
        height_r = 1 + tree_size_h(tree->right);

    return (height_l + height_r);
}

/**
 * _preorder - Traverse a binary tree using pre-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @node: Will be the last node in the traversal.
 * @height: The height of the tree.
 *
 * Return: No return value.
 */
void _preorder(heap_t *tree, heap_t **node, size_t height)
{
    if (!tree)
        return;

    if (!height)
        *node = tree;
    height--;

    _preorder(tree->left, node, height);
    _preorder(tree->right, node, height);
}

/**
 * heapify - Heapify a Max Binary Heap.
 * @root: A pointer to the binary heap.
 *
 * Return: No return value.
 */
void heapify(heap_t *root)
{
    int value;
    heap_t *tmp1, *tmp2;

    if (!root)
        return;

    tmp1 = root;

    while (1)
    {
        if (!tmp1->left)
            break;
        if (!tmp1->right)
            tmp2 = tmp1->left;
        else
        {
            tmp2 = (tmp1->left->n > tmp1->right->n) ? tmp1->left : tmp1->right;
        }
        if (tmp1->n > tmp2->n)
            break;
        value = tmp1->n;
        tmp1->n = tmp2->n;
        tmp2->n = value;
        tmp1 = tmp2;
    }
}

/**
 * heap_extract - Extract the root node from a Max Binary Heap.
 * @root: A double pointer to the heap root.
 *
 * Return: The value of the extracted node or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    int value;
    heap_t *heap_r, *node;

    if (!root || !*root)
        return (0);
    heap_r = *root;
    value = heap_r->n;
    if (!heap_r->left && !heap_r->right)
    {
        *root = NULL;
        free(heap_r);
        return (value);
    }

    _preorder(heap_r, &node, tree_height(heap_r));

    heap_r->n = node->n;
    if (node->parent->right)
        node->parent->right = NULL;
    else
        node->parent->left = NULL;
    free(node);
    heapify(heap_r);
    *root = heap_r;
    return (value);
}

