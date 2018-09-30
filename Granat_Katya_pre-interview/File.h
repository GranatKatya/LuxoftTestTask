#pragma once
#include "stdafx.h"

class FileReaderWritter {
	string _name;
	//ofstream * _fout = nullptr ;
	FILE * _fout;
	//ifstream *_fin = nullptr;
	FILE *_fin;
public:

	FILE * GetFile() {
		return _fout;
	}
	FILE * GetFileToWrite() {
		return _fin;
	}

	FileReaderWritter(char f) {
	_name = f;
	OpenInFile();
	OpenOutFile();
	}

	string Read() {
		
		char buff[10]; // буфер промежуточного хранения считываемого из файла текста
		//ifstream fin(_name); // открыли файл для чтения

		//fin >> buff; // считали первое слово из файла
		//cout << buff << endl; // напечатали это слово

					//ifstream  *fin = nullptr;
					//fin->getline(buff, 10); // считали строку из файла
		fgets(buff ,10, _fout);

		//_fin.close(); // закрываем файл

		//delete
		cout << buff << endl; // напечатали эту строку
		string str(buff);
		return str;
	}

	/*ifstream& GetInputStream() {
		return *_fin;
	}*/

	/*bool IsEof() {
		
			return  _fin->eof();

	}*/



	void OpenInFile(string _name = "cppstudio.txt") {

		const char * a = _name.c_str();
		//ifstream fin(_name, ios_base::in);
		//_fin = move(&fin);
		_fout = fopen(a , "r");
	}

	 
	void OpenOutFile(string _name = "example_out.txt") {

		const char * a = _name.c_str();
		 // ofstream fout(_name,  ios_base::app | ios_base::trunc);
		 //_fout =  move(&fout);
		 _fin = fopen(a, "w");
		 
	}

	void Write(string str) {
	//	
	//	 // создаём объект класса ofstream и связываем его с файлом cppstudio.txt
	//	*_fout << str;   // запись строки в файл
	//	 // закрываем файл
		
		//fputs(iprocessor.Action(str, "s").c_str(), _fin);
		fputs(str.c_str(), _fin);
	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//FileReaderWritter(string name) { _name = name; }
	~FileReaderWritter() {
		fclose(_fout);
		fclose(_fin);
	}
	

	void SetName(string name) { _name = name; }
	string GetName() { return _name; }
};
