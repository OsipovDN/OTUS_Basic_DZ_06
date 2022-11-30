#include "iostream"
#include "myVector.h"
#include "myVec_res.h"
#include "myList.h"
#include "myDubList.h"

namespace conteiners {
	template <typename T>
	void print(MyVector <T>& v) {
		for (size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}
	template <typename T>
	void print(MyVecRes <T>& v) {
		for (size_t i = 0; i < v.size(); ++i) {
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
	}


	void vector() {
		std::cout << "������������� ������� ������� � ���������� ����� push_back" << std::endl;
		MyVector <int> vec1;
		for (int i = 0; i < 10; ++i) 
			vec1.push_back(i);
		print(vec1);
		std::cout << vec1.size() << std::endl;

		std::cout << "�������� ��������, ������ � �������� ��������" << std::endl;
		vec1.erase(3);
		std::cout << vec1.size() << std::endl;
		vec1.erase(4);
		std::cout << vec1.size() << std::endl;
		vec1.erase(5);
		std::cout << vec1.size() << std::endl;
		print(vec1);

		std::cout << "���������� �������� 10 � ������ �������" << std::endl;
		vec1.insert(1, 10);
		print(vec1);

		std::cout << "���������� ����� 20 � �������� ����������" << std::endl;
		vec1.insert((static_cast <size_t>(vec1.size() / 2)) + 1, 20);
		print(vec1);

		std::cout << "���������� �������� 30 � ����� �������" << std::endl;
		vec1.push_back(30);
		print(vec1);
		std::cout << std::endl;
	}

	void listCont() {
		std::cout << "������������� ������������ ��� �������� n int ����� �� ��������� 3" << std::endl;
		MyList <int>lst(5, 3);
		std::cout << "������ ����������" << std::endl;
		std::cout << "Size = " << lst.get_size() << std::endl;
		lst.print();

		std::cout << "������������� ������� ���������� int � ���������� ����� push_back" << std::endl;
		MyList <int>lst1;
		lst1.push_back(2);
		lst1.push_back(3);
		lst1.push_back(4);
		std::cout<<"Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� �������� 2 � ������� 3" << std::endl;
		lst1.insert(3, 2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� � ������� 2 ������� ��������� 1" << std::endl;
		lst1.insert(2, 4, 1);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� �������� � ������ ������" << std::endl;
		lst1.push_front(10);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "�������� 2-��� �������� �� ������" << std::endl;
		lst1.erase(2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();
		std::cout << std::endl;
	}

	void vector_res() {
		std::cout << "������������� ������� ������� � ���������� ����� push_back" << std::endl;
		MyVecRes <int> vec1;
		std::cout << vec1.size() << std::endl << std::endl;

		for (int i = 0; i < 10; ++i) {
			vec1.push_back(i);
			std::cout << vec1.size() << std::endl;
		}
		print(vec1);
		std::cout << vec1.size() << std::endl << std::endl;

		std::cout << "�������� ��������,������ � �������� ��������" << std::endl;
		vec1.erase(3);
		std::cout << vec1.size() << std::endl;
		vec1.erase(4);
		std::cout << vec1.size() << std::endl;
		vec1.erase(5);
		std::cout << vec1.size() << std::endl;
		print(vec1);

		std::cout << "���������� �������� 10 � ������ �������" << std::endl;
		vec1.insert(1, 10);
		print(vec1);

		std::cout << "���������� ����� 20 � �������� ����������" << std::endl;
		vec1.insert((static_cast <size_t>(vec1.size() / 2)) + 1, 20);
		print(vec1);

		std::cout << "���������� �������� 30 � ����� �������" << std::endl;
		vec1.push_back(30);
		print(vec1);
		std::cout << std::endl;
	}

	void DublistCont() {
		std::cout << "������������� ������������ ��� �������� n int ����� �� ��������� 3" << std::endl;
		MyDubList <int>lst(5, 3);
		std::cout << "������ ����������" << std::endl;
		std::cout << "Size = " << lst.get_size() << std::endl;
		lst.print();

		std::cout << "������������� ������� ���������� int � ���������� ����� push_back" << std::endl;
		MyList <int>lst1;
		lst1.push_back(2);
		lst1.push_back(3);
		lst1.push_back(4);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� �������� 2 � ������� 3" << std::endl;
		lst1.insert(3, 2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� � ������� 2 ������� ��������� 1" << std::endl;
		lst1.insert(2, 4, 1);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "���������� �������� � ������ ������" << std::endl;
		lst1.push_front(10);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();

		std::cout << "�������� 2-��� �������� �� ������" << std::endl;
		lst1.erase(2);
		std::cout << "Size = " << lst1.get_size() << std::endl;
		lst1.print();
		std::cout << std::endl;
	}


	void iterVec() {
		MyVector <int> vec1;
		MyVector <int>::Iterator it_ptr;
		for (int i = 0; i < 10; ++i) 
			vec1.push_back(i);
		for (it_ptr = vec1.begin(); it_ptr != vec1.end(); ++it_ptr) 
			std::cout << *it_ptr << " ";
	}
}

int main() {
	
	system("chcp 1251>nul");
	conteiners::vector();
	conteiners::listCont();
	conteiners::DublistCont();
	//conteiners::vector_res();
	conteiners::iterVec();

	

	return 0;
}


