//
// Created by Yusuf Sherif on 2020-03-10.
//

#include "utilities.h"

long long get_file_size(const char *filename)
{
/*    FILE *p_file = NULL;
    p_file = fopen(filename,"rb");
    long long size;
    if(p_file!=NULL) {
        fseek(p_file, 0, SEEK_END);
        size = ftell(p_file);
        fclose(p_file);
    } else {
        size = 0;
    }
    return size;*/
    struct stat f_info;
    stat(filename, &f_info);
    return f_info.st_size;
}