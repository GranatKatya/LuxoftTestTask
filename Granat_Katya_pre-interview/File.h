#pragma once
#include "stdafx.h"

class FileReaderWritter {
	FILE * _fout;
	FILE *_fin;
public:

	FILE * GetFile();
	FILE * GetFileToWrite();

	FileReaderWritter();

	string Read();


	void OpenInFile(string name = "example.txt") {

		const char * a = name.c_str();
		_fin = fopen(a, "r");
	}


	void OpenOutFile(string name = "example_out.txt") {
		const char * a = name.c_str();
		_fout = fopen(a, "w");

	}

	void Write(string str);
	void CloseInFile();
	void CloseOutFile();

	~FileReaderWritter();
	
};
