#pragma once


template <typename T>
class MyVector {
public:
	MyVector ():v_ptr(nullptr),size(0){}

	explicit MyVector(size_t& count, const T& val = 0) :MyVector();

	void insert(size_t& pos, int count, const T& val);

	void insert(size_t& pos, const T& val) :void insert(pos, 1, val);

	void push_back(T val);

	void insert (T val,int count){}

	void erase() {
		delete[]v_ptr;
		v_ptr = nullptr;
	}

	T& operator [](const size_t& val){}

private:
	T* v_ptr;
	size_t size;


};