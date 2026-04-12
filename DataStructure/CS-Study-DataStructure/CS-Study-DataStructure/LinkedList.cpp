#include <iostream>

using namespace std;

// const를 쓰는 이유는 값이 중간에 함부로 변하게 하지 못하게 하기 위해서임.
class Node {
private:
	int element;
	Node* next_node;

public:
	Node(int = 0, Node* = 0);

	int retrieve() const;
	Node* next() const;
};

Node::Node(int e, Node *n) : element(e), next_node(n){}

int Node::retrieve() const {
	return element;
}

Node* Node::next() const {
	return next_node;
}

class List {
private:
	Node* list_head;
public:
	List(Node * = 0);
	~List();

	// Accessors
	bool empty() const;
	int front() const;
	Node* head() const;
	bool member(int) const;

	//Mutators
	void push_front(int);
	int pop_front();
	bool remove(int);
};

List::List(Node* n) : list_head(n){}

bool List::empty() const {
	if (list_head == 0)
		return true;
	else
		return false;
}

int List::front() const {
	if (empty()) {
		throw UNDERFLOW;
	}
	return list_head->retrieve();
}

Node* List::head() const {
	return list_head;
}

bool List::member(int n) const {
	if (empty()) {
		throw UNDERFLOW;
	}
	Node* node = list_head;
	for (Node* tmp = head(); tmp != 0; tmp = tmp->next()) {
		if (tmp->retrieve() == n)
			return true;
	}
	return false;
}

void List::push_front(int n) {
	if (empty()) {
		list_head = new Node(n, 0);
	}
	else {
		list_head = new Node(n, list_head);
	}
}

int List::pop_front() {
	if (empty())
		throw UNDERFLOW;
	int e = front();

	Node* tmp = list_head;
	list_head = list_head->next();
	delete tmp;
	return e;
	
}
