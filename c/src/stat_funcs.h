#include <sys/stat.h>
#include <stdlib.h>
#include <strings.h>

enum FileType {
    REG_FILE,
    DIRECTORY,
    SOCKET,
    SIMLINK,
    BLOCK_DEV,
    CHAR_DEV,
    FIFO_PIPE,
    UNK
};

FileType get_ftype(mode_t mode);

char *get_perm(mode_t mode);

