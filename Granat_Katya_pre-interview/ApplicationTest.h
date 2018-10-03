#pragma once
#include "stdafx.h"
#include "assert.h"

class ApplicationTest {

public:


	void ExecuteTestA()
	{
		Application *app = new Application('a', ' ', "ApplicationTest5ExecuteTest.txt");
		app->Execute();//C
		//delete app;
		app->GetFile()->CloseOutFile();

		//CloseInFile();
		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");
		string test = fileReader->Read();
		//cout << "ExecuteTestA: Comparing " << test  << endl;
		assert(test == "a aaaaaaa");
		//if (test == "a aaaaaaa") { cout << " strings is equal" << endl; }


	}
	void ExecuteTestB()
	{

		Application *app = new Application('b', ' ', "ApplicationTest5ExecuteTest.txt");
		app->Execute();
		app->GetFile()->CloseOutFile();

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");
		//cout <<endl<< fileReader->Read();

		assert(fileReader->Read() == "bbsaaaaaa");// б в вова г к кат€ старопортофранковска€улицаодессыдочтаточнобольша€");

	}
	void ExecuteTestC()
	{

		Application *app = new Application('c', 's', "ApplicationTest5ExecuteTest.txt");
		app->Execute();
		app->GetFile()->CloseOutFile();

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");
		//cout <<endl<< fileReader->Read();

		assert(fileReader->Read() == "1");// б в вова г к кат€ старопортофранковска€улицаодессыдочтаточнобольша€");

	}

};
