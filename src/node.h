//
// Created by solom on 3/28/20.
//

#ifndef OS_PROJECT1_NODE_H
#define OS_PROJECT1_NODE_H

#include <string>
#include <vector>

class node {
private:
	unsigned long long size;
	std::string name;
	std::string dir;
	std::vector<node*> child;
	node *parent;
public:
	node();
	node (std::string in);
	~node();
	bool traverse(node *cur_node);
	node *new_cild(std::string name, node *in_parent);
	bool terminate(unsigned long long sz);
};


#endif //OS_PROJECT1_NODE_H
