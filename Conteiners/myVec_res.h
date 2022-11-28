#pragma once

template <typename T>
class MyVecRes {
public:
	MyVecRes();

	explicit MyVecRes(size_t count, const T& val);

	~MyVecRes() {
		delete[]v_ptr;
	}

	void insert(size_t pos, int count, const T& val);

	void insert(size_t pos, const T& val);

	void push_back(const T& val);

	void erase(size_t pos);

	size_t size()const { return size_vec; }

	T& operator [](size_t pos) const {
		return v_ptr[pos];
	}


private:
	T* v_ptr;
	size_t size_vec;
	size_t res;
};

template <typename T> MyVecRes<T>::MyVecRes() {
	size_vec = 0;
	res = 5;
	v_ptr = new T[size_vec+res];
}

template <typename T> MyVecRes<T>::MyVecRes(size_t count, const T& val) : MyVecRes() {
	
	if (count <= res) {
		for (size_t i = 0; i < count; ++i) {
			v_ptr[i] = val;
			res--;
		}
		size_vec = count;
	}
	else {	
		size_vec =res= count;
		delete[]v_ptr;
		v_ptr = new T[size_vec+res];
		for (size_t i = 0; i < count; ++i) {
			v_ptr[i] = val;
		}
	}
}

template <typename T> void  MyVecRes<T>::insert(size_t pos, int count, const T& val) {
	if (pos < 0)
		pos = 0;
	if (pos > size_vec)
		pos = size_vec;
	if (count <= res) {
		T* temp = new T[count];
		for (size_t i = (pos-1),j=0; i < (pos-1 + count); ++i,++j) {
			temp[j] = v_ptr[i];
			v_ptr[i] = val;
		}
		for (size_t i = (pos-1 + count), j = 0; i < (size_vec + count); ++i, j++) {
			v_ptr[i]=temp[j];
		}
		delete[]temp;
		res -=count;
		size_vec += res;
	}
	else {
		res = count;
		T* res_v = new T[size_vec + res];
		for (size_t i = 0; i < pos; ++i) {
			res_v[i] = v_ptr[i];
		}
		for (size_t i = (pos-1); i < (pos-1 + count); ++i) {
			res_v[i] = val;
		}
		for (size_t i = (pos-1 + count); i < (size_vec-res); ++i) {
			res_v[i] = v_ptr[i - count];
		}
		delete[]v_ptr;
		v_ptr = res_v;
		size_vec += count;
	}
}

template <typename T> void  MyVecRes<T>::insert(size_t pos, const T& val) {
	insert(pos, 1, val);
}

template <typename T> void  MyVecRes<T>::push_back(const T& val) {
	if (res) {
		v_ptr[size_vec - res] = val;
		res--;
		size_vec++;
	}
	else {
		res = 5;
		T* res_v = new T[size_vec + res];
		for (size_t i = 0; i < size_vec; ++i) {
			res_v[i] = v_ptr[i];
		}
		res_v[size_vec] = val;
		delete[]v_ptr;
		v_ptr = res_v;
		size_vec ++;
	}
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
	for (size_t i = pos; i < size_vec; ++i) {
		res_v[i] = v_ptr[i + 1];
	}
	delete[]v_ptr;
	v_ptr = res_v;
	size_vec--;
	res++;

}
