#pragma once

#include "stdafx.h"

//interface
class IProcessor {
protected:
//	File * _file;
public:
	IProcessor() {}
	//IProcessor(File * file) {_file = file;}
	virtual string Action(string str) = 0;
};



//realization 
class ArgumentA : public IProcessor {
public:

	virtual string Action(string str) {
		
		return str;
	}

};

class ArgumentB : public IProcessor {
public:
	ArgumentB() {}
	/*ArgumentB(File  &file) {
		_file = &file; }*/
	virtual string Action(string str){


		//string str;
	//while ( !_file->IsEof()) {
		//while (){
			//str = _file->Read();
//			for ()
			//str.erase(str.find(' '));

		str.erase(remove(str.begin(), str.end(),' '), str.end());

		return str;
		//}

	}

	string GetStringWithoutSpaces(string str) {
		for (int i = 0; i < str.size();i++) {
		
		}
	}

};


class ArgumentC : public IProcessor {
public:
	ArgumentC() {}
	/*ArgumentC(File  &file) {
		_file = &file;
	}*/
	virtual string Action(string ch) {
		int count = 0;

	//	while (1) {
		string str;
		//str = _file->Read();


			if (str.find(ch)) {
				count++;

			}
	//	}

		//example_out.txt

		ofstream _fout2("example_out.txt");
		_fout2 << ch;
		_fout2.close();


		return str;

	}

};