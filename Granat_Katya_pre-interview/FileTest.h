#pragma once
#include "stdafx.h"
#include "assert.h"


class FileTest {
	
public:
	void ReadTest() {
		cout << "[Test]: FileTest::ReadTest START" << endl;

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");
		assert(fileReader->Read() == "1");
		cout << "[Test]: FileTest::ReadTest FINISH" << endl;
	}
	void WriteTest() {
		cout << "[Test]: FileTest::WriteTest START" << endl;
		FileReaderWritter * fileWriter = new FileReaderWritter;
		fileWriter->OpenOutFile("example_out.txt");
		fileWriter->Write("FirstString");
		fileWriter->Write("SecondString");
		fileWriter->CloseOutFile();
		fileWriter->OpenInFile("example_out.txt");
		assert(fileWriter->Read() == "FirstStri");
		cout << "[Test]: FileTest::WriteTest FINISH" << endl;
	}

};
