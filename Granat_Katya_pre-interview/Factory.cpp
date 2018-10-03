
#include "stdafx.h"

IProcessor& Factory::SetGetIProcessors(char _processorType, char _processorArgumet) {

	if (_processorType == 'a') {  return *new ArgumentA; }
	else if (_processorType == 'b') {  return *new ArgumentB; }
	else if (_processorType == 'c') {  return *new ArgumentC; }
}
