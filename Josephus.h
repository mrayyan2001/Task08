#pragma once
#include<iostream>	
using namespace std;

class Node {
public:
	int info;
	Node* next;

	Node(int info, Node* next = 0) {
		this->info = info;
		this->next = next;
	}
};

class Josephus
{
	Node* tail;

public:
	Josephus() {
		tail = 0;
	}

	bool isEmpty();
	void insert(int);
	void print();
	void deleteNode(Node*);
	void startGame(int, int);

};

