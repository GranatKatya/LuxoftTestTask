#pragma once
#include "stdafx.h"
#include "assert.h"

class ArgumentATest {

	
public:
	void addToContainerTest() {
		ArgumentA *a = new ArgumentA;
		a->addToContainer("test");
		assert(a->GetFinalResult() == "test");
		a->addToContainer("aaaa");
		assert(a->GetFinalResult() == "aaaa test");
		a->addToContainer("aaaa");
		assert(a->GetFinalResult() == "aaaa aaaa test");
		a->addToContainer("zzzz");
		assert(a->GetFinalResult() == "aaaa aaaa test zzzz");
		a->addToContainer("");
		assert(a->GetFinalResult() == " aaaa aaaa test zzzz");
	}
	void actionTest() {
		ArgumentA *a = new ArgumentA;
		a->Action("a test1 very");
		a->Action("very");
		a->Action("long");
		a->Action("string test2 +_)");
		a->Action("(_+");
		assert(a->GetFinalResult() == "+_)(_+ a test1 test2 veryverylongstring");

	}
};