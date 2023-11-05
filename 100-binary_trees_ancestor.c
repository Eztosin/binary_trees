#include "binary_trees.h"

/**
* binary_tree_depth - measures the depth of a node in a binary tree.
* @tree: pointer to the node to measure the depth
* Return: 0 If tree is NULL.
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t root_depth = 0;

if (tree == NULL)
{
return (0);
}

if (tree->parent)
root_depth += 1 + binary_tree_depth(tree->parent);
return (root_depth);
}

/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: a pointer to the first node
* @second: a pointer to the second node
* Return: a pointer to the LCA node, or NULL if not found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
size_t depth1, depth2;

if (first == NULL || second == NULL)
return (NULL);

depth1 = binary_tree_depth(first);
depth2 = binary_tree_depth(second);

while (depth1 > depth2)
{
first = first->parent;
depth1--;
}

while (depth2 > depth1)
{
second = second->parent;
depth2--;
}

while (first && second && first != second)
{
first = first->parent;
second = second->parent;
}

return ((binary_tree_t *)first);
}
