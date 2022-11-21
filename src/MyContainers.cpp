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
	for (int i = 0; i < 10; ++i) {
		vec1.push_back(i);
	}
	print(vec1);
	std::cout << vec1.size() << std::endl;

	vec1.erase(3);
	vec1.erase(5);
	vec1.erase(7);
	print(vec1);

	vec1.insert(1, 10);
	print(vec1);

	vec1.insert((static_cast <size_t>(vec1.size() / 2)), 20);
	print(vec1);

	vec1.push_back(30);
	print(vec1);



	MyVector <char> vec2(3, 'x');
	print(vec2);
	return 0;
}

