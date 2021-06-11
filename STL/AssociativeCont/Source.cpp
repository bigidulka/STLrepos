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
	// Map - ��� ������������� ���������, �� ����, ������ ������� ����� ���������� ������ ���� "����-��������" (key-value);
	// ��� ���� ��� � �������� ������� ����� ���� ������ ����. �� ���� ����� ��� ���������, ��� � ���������.
	// Map ������ �������� � ���� ��������� ������, ���������������� �� �����.
	// Map � MultiMap ���������� ���� ��� ��� � map ����� �������� ���� ���������� �������� ��������, � � MultiMap �������� �������� ����� ����������.
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
	map<string, list<string>> dictionary =
	{
		pair<string, list<string>>("finite", {"������������", "������� ������"}),
		pair<string, list<string>>("adjacent", {"�����������", "�������", "��������"}),
		pair<string, list<string>>("plot", {"�����", "����", "������", "�����"}),
		pair<string, list<string>>("incident", {"�����������", "������������"}),
		pair<string, list<string>>("splice", {"����������", "����������"}),
	};
	//cout << dictionary["finite"] << endl;
	cout << dictionary["finite"].back() << endl;
	dictionary["space"].assign({ "������������", "������" });
	dictionary["space"].push_back({ "�������" });
	for (map<string, list<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		cout << it->first << ":";
		cout.width(20);
		for (list<string>::iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{	
			cout << *jt << ", ";
		}
		cout << endl;
	}
	cout << dictionary.find("finite")->first << endl;
	for (string i : dictionary.find("finite")->second)cout << i << '\t'; cout << endl;
#endif // MAP
}