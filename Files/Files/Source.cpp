#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(0, "Rus");
#ifdef  WRITE_TO_FILE
	cout << "HelloWorld";
	ofstream fout;
	fout.open("File.txt", ios_base::app);
	fout << "Hello World" << endl;
	fout.close();
	system("notepad File.txt");
#endif //  WRITE_TO_FILE
#ifdef READ_FROM_FILE
	ifstream fin;
	fin.open("File.txt");
	const int n = 256;
	char buffer[n] = {};
	if (fin.is_open())
	{
		while (!fin.eof()) fin.getline(buffer, n); cout << buffer << endl;
	}
	else cout << "Error: File not found" << endl;
	fin.close();
#endif // READ_FROM_FILE
	ofstream fout;
	ifstream fin;
	fout.open("Copy.txt");
	fin.open("File.txt");

	const int n = 256;
	char buffer[n] = {};

	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, n);
			fout << buffer << endl;
		}
	}
	else
	{
		cout << "Error: File not found" << endl;
	}
	fout.close();
	fin.close();
	system("notepad Copy.txt");
}

// Для работы с файлами в C++ существуют потоки.
// cout (ostream) / cin (istream) || fout (ofstream) - запись в файл / fin (ifstream) - чтение файла
// cout и cin существующие объекты, а fout и fin нужно создавать.