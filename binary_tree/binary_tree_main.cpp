#include "binary_tree.h"

//main - driver program to test functions
int main() {
	//creating a binary tree to test with
	binNode n9 = { 0, NULL, NULL };
	binNode n8 = { 0, &n9, NULL };
	binNode n7 = { 0, NULL, NULL };
	binNode n6 = { 1, NULL, &n8 };
	binNode n5 = { 7, NULL, NULL };
	binNode n4 = { 9, NULL, NULL };
	binNode n3 = { 2, &n5, &n6 };
	binNode n2 = { 3, &n4, &n7 };
	binNode n1 = { 8, &n2, &n3 };

	//testing mirror function
	std::cout << "Before mirror: ";
	print_tree(&n1);
	mirror(&n1);
	std::cout << std::endl << "After mirror: ";
	print_tree(&n1);
	std::cout << std::endl << std::endl;

	//testing search function
	std::cout << "Current tree: ";
	print_tree(&n1);
	std::cout << std::endl;
	std::cout << "Is the number 5 in the binary tree? " << (search_tree(&n1, 5) ? ("yes") : ("no")) << std::endl;
	std::cout << "Is the number 7 in the binary tree? " << (search_tree(&n1, 7) ? ("yes") : ("no")) << std::endl;
	std::cout << "Is the number 0 in the binary tree? " << (search_tree(&n1, 0) ? ("yes") : ("no")) << std::endl;
	std::cout << "Is the number 2 in the binary tree? " << (search_tree(&n1, 2) ? ("yes") : ("no")) << std::endl;
	std::cout << "Is the number 4 in the binary tree? " << (search_tree(&n1, 4) ? ("yes") : ("no")) << std::endl;
	std::cout << std::endl;

	//testing height check function
	std::cout << "Current tree: ";
	print_tree(&n1);
	std::cout << std::endl;
	std::cout << "The maximum height of the tree is: " << maxHeight(&n1);
	return 0;
}

/*
output from main (driver program):

Before mirror: 0 0 1 2 7 8 0 3 9
After mirror: 9 3 0 8 7 2 1 0 0

Current tree: 9 3 0 8 7 2 1 0 0
Is the number 5 in the binary tree? no
Is the number 7 in the binary tree? yes
Is the number 0 in the binary tree? yes
Is the number 2 in the binary tree? yes
Is the number 4 in the binary tree? no

Current tree: 9 3 0 8 7 2 1 0 0
The maximum height of the tree is: 5

*/