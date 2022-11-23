#pragma once

template <typename T>
class MyList {
	struct Node
	{
		T val;
		Node* next;
	};
	Node* first;
	Node* last;
	size_t count;
public:
	MyList() :first(nullptr), last(nullptr), count(0) {}

	explicit MyList(const T& val) :MyList() {
		count = 1;
		first = last = new Node;
		first->Node::val = val;
		first->Node::next= nullptr;
	}

	~MyList();

	void insert(size_t pos, int count, const T& val);

	void insert(size_t pos, const T& val);

	void push_back(const T& val);

	void erase(size_t pos);

	size_t size()const { return size_vec; }
};