#include "iostream"
#include "myVector.h"
#include "myList.h"

template <typename T>void print(MyVector <T>& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}


int main() {

	MyVector <int> vec1;
	for (int i = 0; i < 10; ++i) {
		vec1.push_back(i);
	}
	print(vec1);
	std::cout << vec1.size() << std::endl;

	vec1.erase(3);
	std::cout << vec1.size() << std::endl;
	vec1.erase(4);
	std::cout << vec1.size() << std::endl;
	vec1.erase(5);
	std::cout << vec1.size() << std::endl;
	print(vec1);

	vec1.insert(1, 10);
	print(vec1);

	vec1.insert((static_cast <size_t>(vec1.size() / 2)) + 1, 20);
	print(vec1);

	vec1.push_back(30);
	print(vec1);

	return 0;
}


