//
// Created by Yusuf Sherif on 2020-03-10.
//

#include "utilities.h"
#include <stdio.h>
#include <sys/stat.h>

long long get_file_size(const char *filename)
{
    struct stat f_info;
    stat(filename, &f_info);
    return f_info.st_size;
}