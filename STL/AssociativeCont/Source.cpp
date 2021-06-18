#include<iostream>
#include<string>
#include<map>
#include<list>
using std::cin;
using std::cout;
using std::endl;
#define MAP
void main()
{
	setlocale(0, "rus");
	using namespace std;
#ifdef MAP
	// Map - это ассоциативный контейнер, то есть, каждый элемент этого контейнера хранит пару "ключ-значение" (key-value);
	// Как ключ так и значение элемнта могут быть любого типа. Их типы могут так совподать, так и отличатся.
	// Map хранит элементы в виде бинарного дерева, отсортированного по ключу.
	// Map и MultiMap отличаются лижь тем что в map могут хранится лишь уникальные ключевые значения, а в MultiMap ключевые значения могут повторятся.
	/*std::multimap<int, std::string> week =
	{
		std::pair<int, std::string>(0, "Sunday"),
		std::pair<int, std::string>(1, "Monday"),
		std::pair<int, std::string>(2, "Tuesday"),
		std::pair<int, std::string>(3, "Wednesday"),
		std::pair<int, std::string>(4, "Thursday"),
		std::pair<int, std::string>(5, "Friday"),
		std::pair<int, std::string>(6, "Saturday"),
	};
	for (std::map<int, std::string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << '\t' << it->second << endl;
	}*/
	map<string, forward_list<string>> dictionary =
	{
		pair<string, forward_list<string>>("finite", {"ограниченный", "имеющий предел"}),
		pair<string, forward_list<string>>("adjacent", {"примыкающий", "смежный", "соседний"}),
		pair<string, forward_list<string>>("plot", {"карта", "план", "график", "сюжет"}),
		pair<string, forward_list<string>>("incident", {"случайность", "происшествие"}),
		pair<string, forward_list<string>>("splice", {"соединение", "сращивание"}),
	};
	//cout << dictionary["finite"] << endl;
	//cout << dictionary["finite"].back() << endl;
	//dictionary["space"].assign({ "пространство", "космос" });
	//dictionary["space"].push_back({ "пустота" });
	for (map<string, forward_list<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << ":";
		for (forward_list<string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			cout << *jt << ", ";
		}
		cout << endl;
	}
	//cout << dictionary.find("finite")->first << endl;
	//for (string i : dictionary.find("finite")->second)cout << i << '\t'; cout << endl;
#endif // MAP
}