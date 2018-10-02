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
		assert(fileReader->Read() == "a bb s");

	}
	void ExecuteTestB()
	{

		Application *app = new Application('b', ' ', "ApplicationTest5ExecuteTest.txt");
		app->Execute();
		app->GetFile()->CloseOutFile();

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");
		//cout <<endl<< fileReader->Read();

		assert(fileReader->Read() == "bbsa");

	}
	void ExecuteTestC()
	{

		Application *app = new Application('c', 'b', "ApplicationTest5ExecuteTest.txt");
		app->Execute();
		app->GetFile()->CloseOutFile();

		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");

		assert(fileReader->Read() == "2");

	}

};
