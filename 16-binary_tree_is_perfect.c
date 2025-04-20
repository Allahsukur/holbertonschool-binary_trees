#include "binary_trees.h"

/**
 * depth - calculates depth of the tree
 * @tree: pointer to the node
 * Return: depth
 */
int depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perfect_recursive - checks recursively if tree is perfect
 * @tree: pointer to root
 * @d: expected depth
 * @level: current level
 * Return: 1 if perfect, 0 if not
 */
int is_perfect_recursive(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (d == level + 1);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_recursive(tree->left, d, level + 1) &&
		is_perfect_recursive(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (!tree)
		return (0);

	d = depth(tree);
	return (is_perfect_recursive(tree, d, 0));
}
