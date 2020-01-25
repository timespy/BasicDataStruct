#pragma once
#include<stdio.h>
template <typename T_List>


class List {
private:
	class Node_List {
	public:
		int id;
		T_List value;
		Node_List* pre;
		Node_List* next;
	};

	int length;
	Node_List* head;

public:
	List() {
		length = 0;
		head = new Node_List();
		head->id = -1;
		head->next = head;
		head->pre = head;
	}

	int getLength() {
		return length;
	}

	void add(T_List value) {
		length++;
		Node_List* newNode = new Node_List();
		newNode->id = length;
		newNode->value = value;
		newNode->pre = head->pre;
		newNode->next = head;
		head->pre->next = newNode;
		head->pre = newNode;
	}

	void delete_id(int id) {
		Node_List* p = head->next;
		while (true) {
			if (p->id == -1) {
				printf("no such id node in this list.\n");
				break;
			}
			if (p->id == id) {
				p->pre->next = p->next;
				break;
			}
			p = p->next;
		}

		int k = 1;
		p = head->next;
		while (p->id != -1) {
			p->id = k;
			k++;
			p = p->next;
		}
		length = k - 1;
	}

	void delete_value(T_List value) {
		Node_List* p = head->next;
		while (p->id != -1) {
			if (p->value == value)
				p->pre->next = p->next;
			p = p->next;
		}
		
		int k = 1;
		p = head->next;
		while (p->id != -1) {
			p->id = k;
			k++;
			p = p->next;
		}
		length = k - 1;
	}

	void insert(int id, T_List value) {
		Node_List* p = head->next;
		while (true) {
			if (p->id == -1) {
				printf("there is no such pre node you want to insert.\n");
				break;
			}
			if (p->id == id) {
				Node_List* newNode = new Node_List();
				newNode->id = 0;
				newNode->value = value;
				newNode->next = p->next;
				p->next = newNode;
				newNode->pre = p;
				break;
			}
			p = p->next;
		}

		int k = 1;
		p = head->next;
		while (p->id != -1) {
			p->id = k;
			k++;
			p = p->next;
		}
		length = k - 1;
	}

	T_List getId(int id) {
		Node_List* p = head->next;
		while (p->id != id) {
			p = p->next;
			if (p->id == -1) {
				printf("there is no such node you want get.\n");
				return 0.0;
			}
		}
		return p->value;
	}
};
