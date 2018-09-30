#pragma once
#include "stdafx.h"

class Factory {
	/*char _processorType;
	char _processorArgument;*/
public:
	Factory() {}
	//Factory(char processorType,char processorArgumet) {
	//	_processorType = processorType;
	//	_processorArgument = processorArgumet;

	//}

	IProcessor& SetGetIProcessors(char _processorType, char _processorArgumet) {

		if (_processorType == 'a') { cout << "a"; return *new ArgumentA; }
		else if (_processorType == 'b') { cout << "b"; return *new ArgumentB; }
		else if (_processorType == 'c') { cout << "c"; return *new ArgumentC; }
	}

};
