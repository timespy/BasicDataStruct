#pragma once
#include<stdio.h>
#include"Queue.h"

class BinaryTree_List {
private:
	class Node_Tree {
	public:
		char value;
		Node_Tree* left;
		Node_Tree* right;
	};

	int number_nodes;
	Node_Tree* root;

	Node_Tree* create(char* values, int k, Node_Tree* root) {
		if (values[k] != '#') {
			number_nodes++;
			root = new Node_Tree();
			root->value = values[k];
			root->left = create(values, 2 * k + 1, root->left);
			root->right = create(values, 2 * k + 2, root->right);
		}
		else
			root = NULL;
		return root;
	}

	void pre_order(Node_Tree* root) {
		if (root != NULL) {
			printf("%c ", root->value);
			pre_order(root->left);
			pre_order(root->right);
		}
	}

	void in_order(Node_Tree* root) {
		if (root != NULL) {
			in_order(root->left);
			printf("%c ", root->value);
			in_order(root->right);
		}
	}

	void post_order(Node_Tree* root) {
		if (root != NULL) {
			post_order(root->left);
			post_order(root->right);
			printf("%c ", root->value);
		}
	}

public:
	BinaryTree_List() {
		root = NULL;
		number_nodes = 0;
	}
	BinaryTree_List(char* values) {
		root = create(values, 0, root);
		number_nodes = 0;
	}

	int getNumberNodes() {
		return number_nodes;
	}

	void PreOrder() {
		pre_order(root);
	}

	void InOrder() {
		in_order(root);
	}

	void PostOrder() {
		post_order(root);
	}

	void LayerOrder() {
		if (root == NULL) {
			printf("this is an empty tree , cannot output\n");
			return;
		}

		Queue<Node_Tree*> queue;
		Node_Tree* p;
		queue.enqueue(root);
		while (queue.getLength() != 0) {
			p = queue.dequeue();
			printf("%c ", p->value);
			if (p->left != NULL)
				queue.enqueue(p->left);
			if (p->right != NULL)
				queue.enqueue(p->right);
		}
	}
};
