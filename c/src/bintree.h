#pragma once

#include <stdlib.h>
#include <strings.h>

#include "stat_funcs.h"

typedef struct BinTree {
    char* name;
    enum FileType f_type;
    int level;
    struct BinTree* left;
    struct BinTree* right;
} BinTree;

BinTree *init_tree(char* name, FileType f_type, int level, BinTree* left, BinTree* right);

void destroy_tree(BinTree* tree);

