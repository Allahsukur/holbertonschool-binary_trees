#include "binary_trees.h"

int _tree_depth(const binary_tree_t *tree) {
    int depth = 0;
    while (tree) {
        depth++;
        tree = tree->left;
    }
    return depth;
}

int _is_perfect(const binary_tree_t *tree, int depth, int level) {
    if (!tree)
        return 1;

    if (!tree->left && !tree->right)
        return (depth == level + 1);

    if (!tree->left || !tree->right)
        return 0;

    return _is_perfect(tree->left, depth, level + 1) &&
           _is_perfect(tree->right, depth, level + 1);
}

int binary_tree_is_perfect(const binary_tree_t *tree) {
    int depth;
    if (!tree)
        return 0;

    depth = _tree_depth(tree);
    return _is_perfect(tree, depth, 0);
}
