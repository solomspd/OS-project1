//
// Created by Yusuf Sherif on 2020-03-03.
//

#include "FileNode.h"

FileNode::FileNode(char *name, FileNode *parent) {
    this->parent=parent;
    this->size=0;
    size_t pNameSize = 0;
    if(this->parent!=NULL)
        pNameSize = (this->parent->filename.size());
    if(this->parent!=NULL) {
        this->filename = this->parent->filename +  "/" + name;
    }
    else{
        this->filename =  name;
    }
}

void FileNode::addChild(const FileNode &child) {
    this->children.push_back(child);
}

void FileNode::setParent(FileNode *parent) {
    this->parent = parent;
}

bool FileNode::isFile() {
    return (this->children.empty());
}

FileNode::~FileNode(){}

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

bool  FileNode::traverse(const char *path) {
    std::string dir_in ;
    dir_in = path;
    DIR *dir;
    struct dirent *cur;

    dir = opendir(dir_in.c_str());

    if (dir == NULL) {
        printf("Error: not a directory\n");
        return false;
    }

    dir_in+= "/";
    char *cur_root;
    cur_root = (char*)calloc(strlen(dir_in.c_str())+1+1, sizeof(char));
    strcpy(cur_root, dir_in.c_str());


//    dir_in = strncat(dir_in, temp, strlen(dir_in)+strlen(temp));

    while ((cur = readdir(dir))){
        if (strcmp(cur->d_name, ".") == 0 || strcmp(cur->d_name, "..") == 0){
            continue;
        }else {
            char* newPath = (char*) calloc(strlen(cur_root)+strlen(cur->d_name)+1, sizeof(char));
            FileNode X(cur->d_name, this);
            strcpy(newPath, cur_root);
            strcat(newPath, cur->d_name);
            switch (cur->d_type) {
                case DT_REG:
                    //printf("file: %s size: %lli\n", newPath, get_file_size(newPath));//cur_level.terminate(cur_path, file_size(cur_path)));
                    X.size = get_file_size(newPath);
                    this->addChild(X);
                    break;
                case DT_DIR:
                    this->traverse(newPath);
                    break;
                default:
                    printf("Error: unexpected file\n");
            }
            free(newPath);
        }
    }

    long long int size = 0;

    for (int i = 0; i < this->children.size(); ++i) {
        size += this->children[i].size;
    }
    this->size = size;

    closedir(dir);
    free(cur_root);

    return true;
}

