#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

const int mx_char = 255;

bool traverse(char *dir_in, int *level);
long file_size(char *in_file);

int main(int argc, char **argv) {

    char in[] = ".";
    traverse(in, 0);

    return 0;
}

bool traverse (char *dir_in, int *level) {
    DIR *dir;
    struct dirent *cur;

    dir = opendir(dir_in);

    if (dir == NULL) {
        printf("Error: not a directory\n");
        return false;
    }

    char *cur_root;
    strcat(dir_in, "/");
    cur_root = realloc(NULL, sizeof(char)*strlen(dir_in));
    strcpy(cur_root, dir_in);

//    dir_in = strncat(dir_in, temp, strlen(dir_in)+strlen(temp));

    while ((cur = readdir(dir))){
        printf("%s\n", cur->d_name);
        if (strcmp(cur->d_name, ".") == 0 || strcmp(cur->d_name, "..") == 0){
            continue;
        }
        strcpy(dir_in, cur_root);
        strcat(dir_in, cur->d_name);
        switch (cur->d_type) {
            case DT_REG: printf("file: %s size: %d\n", dir_in, file_size(dir_in));//cur_level.terminate(cur_path, file_size(cur_path)));
                break;
            case DT_DIR: traverse(dir_in, 0/*cur_level.next_level()*/);
                break;
            default: printf("Error: unexpected file");
        }
    }

    closedir(dir);

    return true;
}

//long file_size(char *in_file) {
//
//}

long file_size(char *in_file) {
//    FILE *file = fopen(in_file, "r");
    struct stat f_info;
    stat(in_file, &f_info);
    return f_info.st_size;
}