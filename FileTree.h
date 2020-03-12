//
// Created by Yusuf Sherif on 2020-03-03.
//

#ifndef PROJECT1_FILETREE_H
#define PROJECT1_FILETREE_H

#include "FileNode.h"

typedef struct FileTree {

    FileNode* root;
    char* root_path;

} FileTree;

void FileTree_init(FileTree *tree, char* root_path);
void FileTree_calculateSizes(FileTree* tree);
void FileTree_destruct(FileTree *tree);
bool FileTree_scan(FileTree* tree);


#endif //PROJECT1_FILETREE_H
