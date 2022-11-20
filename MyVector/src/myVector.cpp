#include "myVector.h"

MyVector::MyVector(size_t& count, const T& val = 0) :MyVector() {
	size = count;
	v_ptr = new T[size];
	for (size_t i = 0; i < size; ++i) {
		v_ptr[i] = val;
	}
}

void MyVector::insert(size_t& pos, int count, const T& val) {
	if (pos < 0)
		pos = 0;
	if (pos > size)
		pos = size;
	size += count;
	T* res_v = new T[size];
	for (size_t i = 0; i < pos; ++i) {
		res_v[i] = v_ptr[i];
	}
	for (size_t i = pos; i < (pos + count); ++i) {
		res_v[i] = val;
	}
	for (size_t i = (pos + count); i < size; ++i) {
		res_v[i] = v_ptr[i];
	}
	delete[]v_ptr;
	v_ptr = res_v;
}

void MyVector::insert(size_t& pos, const T& val) :void insert(pos, 1, val) {}

void MyVector::push_back(T val) {
	insert((size - 1), 1, val);
}
void MyVector::erase() {
	delete[]v_ptr;
	v_ptr = nullptr;
}

T& operator MyVector::[](const size_t& val) {}