#pragma once
#include "stdafx.h"

class Application {

	FileReaderWritter * file = new FileReaderWritter;
	IProcessor * iprocessor;
	//Factory factopy;
	char _processorType;
	char _processorArgument;
	Factory factory;// = Factory(_processorType, _processorArgument);


public:
	Application(char processorType, char processorArgument);
	Application() {}
	void Execute();
};

