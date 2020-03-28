//
// Created by solom on 3/28/20.
//

#include <iostream>

#include "node.h"

int main() {
	node *start = new node(".");
	start->traverse(start);

	std::cout << "ass";
	return 0;
}