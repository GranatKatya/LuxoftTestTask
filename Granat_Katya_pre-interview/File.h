#pragma once
#include "stdafx.h"

class File {
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

	File(char f) {
	_name = f;
	OpenInFile();
	OpenOutFile();
	}

	string Read() {
		
		char buff[10]; // ����� �������������� �������� ������������ �� ����� ������
		//ifstream fin(_name); // ������� ���� ��� ������

		//fin >> buff; // ������� ������ ����� �� �����
		//cout << buff << endl; // ���������� ��� �����

		ifstream  *fin = nullptr;
		fin->getline(buff, 10); // ������� ������ �� �����
		//_fin.close(); // ��������� ����

		//delete
		cout << buff << endl; // ���������� ��� ������
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

	//void Write(string str) {
	//	
	//	 // ������ ������ ������ ofstream � ��������� ��� � ������ cppstudio.txt
	//	*_fout << str;   // ������ ������ � ����
	//	 // ��������� ����
	//}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//File(string name) { _name = name; }
	~File() {
		fclose(_fout);
		fclose(_fin);
	}
	

	void SetName(string name) { _name = name; }
	string GetName() { return _name; }
};
