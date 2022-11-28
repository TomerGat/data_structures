#include "linked_list.h"

//main - driver program to test functions
int nodemain() {
	node n1;
	node n2;
	node n3;
	node n4;
	node n5;

	//bubble sort test
	n5 = { 2, nullptr };
	n4 = { 10, &n5 };
	n3 = { 4, &n4 };
	n2 = { 1, &n3 };
	n1 = { 9, &n2 };
	node* head = &n1;
	std::cout << "Before bubble sort: ";
	printLst(head);
	std::cout << "After bubble sort: ";
	head = bubble_sort(head);
	printLst(head);
	std::cout << std::endl;

	//selection sort test
	n5 = { 5, nullptr };
	n4 = { 4, &n5 };
	n3 = { 13, &n4 };
	n2 = { 5, &n3 };
	n1 = { 28, &n2 };
	head = &n1;
	std::cout << "Before selection sort: ";
	printLst(head);
	std::cout << "After selection sort: ";
	head = selection_sort(head);
	printLst(head);
	std::cout << std::endl;

	//merge sort test
	n5 = { 2, nullptr };
	n4 = { 17, &n5 };
	n3 = { 9, &n4 };
	n2 = { 3, &n3 };
	n1 = { 19, &n2 };
	head = &n1;
	std::cout << "Before merge sort: ";
	printLst(head);
	std::cout << "After merge sort: ";
	head = merge_sort(&head);
	printLst(head);
	std::cout << std::endl;

	//reverse test
	n5 = { 2, nullptr };
	n4 = { 5, &n5 };
	n3 = { 9, &n4 };
	n2 = { 2, &n3 };
	n1 = { 7, &n2 };
	head = &n1;
	std::cout << "Before reverse: ";
	printLst(head);
	std::cout << "After reverse: ";
	reverse(head);
	printLst(&n5);
	std::cout << std::endl;

	//palidrome test 1
	n5 = { 2, nullptr };
	n4 = { 5, &n5 };
	n3 = { 9, &n4 };
	n2 = { 2, &n3 };
	n1 = { 7, &n2 };
	head = &n1;
	std::cout << "Linked list 1: ";
	printLst(head);
	std::cout << "Is list 1 a palindrome? " << (palindrome(head)? ("yes") : ("no")) << std::endl;
	std::cout << std::endl;

	//palidrome test 2
	n5 = { 2, nullptr };
	n4 = { 5, &n5 };
	n3 = { 9, &n4 };
	n2 = { 5, &n3 };
	n1 = { 2, &n2 };
	head = &n1;
	std::cout << "Linked list 2: ";
	printLst(head);
	std::cout << "Is list 2 a palindrome? " << (palindrome(head) ? ("yes") : ("no")) << std::endl;

	return 0;
}


/*
Output from main (driver program):

Before bubble sort: 9--->1--->4--->10--->2--->null
After bubble sort: 1--->2--->4--->9--->10--->null

Before selection sort: 28--->5--->13--->4--->5--->null
After selection sort: 4--->5--->5--->13--->28--->null

Before merge sort: 19--->3--->9--->17--->2--->null
After merge sort: 2--->3--->9--->17--->19--->null

Before reverse: 7--->2--->9--->5--->2--->null
After reverse: 2--->5--->9--->2--->7--->null

Linked list 1: 7--->2--->9--->5--->2--->null
Is list 1 a palindrome? no

Linked list 2: 2--->5--->9--->5--->2--->null
Is list 2 a palindrome? yes

*/