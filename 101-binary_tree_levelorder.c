#include "binary_trees.h"
/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Tree to measure the height
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t l = 0, r = 0;

if (!tree)
return (0);

l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

return ((l > r) ? l : r);
}

/**
 * binary_tree_depth - Function that measures the depth of a node
 * in a binary tree
 * @tree: Node to measure the depth
 * Return: The depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

/**
 * linked_node - Function that adds a new node to the linked list
 * @head: Pointer to the head of the linked list
 * @tree: Pointer to the binary tree node
 * @level: Level of the tree where the node is located
 */
void linked_node(link_t **head, const binary_tree_t *tree, size_t level)
{
link_t *new, *aux;

new = malloc(sizeof(link_t));
if (!new)
return;

new->n = level;
new->node = tree;
new->next = NULL;

if (*head == NULL)
{
*head = new;
}
else
{
aux = *head;
while (aux->next != NULL)
aux = aux->next;
aux->next = new;
}
}

/**
* recursion - Function that performs level-order traversal and stores nodes
* in a linked list
* @head: Pointer to the head of the linked list
* @tree: Pointer to the current binary tree node
*/
void recursion(link_t **head, const binary_tree_t *tree)
{
size_t level = 0;
if (tree != NULL)
{
level = binary_tree_depth(tree);
linked_node(head, tree, level);
recursion(head, tree->left);
recursion(head, tree->right);
}
}

/**
 * binary_tree_levelorder - Function that goes through a binary tree using
 * level-order traversal and applies a function to each node
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
link_t *head, *aux;
size_t height = 0, count = 0;

if (!tree || !func)
return;

height = binary_tree_height(tree);
head = NULL;
recursion(&head, tree);

while (count <= height)
{
aux = head;
while (aux != NULL)
{
if (count == aux->n)
func(aux->node->n);
aux = aux->next;
}
count++;
}

while (head != NULL)
{
aux = head;
head = head->next;
free(aux);
}
}

