#pragma once
#include "stdafx.h"
#include "assert.h"


class FileTest {
	
public:
	void ReadTest() {

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");
		assert(fileReader->Read() == "1");
	}
	void WriteTest() {
		FileReaderWritter * fileWriter = new FileReaderWritter;
		fileWriter->OpenOutFile("example_out.txt");
		fileWriter->Write("FirstString");
		fileWriter->Write("SecondString");
		fileWriter->CloseOutFile();
		fileWriter->OpenInFile("example_out.txt");
		assert(fileWriter->Read() == "FirstStri");
	//	cout << "	WWW" << endl;
	}

};