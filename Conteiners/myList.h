#pragma once
#include <iostream>

template <typename T>
class MyList {
	struct Node
	{
		T val;
		Node* next;
		Node(const T& count) :val(count), next(nullptr){}
	};
	Node* first;
	Node* last;
	size_t size;
public:
	MyList() :first(nullptr), last(nullptr), size(0) {}
	explicit MyList(const T& val);
	explicit MyList(size_t count, const T& val);
	~MyList();
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
MyList<T>::MyList(const T& val) :MyList() {
	first = last = new Node(val);
	size += 1;
}
template <typename T>
MyList<T>::MyList(size_t count, const T& val) :MyList() {
	if (count == 0)
		return;
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

template <typename T>
MyList<T>::~MyList() {
	Node* temp = first;
	Node* buf;
	while (temp->next != nullptr) {
		buf = temp->next;
		delete temp;
		temp = buf;
	}
}

template <typename T>
bool MyList<T>::is_empty()const {
	return (first == nullptr);
}

template <typename T>
void MyList<T>::push_back(const T& val) {
	Node* temp = new Node(val);
	if (is_empty()) {
		first = last = temp;
		size += 1;
		return;
	}
	last->next = temp;
	last = temp;
	size += 1;
}

template <typename T>
void MyList<T>::push_front(const T& val) {
	Node* temp = new Node(val);
	if (is_empty()) {
		first = last = temp;
		return;
	}
	temp->next = first;
	first = temp;
	size += 1;
}

template <typename T>
typename MyList<T>::Node* MyList<T>::erase(Node* pos) {
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
void MyList<T>::insert(size_t pos, size_t count, const T& val) {
	if (count == 0)
		return;
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
		size_t i = 2;	//������ �� ������� ��������
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
void MyList<T>::insert(size_t pos, const T& val) {
	if (is_empty())
		push_back(val);
	else {
		Node* temp = first;
		size_t i = 2;	//������ �� ������� ��������
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
void MyList<T>::print()const {
	Node* temp = first;
	do {
		std::cout << temp->val << " ";
		temp = temp->next;
	} while (temp != nullptr);
	std::cout << std::endl;
}
