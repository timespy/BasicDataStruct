#pragma once
#include<stdio.h>
template <typename T_Queue>

class Queue {
private:
	class Node_Queue {
	public:
		T_Queue value;
		Node_Queue* next;
	};

	int length;
	Node_Queue* head;
	Node_Queue* tail;

public:
	Queue() {
		length = 0;
		head = NULL;
		tail = NULL;
	}

	int getLength() {
		return length;
	}

	void enqueue(T_Queue value) {
		if (length == 0) {
			head = new Node_Queue();
			head->value = value;
			head->next = NULL;
			tail = head;
		}
		else {
			tail->next = new Node_Queue();
			tail = tail->next;
			tail->value = value;
			tail->next = NULL;
		}
		length++;
	}

	T_Queue dequeue() {
		Node_Queue* p = head;
		head = head->next;
		length--;
		return p->value;
	}
};
