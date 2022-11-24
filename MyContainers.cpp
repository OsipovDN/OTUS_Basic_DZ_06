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

	/*MyVector <int> vec1;
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
	print(vec1);*/


	MyList <int>lst1(5, 3);
	/*MyList <int>lst1;
	lst1.push_back(2);
	lst1.push_back(3);
	lst1.push_back(4);*/
	size_t val = lst1.get_size();
	std::cout << val << std::endl;
	lst1.print();
	lst1.push_back(4);
	lst1.insert(3, 2);
	val = lst1.get_size();
	std::cout << val << std::endl;
	lst1.print();

	lst1.insert(2, 4, 1);
	val = lst1.get_size();
	std::cout << val << std::endl;
	lst1.print();

	/*lst1.push_front(10);
	val = lst1.get_size();
	std::cout << val << std::endl;
	lst1.print();*/
	return 0;
}


