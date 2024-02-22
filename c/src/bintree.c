#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <bintree.h>

void destroy_tree(Bintree* tree) {
    if (tree->left != NULL) {
        destroy_tree(tree->left);
    }

    if (tree->right != NULL) {
        destroy_tree(tree->right);
    }

    free(tree->name);
    free(tree);
}

