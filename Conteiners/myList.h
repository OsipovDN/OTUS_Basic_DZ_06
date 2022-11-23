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

	~MyList();

	void insert(size_t pos, int count, const T& val);
	void insert(size_t pos, const T& val);

	bool is_empty() {
		return (first == nullptr);
	}

	void push_back(const T& val) {
		Node* ref = new Node(val);
		if (is_empty()) {
			first=last = ref;
			return;
		}
		last->next = ref;
		last = ref;
		size += 1;
	}

	size_t size()const { return size; }

	void erase(Node* pos) {
		Node* temp = first;
		while (temp != pos) {
			temp = temp->next;
		}
		temp->next = lst->next;
		delete lst;
	}
};