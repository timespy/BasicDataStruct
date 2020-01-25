#pragma once
#include<stdio.h>
template <typename T_Stack>

class Stack {
private:
	class Node_Stack {
	public:
		T_Stack value;
		Node_Stack* next;
	};

	int length;
	Node_Stack* head;

public:
	Stack() {
		length = 0;
		head = NULL;
	}

	int getLength() {
		return length;
	}

	void Push(T_Stack value) {
		Node_Stack* newNode = new Node_Stack();
		newNode->value = value;
		newNode->next = head;
		head = newNode;
		length++;
	}

	T_Stack Pop() {
		T_Stack ret = head->value;
		head = head->next;
		length--;
		return ret;
	}
};
