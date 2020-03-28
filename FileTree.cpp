//
// Created by Yusuf Sherif on 2020-03-03.
//

#include "FileTree.h"


/*void FileTree_calculateSizes(FileTree *tree) {
    FileNode_calcSize(tree->root);
}*/

void FileTree_init(FileTree *tree, char *root_path) {
    tree->root = (FileNode*)calloc(1, sizeof(FileNode));
    FileNode_init(tree->root, root_path, NULL);
    tree->root_path = (char*)calloc(strlen(root_path)+1, sizeof(char));
    strcpy(tree->root_path, root_path);
    FileTree_scan(tree);
}

void FileTree_destruct(FileTree *tree) {
    FileNode_destruct(tree->root);
    free(tree->root);
    free(tree->root_path);
}

bool FileTree_scan(FileTree* tree){
    FileNode_traverse(tree->root, tree->root_path);
}

