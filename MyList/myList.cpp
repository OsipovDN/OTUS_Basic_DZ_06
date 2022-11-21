template <typename T>
class MyList {
	struct Node
	{
		T val;
		Node* next;
	};
public:
	MyList();

	explicit MyList();

	~MyList();

	void insert(size_t pos, int count, const T& val);

	void insert(size_t pos, const T& val);

	void push_back(const T& val);

	void erase(size_t pos);

	size_t size()const { return size_vec; }
};