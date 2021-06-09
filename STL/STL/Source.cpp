#include<iostream>
#include<array>
#include<vector>
using namespace std;

#define DELIM "\n----------------------------------------------------------------------------------------------\n"

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_VECTOR_INSERT
//#define VECTOR_SWAP
#define STL_VECTOR_ERASE

template<typename T>void vector_properties(const vector<T>& vec);
template<typename T>void print_vector(const vector<T>& vec);
template<typename T>void reverse_print_vector(const vector<T>& vec);

void main()
{
	setlocale(0, "Rus");
#ifdef STL_ARRAY
	// array - ��� ���������, ������� ������ ������ � ���� ������������ �������.
	array<int, 5> arr = { 3,5,8,13,21 };
	for (int i = 0; i < arr.size(); i++)
	{
		//cout << arr[i] << '\t';
		cout << arr.at(i) << '\t';
	}
	cout << endl;
	cout << arr.front() << endl;
	cout << arr.back() << endl;
	cout << *arr.data() << endl;
	arr.fill(123);
	for (int i : arr)
		cout << i << '\t';
	cout << endl;
#endif // STL_ARRAY
#ifdef STL_VECTOR
	//vector - ��� ���������, ������� ������ ������ � ���� ������������� ������.
	vector<int> vec = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	vec.push_back(55);
	vector_properties(vec);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec1[i] << '\t';
			cout << vec.at(i) << '\t';
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	vec.reserve(45);
	//vec.shrink_to_fit();
	vector_properties(vec);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << '\t';
	}
	cout << endl;
	cout << DELIM;
	vec.assign({ 1024,2048,3072 });
	print_vector(vec);
	vector_properties(vec);
#endif // STL_VECTOR
#ifdef STL_VECTOR_INSERT
	int index;
	int count;
	int value;
	do 
	{
		cout << "������� ������: "; cin >> index;
		if (index > vec.size())cout << "����� ������\n";
	} while (index > vec.size());
	cout << "������� ���������� ����������� ���������: "; cin >> count;
	cout << "������� ��������: "; cin >> value;
	vector<int>::iterator position = vec.begin() + index;
	vec.insert(position, count, value);
	for (int i : vec)
		cout << i << '\t';
	cout << endl;
	vector_properties(vec);
	vec.insert(vec.begin() + 8, vec.begin() + 2, vec.begin() + 5);
	for (int i : vec)cout << i << '\t'; cout << endl;
#endif // STL_VECTOR_INSERT
	/*cout << DELIM;
	vec.insert(vec.begin() + 5, { 1024,2048, 3072, 4098 });
	print_vector(vec);
	vector_properties(vec);
	cout << "������ ������ ��������: " << sizeof(vec) << " ����";
	cout << DELIM;
	vector<int> vec2;
	cout << "������ ������ ��������: " << sizeof(vec2) << " ����";*/
#ifdef VECTOR_SWAP
	vector<int> vec1 = { 3,5,8,13,21 };
	vector<int> vec2 = { 34,55,89 };
	print_vector(vec1);
	print_vector(vec2);
	vec1.swap(vec2);
	print_vector(vec1);
	print_vector(vec2);
#endif // VECTOR_SWAP
#ifdef STL_VECTOR_ERASE
	vector<int> vec = { 3, 5, 8, 13, 21, 34, 55};
	print_vector(vec);
	reverse_print_vector(vec);
	/*int index;
	cout << "������� ������ ���������� ��������: "; cin >> index;
	vector<int>::iterator position = vec.begin() + index;
	vec.erase(position);*/
	int index_start, index_end;
	cout << "������� ������ � ����� ���������� ���������: "; cin >> index_start >> index_end;
	vec.erase(vec.begin() + index_start, vec.begin() + index_end);
	print_vector(vec);
	//vector_properties(vec);
#endif // STL_VECTOR_ERASE
}
template<typename T>void vector_properties(const vector<T>& vec)
{
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "Max size:\t" << vec.max_size() << endl;
}
template<typename T>void print_vector(const vector<T>& vec)
{
	//for (int i : vec)cout << i << '\t'; cout << endl;
	for (/*auto*/ vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		cout << *it << '\t';
	}
	cout << endl;
}
template<typename T>void reverse_print_vector(const vector<T>& vec)
{
	for (vector<int>::const_reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
	{
		cout << *it << '\t';
	}
	cout << endl;
}