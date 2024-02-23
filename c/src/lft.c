#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

#include "bintree.h"
#include "stat_funcs.h"

BinTree *build_dir_tree(DIR* dir, char* dir_name, int level, BinTree *dir_tree, char* match) {

    struct dirent *entry = readdir(dir);
    chdir(dir_name);

    if (entry == NULL) {
        chdir("..");
        return NULL;
    }

    if (strcmp(entry->d_name, ".") || strcmp(entry->d_name, "..")) {
        dir_tree->left = build_dir_tree(dir, dir_name, level, dir_tree, match);
        chdir("..");
        return dir_tree;
    }

    struct stat st;

    stat(entry, &st);

    enum FileType ft = get_ftype(st.st_mode);
    

    if (ft != DIRECTORY && (match == NULL || strstr(entry->d_name, match)) != NULL) {
        BinTree *node = init_tree(entry->d_name, ft, level, NULL, NULL);
        node->left = build_dir_tree(dir, dir_name, level, node, match);
        chdir("..");
        return node;
    }

    if (ft == DIRECTORY) { 
        BinTree *node = init_tree(entry->d_name, ft, level, NULL, NULL);
        node->right = build_dir_tree(opendir(node->name), node->name, level + 1, node, match);
        node->left = build_dir_tree(dir, dir_name, level, node, match);
        chdir("..");
        return node;
    }

    return dir_tree;
}

