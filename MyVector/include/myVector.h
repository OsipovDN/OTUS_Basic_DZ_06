#pragma once

template <typename T>
class MyVector {
public:
	MyVector();

	MyVector(size_t count, const T& val = 0);

	void insert(size_t pos, int count, const T& val);

	void insert(size_t pos, const T& val);

	void push_back(const T& val);

	void erase();

	T& operator [](const size_t& val) {
		return v_ptr[val];
	}

private:
	T* v_ptr;
	size_t size;
};