#include<iostream>
#include<list>
#include<forward_list>
using namespace std;
#define DEL "\n-----------------------------------------------------------------\n"
//#define LIST
//#define LIST_MERGING
#define FORWARD_LIST
template<typename T> void list_properties(const list<T>& lst)
{
	cout << "Size:      " << lst.size() << endl;
	cout << "Max Size:  " << lst.max_size() << endl;
}
template<typename T> void print_list(const list<T>& lst)
{
	if (lst.empty())
	{
		cout << "List is empty" << endl;
		return;
	}
	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << '\t';
	}
	cout << endl;
	//for (int i : lst)cout << i << '\t'; cout << endl;
}
template<typename T>void reverse_print_list(const list<T>& lst)
{
	for (list<int>::const_reverse_iterator it = lst.crbegin(); it != lst.crend(); it++)
	{
		cout << *it << '\t';
	}
	cout << endl;
}
class list_wrapper
{
	list<int> lst;
};
bool more_than_10(const int& value)
{
	return value > 10;
}

void main()
{
	setlocale(0, "Rus");
#ifdef LIST
	//list - это контейнер, который хранит данные в виде двусв€зного списка.
	list<int> lst = { 3,5,8,13,21 };
	cout << "Empty list size: " << sizeof(list_wrapper) << endl;
	list_properties(lst);
	print_list(lst);
	reverse_print_list(lst);
	cout << endl;
	lst.push_front(2);
	lst.push_back(34);
	list_properties(lst);
	
	int index;
	int value;
	cout << "¬ведите индекс: "; cin >> index;
	cout << "¬ведите значение: "; cin >> value;
	list<int>::iterator position = lst.begin();
	for (int i = 0; i < index; i++) position++;
	lst.insert(position, value);
	//print_list(lst);
	for (list<int>::	iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << '\t';
		*it = rand() % 10;
	}
	cout << endl;
	cout << DEL;
	lst.sort();
	for (int i : lst)cout << i << '\t'; cout << endl;
	lst.unique();
	for (int i : lst)cout << i << '\t'; cout << endl;
	cout << DEL;
	lst.reverse();
	cout << DEL;
	for (int i : lst)cout << i << '\t'; cout << endl;
	/*lst.resize(25);
	lst.remove(30);
	lst.remove_if(more_than_10);*/
	/*for (int i = 0; i < lst.size(); i++)
	{
		cout << lst << '\t';
	}
	cout << endl;*/
#endif // LIST
#ifdef LIST_MERGING
	list<int> lst1 = { 3,5,8,13,21 };
	list<int> lst2 = { 34,55,89 };
	//lst1.merge(lst2);
	lst2.merge(lst1);
	print_list(lst1);
	print_list(lst2);
#endif // LIST_MERGING
#ifdef FORWARD_LIST
	forward_list<int> flst = { 3, 5, 8 ,13 ,21 };
	flst.push_front(34);
	for (int i : flst)cout << i << '\t'; cout << endl;
	int index;
	int value;
	cout << "»ндекс: "; cin >> index;
	cout << "«начение: "; cin >> value;
	forward_list<int>::iterator position = flst.before_begin();
	for (int i = 0; i < index - 1; i++) position++;
	flst.insert_after(position, value);
	for (int i : flst)cout << i << '\t'; cout << endl;
#endif // FORWARD_LIST
}