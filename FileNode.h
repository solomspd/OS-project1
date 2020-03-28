//
// Created by Yusuf Sherif on 2020-03-03.
//

#ifndef PROJECT1_FILENODE_H
#define PROJECT1_FILENODE_H

#include <vector>
#include <string>

#include "utilities.h"
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

typedef struct FileNode FileNode;
class FileNode {
public:
    std::string filename;
    std::vector<FileNode> children;
    struct FileNode* parent;
    long long int size;
    FileNode(char *name, FileNode *parent);
    void addChild(const FileNode &child);
    void setParent(FileNode* child);
    bool isFile();
    bool traverse(const char* path);
    ~FileNode();
};

#endif //PROJECT1_FILENODE_H
