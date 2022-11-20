#include "myVector.h"

template <typename T> MyVector<T>::MyVector() :v_ptr(nullptr), size(0) {}

template <typename T> MyVector<T>::MyVector(size_t count, const T& val = 0) : MyVector() {
	size = count;
	v_ptr = new T[size];
	for (size_t i = 0; i < size; ++i) {
		v_ptr[i] = val;
	}
}

template <typename T> void  MyVector<T>::insert(size_t pos, int count, const T& val) {
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

template <typename T> void  MyVector<T>::insert(size_t pos, const T& val) {
	insert(pos, 1, val);
}

template <typename T> void  MyVector<T>::push_back(const T& val) {
	insert((size - 1), 1, val);
}
template <typename T> void  MyVector<T>::erase() {
	delete[]v_ptr;
	v_ptr = nullptr;
}

