#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "stat_funcs.h"
#include "bintree.h"

BinTree *init_tree(char* name, FileType f_type, int level, BinTree* left, BinTree* right) {
    BinTree *tree;
    tree = malloc(sizeof(BinTree));

    tree->right = right;
    tree->left = left;
    
    tree->name = name;
    tree->f_type = f_type;
    tree->level = level;
    
    return tree;
}

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

