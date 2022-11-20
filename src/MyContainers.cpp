#include "iostream"
#include "myVector.h"

void print(const MyVector& v) {
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << endl;
}


int main() {

	MyVector <int> vec1;
	print(vec1);
	MyVector <char> vec2(3,'a');
	print(vec2);


	return 0;
}

