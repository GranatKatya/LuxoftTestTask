#pragma once

#include "stdafx.h"

//interface
class IProcessor {
protected:
	std::string intermediateResult;
	std::string leftover;
	
public:

	IProcessor() {}
	virtual string GetFinalResult() = 0;
	
	//IProcessor(FileReaderWritter * file) {_file = file;}
	virtual string Action(string str, char ch = ' ') = 0;
};



//realization 
class ArgumentA : public IProcessor {
	vector<string> sortWords;// TO DO: replace with indexed tree
public:
	
	void addToContainer(string str);
	virtual string Action(string str, char ch );
	virtual string GetFinalResult();

	bool IsUnique(string str) {
		for (size_t i = 0; i < sortWords.size(); i++)
		{
			if (sortWords[i] == str) {
				return false;
			}
		}
		return true;
	}
};

class ArgumentB : public IProcessor {
public:
	ArgumentB() {}
	
	virtual string GetFinalResult();
	virtual string Action(string str, char ch );

};


class ArgumentC : public IProcessor {
	int count = 0;
	
public:
	ArgumentC() {}
	
	virtual string GetFinalResult();

	virtual string Action(string str, char ch);

};
