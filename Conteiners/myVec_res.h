#pragma once

template <typename T>
class MyVecRes {
public:
	MyVecRes();

	explicit MyVecRes(size_t count, const T& val);
	~MyVecRes() {delete[]v_ptr;}
	void insert(size_t pos, int count, const T& val);
	void insert(size_t pos, const T& val);
	void push_back(const T& val);
	void erase(size_t pos);
	size_t size()const { return size_vec; }
	size_t capacity()const { return cap; }
	T& operator [](size_t pos) const {return v_ptr[pos];}


private:
	T* v_ptr;
	size_t size_vec;
	size_t cap;
};

template <typename T> 
MyVecRes<T>::MyVecRes() {
	size_vec = 0;
	cap = 5;
	v_ptr = new T[cap];
}

template <typename T>
MyVecRes<T>::MyVecRes(size_t count, const T& val) : MyVecRes() {
	if (count <= cap) {
		for (size_t i = 0; i < count; ++i) {
			v_ptr[i] = val;
		}
		size_vec = count;
	}
	else {	
		delete[]v_ptr;
		cap= count*2;
		size_vec = count;
		v_ptr = new T[cap];
		for (size_t i = 0; i < count; ++i) {
			v_ptr[i] = val;
		}
	}
}

template <typename T> 
void  MyVecRes<T>::insert(size_t pos, int count, const T& val) {
	T* temp = nullptr;
	if (pos < 0)
		pos = 0;
	if (pos > size_vec)
		pos = size_vec;
	size_vec += count;
	cap = size_vec+count*2;
	temp = new T[cap];
	for (size_t i = 0; i < pos; ++i) {
		temp[i] = v_ptr[i];
	}
	for (size_t i = pos; i < (pos + count); ++i) {
		temp[i] = val;
	}
	for (size_t i = (pos + count); i < size_vec; ++i) {
		temp[i] = v_ptr[i - count];
	}
	delete[]v_ptr;
	v_ptr = temp;
}

template <typename T> 
void  MyVecRes<T>::insert(size_t pos, const T& val) {
	insert((pos-1), 1, val);
}

template <typename T> 
void  MyVecRes<T>::push_back(const T& val) {
	if (size_vec!=cap) {
		v_ptr[size_vec] = val;
		size_vec++;
	}
	else {
		insert(size_vec, 1, val);
	}
}
template <typename T> 
void  MyVecRes<T>::erase(size_t pos) {
	if (pos < 0)
		pos = 0;
	if (pos > size_vec)
		pos = size_vec;
	T temp = v_ptr[pos];
	for (size_t i = pos; i < size_vec;++i) {
		v_ptr[i - 1] = temp;
		temp = v_ptr[i+1];
	}
	size_vec -= 1;

}
