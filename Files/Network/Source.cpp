#include<iostream>
#include<fstream>
#include<string>
#include<Windows.h>
#include<algorithm>
#include<direct.h>
using namespace std;

//#define WAL // Wake On Lan

void main()
{
	setlocale(0, "Rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

#ifdef WAL

	string source_file_name;
	string destination_file_name;
	string ext = ".txt";

	cout << "¬ведите им€ исходного файла: "; getline(cin, source_file_name);
	cout << "¬ведите им€ конечного файла: "; getline(cin, destination_file_name);

	if (source_file_name.find(ext) == string::npos) source_file_name += ext;
	if (destination_file_name.find(ext) == string::npos)destination_file_name += ext;

	ifstream fin(source_file_name);

	//int a, b;
	//char s;
	//cout << "¬ведите выражение: "; cin >> a >> s >> b;
	//cout << a << s << b << endl;
	/*string last_name, first_name, middle_name;
	cout << "¬ведите ‘»ќ: ";
	cin >> last_name >> first_name >> middle_name;
	cout << last_name << " " << first_name << " " << middle_name << endl;*/

	string IP;
	string MAC;

	if (fin.is_open())
	{
		ofstream fout(destination_file_name);
		while (fin >> IP >> MAC)
		{
			cout << MAC << '\t' << IP << endl;
			fout << MAC << '\t' << IP << endl;
		}
		fout.close();
		string cmd = "notepad" + destination_file_name;
		system(cmd.c_str());
	}
	else
	{
		cerr << "Error: File not found!" << endl;
	}

	fin.close();
#endif // WAL
	string room_number;
	cout << "¬вод: "; cin >> room_number;

	string directory = "File";
	_chdir(directory.c_str());ц

	string source_file_name = room_number + " RAW.txt";
	string dhcpd_file_name = room_number + ".dhcpd";
	string wal_file_name = room_number + ".wal";
	string mac, ip;

	ifstream fin(source_file_name);
	if (fin.is_open())
	{
		ofstream dhpcd_fout(dhcpd_file_name);
		ofstream wal_fout(wal_file_name);
		for (int i = 1; fin >> ip >> mac; i++)
		{
			wal_fout << mac << '\t' << ip << endl;
			replace(mac.begin(), mac.end(), '-', ':');
			cout << "host 201-" << i << endl;
			cout << "{\n";
			cout << "\thardware ethernet\t" << mac << ";\n";
			cout << "\tfixed-address\t\t" << ip << ";\n";
			cout << "}\n";
			cout << endl;

			dhpcd_fout << "host 201-" << i << endl;
			dhpcd_fout << "{\n";
			dhpcd_fout << "\thardware ethernet\t" << mac << ";\n";
			dhpcd_fout << "\tfixed-address\t\t" << ip << ";\n";
			dhpcd_fout << "}\n";
			dhpcd_fout << endl;
		}
		//string cmd = "notepad " + dhcpd_file_name;
		string cmd = "start notepad ";
		system((cmd + wal_file_name).c_str());
		system((cmd + dhcpd_file_name).c_str());
	}
	else
	{
		cout << "Error: File not found" << endl;
	}
	fin.close();
}