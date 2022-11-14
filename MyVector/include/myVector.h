#pragma once


template <typename T>
class MyVector {
public:
	explicit MyVector (){}

	void push_back (T val){
		insert(val, (size - 1));
	}

	void insert (T val,int count){}

	void erase() {
		delete[]v_ptr;
		v_ptr = nullptr;
	}

	T& operator [](const size_t val){}

private:
	T* v_ptr;
	size_t size;


};