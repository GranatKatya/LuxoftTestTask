#pragma once
#include "stdafx.h"

class Factory {
	
public:
	Factory() {}
	IProcessor& SetGetIProcessors(char _processorType, char _processorArgumet);
};
