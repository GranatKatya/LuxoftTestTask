#pragma once
#include "stdafx.h"
#include "assert.h"

class FactoryTeat {

public:
	void SetGetIProcessorsTest() {
		Factory * factory = new Factory;

		IProcessor &result = factory->SetGetIProcessors('-a',' ');
		assert(typeid(result) == typeid (ArgumentA));

		result = factory->SetGetIProcessors('-b', ' ');
		assert(typeid(result) == typeid (ArgumentB));

		result = factory->SetGetIProcessors('-c', 'a');
		assert(typeid(result) == typeid (ArgumentC));

	}
};