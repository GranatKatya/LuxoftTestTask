#pragma once
#include "stdafx.h"
#include "assert.h"

class ApplicationTest {

public:
	/*void ApplicationConstructorTest() {
		Application app =  Application('a','b');

		app.

	}*/

	void ExecuteTest() 
	{
		char ch = '-a';
		Application app = Application(ch, 'b');
		app.Execute();//C
		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("example_out.txt");

		if (ch == '-a') {
			
			assert(fileReader->Read() == "� ����� ��� � ���� � � ���� �������������������������������������������������");

		}
		else if (ch == '-b') {
			assert(fileReader->Read() == "����������������������������������������������������������������\\n\
�����");
		}
		else if (ch == '-c') {
			assert(fileReader->Read() == "23");
		}

	}
};