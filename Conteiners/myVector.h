#pragma once

template <typename T>
class MyVector {
public:
	MyVector();

	explicit MyVector(size_t count, const T& val);

	~MyVector() {
		delete[]v_ptr;
	}

	void insert(size_t pos, int count, const T& val);

	void insert(size_t pos, const T& val);

	void push_back(const T& val);

	void erase(size_t pos);

	size_t size()const { return size_vec; }

	T& operator [](size_t pos) {
		return v_ptr[pos];
	}


private:
	T* v_ptr;
	size_t size_vec;
};

template <typename T> MyVector<T>::MyVector() :v_ptr(nullptr), size_vec(0) {}

template <typename T> MyVector<T>::MyVector(size_t count, const T& val) : MyVector() {
	size_vec = count;
	v_ptr = new T[size_vec];
	for (size_t i = 0; i < size_vec; ++i) {
		v_ptr[i] = val;
	}
}

template <typename T> void  MyVector<T>::insert(size_t pos, int count, const T& val) {
	if (pos < 0)
		pos = 0;
	if (pos > size_vec)
		pos = size_vec;
	T* res_v = new T[size_vec + count];
	for (size_t i = 0; i < pos; ++i) {
		res_v[i] = v_ptr[i];
	}
	for (size_t i = pos; i < (pos + count); ++i) {
		res_v[i] = val;
	}
	for (size_t i = (pos + count); i < (size_vec + count); ++i) {
		res_v[i] = v_ptr[i - count];
	}
	delete[]v_ptr;
	v_ptr = res_v;
	size_vec += count;
}

template <typename T> void  MyVector<T>::insert(size_t pos, const T& val) {
	insert((pos - 1), 1, val);
}

template <typename T> void  MyVector<T>::push_back(const T& val) {
	insert((size_vec), 1, val);
}
template <typename T> void  MyVector<T>::erase(size_t pos) {
	if (pos < 0)
		pos = 0;
	if (pos > size_vec)
		pos = size_vec;
	T* res_v = new T[size_vec - 1];
	for (size_t i = 0; i < pos; ++i) {
		res_v[i] = v_ptr[i];
	}
	for (size_t i = (pos - 1); i < size_vec; ++i) {
		res_v[i] = v_ptr[i + 1];
	}
	delete[]v_ptr;
	v_ptr = res_v;

}