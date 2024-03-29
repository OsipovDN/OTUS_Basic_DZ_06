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
	explicit MyDubList(const size_t& count, const T& val);
	~MyDubList();
	bool is_empty()const;
	void push_back(const T& val);
	void push_front(const T& val);
	size_t get_size()const { return size; }
	void erase(const size_t& pos);
	void insert(const size_t& pos, size_t count, const T& val);
	void insert(const size_t& pos, const T& val);
	void print()const;
};


template <typename T>
MyDubList<T>::MyDubList(const T& val) :MyDubList() {
	first = last = new Node(val);
	size += 1;
}
template <typename T>
MyDubList<T>::MyDubList(const size_t& count, const T& val) : MyDubList() {
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
template <typename T>
void MyDubList<T>::erase(const size_t& pos) {
	Node* temp = first;
	Node* n = nullptr;
	size_t i = 2; //������ �� ������� ��������
	while (i < pos) {
		temp = temp->next;
		i++;
	}
	n = temp->next;
	temp->next = n->next;
	temp = n->next;
	temp->prev = n->prev;
	delete n;
	size -= 1;
}

template <typename T>
void MyDubList<T>::insert(const size_t& pos, size_t count, const T& val) {
	Node* temp=nullptr;
	Node* n = nullptr;
	Node* p = nullptr;
	if (count == 0) {
		return;
	}
	if (is_empty()) {
		first = last = new Node(val);
		temp = first;
		size = 1;
		while (size < count) {
			temp->next = new Node(val);
			n = temp;
			temp = temp->next;
			temp->prev = n;
			size += 1;
		}
		last = temp;
	}
	else {
		temp = first;
		size_t i = 2;	//������ �� ������� ��������
		while (i != pos) {
			temp = temp->next;
			i++;
		}	
		for (i = 0; i < count; ++i) {
			p = temp->next;
			temp->next = new Node(val);
			n = temp->next;
			n->prev = temp;
			n->next = p;
			p->prev = n;
			size+=1;
		}
	}
}

template <typename T>
void MyDubList<T>::insert(const size_t& pos, const T& val) {
	Node* temp = nullptr;
	Node* n = nullptr;
	Node* p= nullptr;
	if (is_empty()|| pos==size) {
		push_back(val);
	}
	else {
		temp = first;
		size_t i = 2;	//������ �� ������� ��������
		while (i < pos) {
			temp = temp->next;
			i++;
		}
		n = new Node(val);
		p = temp->next;
		p->prev = n;
		n->next=p;
		n->prev = temp;
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
	temp = last;
	do {
		std::cout << temp->val << " ";
		temp = temp->prev;
	} while (temp != nullptr);
	std::cout << std::endl;
}
