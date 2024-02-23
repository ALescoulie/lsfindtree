#include <sys/stat.h>
#include <stdlib.h>
#include <strings.h>

#include "stat_funcs.h"

const char PERM[] = " [---------]";

enum FileType get_ftype(mode_t mode) {
    enum FileType ft;

    switch (mode) {
        case S_ISBLK(mode):
            return ft = BLOCK_DEV;
        case S_ISDIR(mode):
            return ft = DIRECTORY;
        case S_ISLNK(mode):
            return ft = SIMLINK;
        case S_ISFIFO(mode):
            return ft = FIFO_PIPE;
        case S_ISSOCK(mode):
            return ft = SOCKET;
        case S_ISREG(mode):
            return ft = REG_FILE;
        default:
            return ft = UNK;
    }
}

char *get_perm(mode_t mode) {
    char* perm = malloc(sizeof(char) * strlen(&PERM));
    strcpy(perm, PERM);

    if (S_IRUSR & mode) {
        perm[2] = 'r';
    }

    if (S_IWUSR & mode) {
        perm[3] = 'w';
    }

    if (S_IXUSR & mode) {
        perm[4] = 'x';
    }

    if (S_IRGRP & mode) {
        perm[5] = 'r';
    }

    if (S_IWGRP & mode) {
        perm[6] = 'w';
    }

    if (S_IXGRP & mode) {
        perm[7] = 'x';
    }

    if (S_IROTH & mode) {
        perm[8] = 'r';
    }

    if (S_IWOTH & mode) {
        perm[9] = 'w';
    }

    if (S_IXOTH & mode) {
        perm[10] = 'x';
    }

    return perm;
}

