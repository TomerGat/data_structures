#include "linked_list.h"

/*
node* selectionSort(node* pos)
{
	if (pos == nullptr)
	{
		return pos;
	}
	if (pos->next == nullptr)
	{
		return pos;
	}

	node* before = nullptr;
	node* ptr = pos;
	int smallest = pos->value;
	while (ptr->next != nullptr)
	{
		if (ptr->next->value < smallest)
		{
			before = ptr;
			smallest = ptr->next->value;
		}
		ptr = ptr->next;
	}
	if (before == nullptr)
	{
		return selectionSort(pos->next);
	}
	pos = front(pos, before, before->next);
	return selectionSort(pos->next);


}

node* front(node* pos, node* before, node* min)
{
	before->next = min->next;
	min->next = pos;
	return min;
}
*/


//print linked list
void printLst(node* nd1)
{
	node* temp = nd1;
	while (temp != nullptr) {
		std::cout << temp->value << "--->";
		temp = temp->next;
	}
	std::cout << "null" << std::endl;
}

//reverse linked list
void reverse(node* pos)
{
	node* temp = pos;
	while (pos->next != nullptr) {
		temp = pos;
		while (temp->next->next != nullptr) { temp = temp->next; }
		temp->next->next = temp;
		temp->next = nullptr;
	}
}

// function returning length of list
int length(node* pos)
{
	if (pos == nullptr) { return 0; }
	return 1 + length(pos->next);
}

//function checking if linked list contains a palindrome
bool palindrome(node* pos)
{
	static int jump = length(pos) - 1;
	if (jump <= 0) { return true; }
	node* temp = pos;
	for (int i = 0; i < jump; i++) { temp = temp->next; }
	if (pos->value != temp->value) { return false; }
	jump = jump - 2;
	return palindrome(pos->next);
}

//recursive implementation of selection sort algorithm for linked list
node* selection_sort(node* pos) {
	if (pos->next == nullptr) {
		return pos;
	}
	node* ptr;
	node* before_min = nullptr;
	node* min = pos;
	for (ptr = pos; ptr->next != nullptr; ptr = ptr->next) {
		if (ptr->next->value < min->value) {
			min = ptr->next;
			before_min = ptr;
		}
	}
	if (min != pos) {
		pos = bringToFront(pos, before_min, min);
	}
	pos->next = selection_sort(pos->next);
	return pos;
}

//bring node to front of linked list - side function for selection sort
node* bringToFront(node* current, node* before, node* min)
{
	before->next = min->next;
	min->next = current;
	return min;
}

//recursive implementation of bubble sort algorithm for linked list
node* bubble_sort(node* pos) {
	static int counter = 0;
	static int listlength = length(pos);
	static node* first = pos;
	static node* before = nullptr;
	if (pos->next == nullptr) {
		if (before == nullptr) {
			return first;
		}
		before = nullptr;
		return bubble_sort(first);
	}
	if (pos->value > pos->next->value) {
		node* nextnode = pos->next;
		swap(before, pos, nextnode);
		counter = 0;
		pos = nextnode;
		if (before == nullptr) {
			first = pos;
		}
	}
	else {
		counter++;
		if (counter == listlength) {
			return first;
		}
	}
	if (before == nullptr) {
		before = first;
	}
	else {
		before = before->next;
	}
	return bubble_sort(pos->next);
}

//swap two nodes in a linked list - side function for bubble sort
void swap(node* before, node* ptr1, node* ptr2)
{
	node* temp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = temp;
	if (before != nullptr) { before->next = ptr2; }
}

//implementation of merge sort algorithm for linked list
node* merge_sort(node** headRef)
{
	node* head = *headRef;
	node* a;
	node* b;

	if ((head == nullptr) || (head->next == nullptr)) {
		return *headRef;
	}

	split(head, &a, &b);

	merge_sort(&a);
	merge_sort(&b);

	*headRef = merge_sides(a, b);
	return *headRef;
}

//splits linked list into two halves - side function for merge sort
void split(node* source, node** frontRef, node** backRef)
{
	node* fast;
	node* slow;
	slow = source;
	fast = source->next;

	while (fast != nullptr) {
		fast = fast->next;
		if (fast != nullptr) {
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = nullptr;
}

//merges two linked list into one according to larger value - side function for merge sort
node* merge_sides(node* a, node* b)
{
	node* result = nullptr;

	if (a == nullptr)
		return (b);
	else if (b == nullptr)
		return (a);

	if (a->value <= b->value) {
		result = a;
		result->next = merge_sides(a->next, b);
	}
	else {
		result = b;
		result->next = merge_sides(a, b->next);
	}
	return result;
}
