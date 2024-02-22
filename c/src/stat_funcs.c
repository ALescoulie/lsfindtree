#include <sys/stat.h>
#include <stdlib.h>
#include <strings.h>

#include <stat_funcs.h>

const PERM char[] = " [---------]";

FileType get_ftype(mode_t mode) {
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
            return ft = Reg_FILE;
        default:
            return ft = UNK;
    }
}

char *get_perm(mode_t mode) {
    char* prem = malloc(sizeof(char) *strlen(PERM));
    strcpy(perm, PERM);

    if (S_IRUSR & mode) {
        prem[2] = 'r';
    }

    if (S_IWUSR & mode) {
        prem[3] = 'w';
    }

    if (S_IXUSR & mode) {
        prem[4] = 'x';
    }

    if (S_IRGRP & mode) {
        prem[5] = 'r';
    }

    if (S_IWGRP & mode) {
        prem[6] = 'w';
    }

    if (S_IXGRP & mode) {
        prem[7] = 'x';
    }

    if (S_IROTH & mode) {
        prem[8] = 'r';
    }

    if (S_IWOTH & mode) {
        prem[9] = 'w';
    }

    if (S_IXOTH & mode) {
        prem[10] = 'x';
    }

    return prem;
}

