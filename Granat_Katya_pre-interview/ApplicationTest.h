#pragma once
#include "stdafx.h"
#include "assert.h"

class ApplicationTest {

public:


	void ExecuteTestA()
	{
		cout << "[Test]: ApplicationTest::ExecuteTestA START" << endl;
		Application *app = new Application('a', ' ', "ApplicationTest5ExecuteTest.txt");
		app->Execute();
		app->GetFile()->CloseOutFile();

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");
		string test = fileReader->Read();
		assert(test == "a aaaaaaa");
		cout << "[Test]: ApplicationTest::ExecuteTestA FINISH" << endl;


	}
	void ExecuteTestB()
	{

		cout << "[Test]: ApplicationTest::ExecuteTestB START" << endl;
		Application *app = new Application('b', ' ', "ApplicationTest5ExecuteTest.txt");
		app->Execute();
		app->GetFile()->CloseOutFile();

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");

		assert(fileReader->Read() == "bbsaaaaaa");
		cout << "[Test]: ApplicationTest::ExecuteTestB FINISH" << endl;

	}
	void ExecuteTestC()
	{

		cout << "[Test]: ApplicationTest::ExecuteTestC START" << endl;
		Application *app = new Application('c', 's', "ApplicationTest5ExecuteTest.txt");
		app->Execute();
		app->GetFile()->CloseOutFile();

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");

		assert(fileReader->Read() == "1");
		cout << "[Test]: ApplicationTest::ExecuteTestC FINISH" << endl;

	}

};
