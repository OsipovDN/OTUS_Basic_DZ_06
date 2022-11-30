#pragma once
#include <iostream>

template <typename T>
class MyDubList {
	struct Node
	{
		T val;
		Node* prev;
		Node* next;
		Node(const T& count) :val(count),prev(nullptr), next(nullptr) {}
	};
	Node* first;
	Node* last;
	size_t size;
public:
	MyDubList() :first(nullptr), last(nullptr), size(0) {}
	explicit MyDubList(const T& val);
	explicit MyDubList(size_t count, const T& val);
	~MyDubList();
	bool is_empty()const;
	void push_back(const T& val);
	void push_front(const T& val);
	size_t get_size()const { return size; }
	Node* erase(Node* pos);
	void insert(size_t pos, size_t count, const T& val);
	void insert(size_t pos, const T& val);
	void print()const;
};


template <typename T>
MyDubList<T>::MyDubList(const T& val) :MyDubList() {
	first = last = new Node(val);
	size += 1;
}
template <typename T>
MyDubList<T>::MyDubList(size_t count, const T& val) : MyDubList() {
	if (count == 0) {
		return;
	}
	first = last = new Node(val);
	Node* temp = first;
	size = 1;
	while (size < count) {
		temp->next = new Node(val);
		temp->prev = temp;
		temp = temp->next;
		size += 1;
	}
	last = temp;
}

template <typename T>
MyDubList<T>::~MyDubList() {
	Node* temp = first;
	Node* buf;
	while (temp->next != nullptr) {
		buf = temp->next;
		delete temp;
		temp = buf;
	}
}

template <typename T>
bool MyDubList<T>::is_empty()const {
	return (first == nullptr);
}

template <typename T>
void MyDubList<T>::push_back(const T& val) {
	Node* temp = new Node(val);
	if (is_empty()) {
		first = last = temp;
		size += 1;
		return;
	}
	temp->prev = last;
	last->next = temp;
	last = temp;
	size += 1;
}

template <typename T>
void MyDubList<T>::push_front(const T& val) {
	Node* temp = new Node(val);
	if (is_empty()) {
		first = last = temp;
		return;
	}
	first->prev = temp;
	temp->next = first;
	first = temp;
	size += 1;
}
//Доделать с этого момента
template <typename T>
typename MyDubList<T>::Node* MyDubList<T>::erase(Node* pos) {
	Node* temp = first;
	while (temp != pos) {
		temp = temp->next;
	}
	temp->next = lst->next;
	delete lst;
	size -= 1;
	return temp;
}

template <typename T>
void MyDubList<T>::insert(size_t pos, size_t count, const T& val) {
	if (count == 0) {
		return;
	}
	if (is_empty()) {
		first = last = new Node(val);
		Node* temp = first;
		size = 1;
		while (size < count) {
			temp->next = new Node(val);
			temp = temp->next;
			size += 1;
		}
		last = temp;
	}
	else {
		Node* temp = first;
		size_t i = 2;	//отсчет со второго элемента
		while (i != pos) {
			temp = temp->next;
			i++;
		}
		Node* n = temp->next;
		for (i = 0; i < count; ++i) {
			temp->next = new Node(val);
			temp = temp->next;
			size++;
		}
		temp->next = n;
	}
}

template <typename T>
void MyDubList<T>::insert(size_t pos, const T& val) {
	if (is_empty()) {
		push_back(val);
	}
	else {
		Node* temp = first;
		size_t i = 2;	//отсчет со второго элемента
		while (i < pos) {
			temp = temp->next;
			i++;
		}
		Node* n = new Node(val);
		n->next = temp->next;
		temp->next = n;
	}
	size += 1;
}

template <typename T>
void MyDubList<T>::print()const {
	Node* temp = first;
	do {
		std::cout << temp->val << " ";
		temp = temp->next;
	} while (temp != nullptr);
	std::cout << std::endl;
}
