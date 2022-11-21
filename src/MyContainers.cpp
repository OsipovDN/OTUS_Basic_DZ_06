#include "iostream"
#include "myVector.cpp"

template <typename T>void print(MyVector <T>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}


int main() {

	MyVector <int> vec1;
	print(vec1);
	MyVector <char> vec2(3,'x');
	print(vec2);


	return 0;
}

