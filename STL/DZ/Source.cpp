#define DZ1
//#define DZ2

#ifdef DZ1
#include<iostream>
#include<string>
#include<list>
#include<forward_list>
#include<map>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

void print(const map<string, forward_list<string>>& mp)
{
	cout << endl;
	for (map<string, forward_list<string>>::const_iterator it = mp.begin(); it != mp.end(); it++)
	{
		cout << it->first << ":\t";
		for (forward_list<string>::const_iterator jt = it->second.begin(); jt != it->second.end(); jt++)
		{
			cout << *jt << ", ";
		}
		cout << endl;
	}
	cout << endl;
}
void print_num(const map<string, forward_list<string>>& base)
{
	string auto_num;
	do
	{
		cout << "������� �����: "; cin >> auto_num;
		if (base.count(auto_num) == 0) cout << "������ ������ ���!" << endl;
	} while (base.count(auto_num) == 0);
	cout << endl << base.find(auto_num)->first << ": ";
	for (string i : base.find(auto_num)->second)cout << i << ", "; cout << endl << endl;
}
void add_crime(map<string, forward_list<string>>& base)
{
	string auto_num, cause;
	do
	{
		cout << "������� ����� ������: "; cin >> auto_num;
		if (base.count(auto_num) == 0) cout << "������ ������ ���!" << endl;
	} while (base.count(auto_num) == 0);
	cout << "������� ���������: "; cin.ignore(); getline(cin, cause);
	base[auto_num].push_front(cause);
}
void add_auto(map<string, forward_list<string>>& base)
{
	forward_list<string> causes;
	string auto_num, cause;
	int fine_num;
	cout << "������� ����� ������: "; cin >> auto_num;
	cout << "������� ���-�� ���������: "; cin >> fine_num;
	if (fine_num != 0)
	{
		cout << "������� �������� ���������" << endl;
		for (int i = 0; i < fine_num; i++)
		{
			cout << i + 1 << ". ";
			cin >> cause;
			causes.push_front(cause);
		}
	}
	base.insert(pair<string, forward_list<string>>(auto_num, causes));
}
void dip(map<string, forward_list<string>>& base)
{
	string dip1, dip2;
	do
	{
		cout << "������� ����� ������ ������: "; cin >> dip1;
		if (base.count(dip1) == 0) cout << "������ ������ ���!" << endl;
	} while (base.count(dip1) == 0);
	do
	{
		cout << "������� ����� ������ ������: "; cin >> dip2;
		if (base.count(dip2) == 0) cout << "������ ������ ���!" << endl;
	} while (base.count(dip2) == 0);
}

void main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int switch_on;
	do
	{
		map<string, forward_list<string>> list_penalties =
		{
			pair<string, forward_list<string>>("�543��",{"�����", "������� ����"}),
			pair<string, forward_list<string>>("�543��",{"�����", "������� ����"}),
			pair<string, forward_list<string>>("�543��",{"�����", "������� ����"}),
			pair<string, forward_list<string>>("�543��",{"�����", "������� ����"}),
			pair<string, forward_list<string>>("�543��",{"�����", "������� ����"}),
			pair<string, forward_list<string>>("a543av",{"�����", "������� ����"}),
			pair<string, forward_list<string>>("�543��",{"�����", "������� ����"})
		};
		cout << "�������� ��������: " << endl;
		cout << "1. �������� ����� �����" << endl;
		cout << "2. �������� ��������� � ������" << endl;
		cout << "3. ������� ���" << endl;
		cout << "4. ������� �� ������" << endl;
		cout << "5. ������� �� ��������� �������" << endl;
		cout << "6. �����" << endl;
		do
		{
			cout << "����: ";
			cin >> switch_on;
			if (switch_on < 1 || switch_on > 6) cout << "��� ���!" << endl;
		} while (switch_on < 1 || switch_on > 6);

		switch (switch_on)
		{
		case 1:
			add_auto(list_penalties);
			break;
		case 2:
			add_crime(list_penalties);
			break;
		case 3:
			print(list_penalties);
			break;
		case 4:
			print_num(list_penalties);
			break;
		case 5:
			dip(list_penalties);
			break;
		case 6:
			break;
		}
	} while(switch_on != 6);
}
#endif // DZ1
#ifdef DZ2
#include<iostream>
#include<string>
#include<list>
#include<forward_list>
#include<map>
#include<Windows.h>
using namespace std;
#define DEL "\n----------------------------------------------------------\n"
void print_base(map<string, forward_list<string>>& base);
void add_crime(map<string, forward_list<string>>& base);
void crimes_of(string, const map<string, forward_list<string>>& base);
void main()
{
	setlocale(0, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<string, forward_list<string>> base =
	{
		pair<string, forward_list<string>>("�123��777", {"������ �� �������", "���������� ��������"}),
		pair<string, forward_list<string>>("�124��777", {"�������� � ������������ �����"}),
		pair<string, forward_list<string>>("�555��777", {"���������� ��������"}),
		pair<string, forward_list<string>>("�555��178", {"������ �� �������", "������ ��������"}),
	};
	print_base(base);
	/*add_crime(base);
	print_base(base);*/
	string id;
	cout << "������� ����� ����������: "; cin >> id;
	crimes_of(id, base);
}
void print_base(map<string, forward_list<string>>& base)
{
	for (map<string, forward_list<string>>::const_iterator it = base.begin(); it != base.end(); it++)
	{	
		cout << it->first << ":\t";
		for (forward_list<string>::const_iterator l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			cout << *l_it << ", ";
		}
		cout << "\b \b";
		cout << "\b \b";
		cout << ";";
		cout << DEL;
	}
}
void add_crime(map<string, forward_list<string>>& base)
{
	string id;
	string crime;
	cout << "������� ����� ����������: "; cin >> id;
	cout << "������� ���������: ";
	cin.ignore();
	getline(cin, crime);
	base[id].push_front(crime);
}
void crimes_of(string id, const map<string, forward_list<string>>& base)
{
	map<string, forward_list<string>>::const_iterator criminal = base.find(id);
	if (criminal != base.end())
	{
		cout << "������ ��������� " << id << ":\t";
		for (forward_list<string>::const_iterator it = criminal->second.begin(); it != criminal->second.end(); it++)
		{
			cout << *it << ", ";
		}
		cout << endl;
	}
}
#endif // DZ2