//
// Created by Yusuf Sherif on 2020-03-03.
//

#ifndef PROJECT1_FILENODE_H
#define PROJECT1_FILENODE_H

#include <vector>
#include "utilities.h"
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct FileNode FileNode;
struct FileNode {

    char* filename;
    std::vector<FileNode*> children;
    struct FileNode* parent;
    long long int size;

};

void FileNode_init(FileNode *FN, char *name, FileNode *parent);
FileNode * FileNode_addChild(FileNode *parent, FileNode *child);
void FileNode_setParent(FileNode* parent, FileNode* child);
bool FileNode_isFile(FileNode *FN);
void FileNode_destruct(FileNode* FN);
//long long int FileNode_calcSize(FileNode *FN);
bool FileNode_traverse(FileNode* FN, const char* path);

#endif //PROJECT1_FILENODE_H
