//
// Created by Yusuf Sherif on 2020-03-03.
//

#include "FileNode.h"

void FileNode_init(FileNode *FN, char *name, FileNode *parent) {
    FN->parent=parent;
    FN->size=0;
    size_t pNameSize = 0;
    if(FN->parent!=NULL)
        pNameSize = strlen(FN->parent->filename);
    FN->filename = (char*) calloc(pNameSize+1+strlen(name)+1, sizeof(char));
    if(FN->parent!=NULL) {
        strcpy(FN->filename, FN->parent->filename);
        strcat(FN->filename, "/");
        strcat(FN->filename, name);
    }
    else{
        strcpy(FN->filename, name);
    }
}

FileNode * FileNode_addChild(FileNode *parent, FileNode *child) {
    parent->children.push_back(child);
    return parent->children.back();
}

void FileNode_setParent(FileNode *parent, FileNode *child) {
    child->parent = parent;
}

bool FileNode_isFile(FileNode *FN) {
    return (FN->children.empty());
}

void FileNode_destruct(FileNode *FN) {
    for (int i = 0; i < FN->children.size(); ++i) {
        FileNode_destruct(FN->children[i]);
    }
    free(FN->filename);
}

/*long long int FileNode_calcSize(FileNode *FN) {
    if(FileNode_isFile(FN)){
        return FN->size;
    } else {
        long long int size = 0;

        for (int i = 0; i < FN->children->vec_size; ++i) {
            size += FileNode_calcSize(&FN->children->t[i]);
        }
        FN->size = size;
        return size;
    }
}*/

bool FileNode_traverse(FileNode *FN, const char *path) {
    char* dir_in = (char*) calloc(strlen(path)+1+1, sizeof(char));
    strcpy(dir_in, path);
    DIR *dir;
    struct dirent *cur;

    dir = opendir(dir_in);

    if (dir == NULL) {
        printf("Error: not a directory\n");
        return false;
    }

    strcat(dir_in, "/");
    char *cur_root;
    cur_root = (char*)calloc(strlen(dir_in)+1+1, sizeof(char));
    strcpy(cur_root, dir_in);


//    dir_in = strncat(dir_in, temp, strlen(dir_in)+strlen(temp));

    while ((cur = readdir(dir))){
        if (strcmp(cur->d_name, ".") == 0 || strcmp(cur->d_name, "..") == 0){
            continue;
        }else {
            char* newPath = (char*) calloc(strlen(cur_root)+strlen(cur->d_name)+1, sizeof(char));
            FileNode *X = (FileNode*) calloc(1, sizeof(FileNode));
            FileNode_init(X, cur->d_name, FN);
            strcpy(newPath, cur_root);
            strcat(newPath, cur->d_name);
            switch (cur->d_type) {
                case DT_REG:
                    //printf("file: %s size: %lli\n", newPath, get_file_size(newPath));//cur_level.terminate(cur_path, file_size(cur_path)));
                    X->size = get_file_size(newPath);
                    FileNode_addChild(FN, X);
                    break;
                case DT_DIR:
                    FileNode_traverse(FileNode_addChild(FN, X), newPath);
                    break;
                default:
                    printf("Error: unexpected file\n");
            }
            free(newPath);
        }
    }

    long long int size = 0;

    for (int i = 0; i < FN->children.size(); ++i) {
        size += FN->children[i]->size;
    }
    FN->size = size;

    closedir(dir);
    free(dir_in);
    free(cur_root);

    return true;
}

