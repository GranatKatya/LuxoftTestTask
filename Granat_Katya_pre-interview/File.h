#pragma once
#include "stdafx.h"

class FileReaderWritter {
	//string _fileName;
	FILE * _fout;
	FILE *_fin;
public:

	FILE * GetFile() {
		return _fin;
	}
	FILE * GetFileToWrite() {
		return _fout;
	}

	FileReaderWritter() {
	//_fileName = fileName;
	OpenInFile();
	OpenOutFile();
	}

	string Read() {
		
		char buff[10]; // буфер промежуточного хранения считываемого из файла текста
		fgets(buff ,10, _fin);

		cout << buff << endl; // напечатали эту строку
		string str(buff);
		return str;
	}

	void OpenInFile(string name = "example.txt") {

		const char * a = name.c_str();
		_fin = fopen(a , "r");
	}

	 
	void OpenOutFile(string name = "example_out.txt") {
		const char * a = name.c_str();
		 _fout = fopen(a, "w");
		 
	}

	void Write(string str) {
		fputs(str.c_str(), _fout);
	}
	void CloseInFile() {
		fclose(_fin);
	}
	void CloseOutFile() {
		fclose(_fout);
	}

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//FileReaderWritter(string name) { _name = name; }
	~FileReaderWritter() {
		fclose(_fout);
		fclose(_fin);
	}
	

	/*void SetName(string name) { _name = name; }
	string GetName() { return _name; }*/
};
