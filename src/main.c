#include "FileTree.h"
#include <stdio.h>


const int mx_char = 255;


int main(int argc, char **argv) {

    FileTree X;
    FileTree_init(&X,"./");
    FileTree_calculateSizes(&X);
    printf("%lli", X.root->size);
    FileTree_destruct(&X);

    return 0;
}
