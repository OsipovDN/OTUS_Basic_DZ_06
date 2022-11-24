#pragma once

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

	explicit MyList(const T& val) :MyList() {
		first = last = new Node(val);
		size += 1;
	}
	explicit MyList(size_t count, const T& val) :MyList() {
		Node*temp = new Node(val);
		first = temp;
		do {
			temp->next = new Node(val);	
		}
		while (size != count);
		last = temp->next;
	}

	~MyList() {
		Node* temp = first,buf;
		while (temp->next!= nullptr) {
			buf = temp->next;
			delete temp;
			temp = buf;
		}
	}

	bool is_empty() {
		return (first == nullptr);
	}

	void push_back(const T& val) {
		Node* temp = new Node(val);
		if (is_empty()) {
			first=last = temp;
			return;
		}
		last->next = temp;
		last = temp;
		size += 1;
	}

	void push_front(const T& val) {
		Node* temp = new Node(val);
		if (is_empty()) {
			first = last = temp;
			return;
		}
		temp->next = first;
		first = temp;
		size += 1;
	}

	size_t size()const { return size; }

	Node* erase(Node* pos) {
		Node* temp = first;
		while (temp != pos) {
			temp = temp->next;
		}
		temp->next = lst->next;
		delete lst;
		return temp;
	}

	void insert(size_t pos, int count, const T& val);
	void insert(size_t pos, const T& val);
};