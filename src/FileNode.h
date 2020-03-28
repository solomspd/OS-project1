//
// Created by Yusuf Sherif on 2020-03-03.
//

#ifndef PROJECT1_FILENODE_H
#define PROJECT1_FILENODE_H

#include <stdbool.h>

typedef struct vector vec_t;
typedef struct FileNode FileNode;
struct FileNode {

    char* filename;
    vec_t* children;
    struct FileNode* parent;
    long long int size;

};

void FileNode_init(FileNode *FN, char *name, FileNode *parent);
FileNode * FileNode_addChild(FileNode *parent, FileNode *child);
void FileNode_setParent(FileNode* parent, FileNode* child);
bool FileNode_isFile(FileNode *FN);
void FileNode_destruct(FileNode* FN);
long long int FileNode_calcSize(FileNode *FN);
bool FileNode_traverse(FileNode* FN, const char* path);

#endif //PROJECT1_FILENODE_H
