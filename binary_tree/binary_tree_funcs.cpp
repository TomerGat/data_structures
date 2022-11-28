#include "binary_tree.h"

//searches tree for value
bool search_tree(binNode* node, int num) {
	if (node->value == num) {
		return true;
	}
	if (node->right && node->left) {
		return (search_tree(node->right, num) || search_tree(node->left, num));
	}
	else if (node->right) {
		return search_tree(node->right, num);
	}
	else if (node->left) {
		return search_tree(node->left, num);
	}
	return false;
}

//returns max height of tree (longest path of binNodes)
int maxHeight(binNode* node) {
	if (node == nullptr) {
		return 0;
	}
	int maxRight = maxHeight(node->right);
	int maxLeft = maxHeight(node->left);
	if (maxRight > maxLeft) { return 1 + maxRight; }
	else { return 1 + maxLeft; }
}

//mirrors the shape of the tree
void mirror(binNode* node) {
	if (node == nullptr) {
		return;
	}
	mirror(node->left);
	mirror(node->right);
	binNode* temp = node->left;
	node->left = node->right;
	node->right = temp;
}

//prints the tree
void print_tree(binNode* node) {
	if (node == NULL) {
		return;
	}
	print_tree(node->left);
	std::cout << node->value << " ";
	print_tree(node->right);
}