#pragma once
#include <iostream>

//binary node struct implementation
struct binNode;
struct binNode {
	int value;
	binNode* right;
	binNode* left;
};

//function declarations
bool search_tree(binNode* node, int num);
int maxHeight(binNode* node);
void mirror(binNode* node);
void print_tree(binNode* node);
