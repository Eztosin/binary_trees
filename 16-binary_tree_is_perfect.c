#include "binary_trees.h"

/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: pointer to the root node of the tree to check.
* Return: 1 if tree is perfect, 0 otherwise.
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t left_height, right_height;

if (binary_tree_is_full(tree))
{
left_height = binary_tree_height(tree->left);
right_height = binary_tree_height(tree->right);

if (left_height == right_height)
{
return (1);
}
}
return (0);
}


/**
* binary_tree_is_full - checks if a binary tree is full.
* @tree: pointer to the root node of the tree to check.
* Return: 0 If tree is NULL otherwise return 1
*
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
if (tree == NULL)
{
return (0);
}

if ((tree->left == NULL) && (tree->right == NULL))
return (1);
if (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right))
{
return (1);
}
return (0);
}

/**
* binary_tree_height - measures the height of a binary tree.
* @tree:  pointer to the root node of the tree to measure the
* balance factor.
* Return: Height measured
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
size_t left_height = 0, right_height = 0;

if (tree == NULL)
{
return (0);
}

left_height += 1 + binary_tree_height(tree->left);
right_height += 1 + binary_tree_height(tree->right);

if (left_height > right_height)
return (left_height);

else
return (right_height);
}
