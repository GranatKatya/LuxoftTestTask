#pragma once
#include "stdafx.h"

class Application {

	FileReaderWritter * file = new FileReaderWritter;
	IProcessor * iprocessor;
	char _processorType;
	char _processorArgument;
	string _fileName;
	Factory factory;// = Factory(_processorType, _processorArgument);


public:
	Application(char processorType, char processorArgument, string _fileName);
	Application() {}
	void Execute();
};

