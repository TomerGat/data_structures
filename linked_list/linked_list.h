#pragma once
#include <iostream>

//node struct implementation
struct node;
struct node {
	int value;
	node* next;
};

//function declarations
void printLst(node* nd1);
void reverse(node* pos);
int length(node* pos);
bool palindrome(node* pos);
node* bringToFront(node* current, node* before, node* min);
node* selection_sort(node* pos);
void swap(node* before, node* ptr1, node* ptr2);
node* bubble_sort(node* pos);
void split(node* source, node** frontRef, node** backRef);
node* merge_sides(node* a, node* b);
node* merge_sort(node** headRef);
