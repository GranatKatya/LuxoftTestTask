#pragma once
#include "stdafx.h"
#include "assert.h"

class FactoryTeat {

public:
	void SetGetIProcessorsTest() {
		Factory * factory = new Factory;

		IProcessor &result = factory->SetGetIProcessors('a',' ');
		assert(typeid(result) == typeid (ArgumentA));

		IProcessor &result1 = factory->SetGetIProcessors('b', ' ');
		assert(typeid(result1) == typeid (ArgumentB));

		IProcessor &result2 = factory->SetGetIProcessors('c', 'a');
		assert(typeid(result2) == typeid (ArgumentC));

	}
};