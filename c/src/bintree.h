#pragma once

#include <stdlib.h>
#include <strings.h>

#include <stat_funcs.h>

typedef struct BinTree {
    char* name;
    FileType;
    int level;
    struct BinTree* left;
    struct BinTree* right;
} BinTree;

void destroy_tree(BinTree* tree);

