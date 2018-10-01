
#include "stdafx.h"

IProcessor& Factory::SetGetIProcessors(char _processorType, char _processorArgumet) {

	if (_processorType == 'a') { cout << "a"; return *new ArgumentA; }
	else if (_processorType == 'b') { cout << "b"; return *new ArgumentB; }
	else if (_processorType == 'c') { cout << "c"; return *new ArgumentC; }
}
