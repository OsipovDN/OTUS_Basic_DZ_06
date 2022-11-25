#include "iostream"
#include "myVector.h"
#include "myVec_res.h"
#include "myList.h"

namespace conteiners {
	template <typename T>void print(MyVector <T>& v) {
		for (size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}


	void vector() {
		//Инициализация пустого вектора и заполнение через push_back
		MyVector <int> vec1;
		for (int i = 0; i < 10; ++i) {
			vec1.push_back(i);
		}
		print(vec1);
		std::cout << vec1.size() << std::endl;

		//Удаление третьего,пятого и седьмого элемента
		vec1.erase(3);
		std::cout << vec1.size() << std::endl;
		vec1.erase(4);
		std::cout << vec1.size() << std::endl;
		vec1.erase(5);
		std::cout << vec1.size() << std::endl;
		print(vec1);

		//Добавление элемента 10 в начало вектора
		vec1.insert(1, 10);
		print(vec1);

		//Добавление числа 20 в середину контейнера
		vec1.insert((static_cast <size_t>(vec1.size() / 2)) + 1, 20);
		print(vec1);

		//Добавление элемента 30 в конец вектора
		vec1.push_back(30);
		print(vec1);
	}

	void listCont() {
		//инициализация конструктора для создания n int узлов со значением 3
		MyList <int>lst(5, 3);
		//Размер контейнера
		size_t val = lst.get_size();
		std::cout << val << std::endl;
		lst.print();

		//инициализация пустого контейнера int и заполнение через push_back
		MyList <int>lst1;
		lst1.push_back(2);
		lst1.push_back(3);
		lst1.push_back(4);
		size_t val = lst1.get_size();
		std::cout << val << std::endl;
		lst1.print();

		//Добавление элемента 2 в позицию 3
		lst1.insert(3, 2);
		val = lst1.get_size();
		std::cout << val << std::endl;
		lst1.print();

		//Добавление в позицию 2 четырех элементов 1
		lst1.insert(2, 4, 1);
		val = lst1.get_size();
		std::cout << val << std::endl;
		lst1.print();

		//Добавление элемента в начало списка
		lst1.push_front(10);
		val = lst1.get_size();
		std::cout << val << std::endl;
		lst1.print();
	}
}

int main() {
	
	conteiners::vector();
	conteiners::listCont();

	

	return 0;
}


