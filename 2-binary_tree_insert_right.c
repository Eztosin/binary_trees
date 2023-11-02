#include "binary_trees.h"

/**
* binary_tree_insert_right - a function that inserts a node as the
* left-child of another node
* @parent: pointer to the node to insert the left-child in.
* @value: value to store in the new node
* Return: pointer to the created node, or NULL on failure or
* if parent is NULL
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent,
				       int value)
{
binary_tree_t *new_right;

if (parent == NULL)
{
return (NULL);
}

new_right = binary_tree_node(parent, value);
if (new_right == NULL)
{
return (NULL);
}

if (parent->right)
{
new_right->right = parent->right;
new_right->right->parent = new_right;
}
parent->right = new_right;

return (new_right);
}
