#include "Josephus.h"

bool Josephus::isEmpty() { return tail == 0; }
void Josephus::insert(int info) { // insertEnd
	if (isEmpty()) {
		tail = new Node(info);
		tail->next = tail;
	}
	else tail = tail->next = new Node(info, tail->next);
}
void Josephus::print() {
	for (Node* temp = tail->next; ; temp = temp->next) {
		cout << temp->info;
		if (temp == tail) break;
		cout << "-->";
	}
	cout << endl;
}

void Josephus::deleteNode(Node* node) {
	if (isEmpty() || node == 0) return; // empty
	if (tail == tail->next && node == tail) { // one node
		delete tail;
		tail = 0;
	}
	else { // more than one node
		Node* temp;
		for (temp = tail; temp->next != node && temp->next != tail; temp = temp->next);
		if (temp->next == tail && node == tail) { // if node is on tail
			temp->next = tail->next;
			delete tail;
			tail = temp;
		}
		else {
			temp->next = node->next;
			delete node;
		}
	}
}

void Josephus::startGame(int n, int m) {
	while(!isEmpty()) deleteNode(tail->next); // clear list
	for (int i = 1; i <= n; i++) insert(i); // insert player
	cout << "Start Game... Number of player = " << n << "... Move = " << m << endl;
	print();
	Node* current = tail->next;
	while (tail->next != tail) {
		cout << "Start from player[" << current->info << "]." << endl;
		for (int i = 0; i < m; i++) current = current->next;
		cout << "After " << m << " movement the player[" << current->info << "] kick out" << endl;
		Node* temp = current->next;
		deleteNode(current);
		current = temp;
		print();
	}
	cout << "Winner is player[" << current->info << "]." << endl;
	cout << "------------------------------------------" << endl;
}