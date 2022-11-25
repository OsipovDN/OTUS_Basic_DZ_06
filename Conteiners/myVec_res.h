#pragma once

template <typename T>
class MyVecRes {
public:
	MyVecRes();

	explicit MyVecRes(size_t count, const T& val);

	~MyVectRes() {
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
	size_t res;
};

template <typename T> MyVecRes<T>::MyVecRes() {
	size_vec=res = 5;
	v_ptr = new T[size_vec];
}

template <typename T> MyVecRes<T>::MyVecRes(size_t count, const T& val) : MyVecRes() {
	
	if (count <= size_vec) {
		res = size_vec - count;
		for (size_t i = 0; i < count; ++i) {
			v_ptr[i] = val;
		}
	}
	else {	
		res = count;
		delete[]v_ptr;
		v_ptr = new T[count+res];
		for (size_t i = 0; i < count; ++i) {
			v_ptr[i] = val;
		}
		size_vec = count+res;
	}
}

template <typename T> void  MyVecRes<T>::insert(size_t pos, int count, const T& val) {
	if (pos < 0)
		pos = 0;
	if (pos > (size_vec))
		pos = size_vec;
	if (count <= res) {
		for (size_t i = 0; i < count; ++i) {
			v_ptr[i] = val;
		}
	}
	else {
		res = count;
		T* res_v = new T[size_vec + res];
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
}

template <typename T> void  MyVecRes<T>::insert(size_t pos, const T& val) {
	insert((pos - 1), 1, val);
}

template <typename T> void  MyVecRes<T>::push_back(const T& val) {
	insert((size_vec-res), 1, val);
}
template <typename T> void  MyVecRes<T>::erase(size_t pos) {
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
