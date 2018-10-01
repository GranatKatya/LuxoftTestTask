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
	// 	
	void GetFinalResultTest() {
		ArgumentA *a = new ArgumentA;
		a->Action("a test1 very");
		a->Action("very");
		a->Action("long");
		a->Action("string test2 +_)");
		a->Action("(_+");

		string result = a->GetFinalResult();
		//assert(c->GetFinalResult()  == result);
		assert("+_)(_+ a test1 test2 veryverylongstring" == result);
	}


};


class ArgumentBTest {
public:

	void actionTest() {
		ArgumentB *b = new ArgumentB;
		string result = b->Action("a test1 very");
		/*c->Action("very");
		c->Action("long");
		c->Action("string test2 ");
		c->Action("(_+");*/
		//assert(c->GetFinalResult() == "atest1veryverylongstring test2(_+");
		assert(result ==  "atest1very");
	}
	// 	
	void GetFinalResultTest() {
		ArgumentB *b = new ArgumentB;
		b->Action("a test1 very");
		b->Action("very");
		b->Action("long");
		b->Action("string test2 +_)");
		b->Action("(_+");

		string result = b->GetFinalResult();
		assert(result == "");
	}

};


class ArgumentCTest {
public:

	void actionTest() {
		ArgumentC *c = new ArgumentC;
		string result = c->Action("a test1 very", 'a');
		/*c->Action("very", 'a');
		c->Action("long", 'a');
		c->Action("string test2 ", 'a');
		c->Action("(_+", 'a');*/
		assert(result == "");

	}
	// 	
	void GetFinalResultTest() {
		ArgumentC *c = new ArgumentC;
		c->Action("a test1 very",'a');
		c->Action("very", 'a');
		c->Action("long", 'a');
		c->Action("string test2 +_)", 'a');
		c->Action("(_+", 'a');

		//string result = c->GetFinalResult();
		assert(c->GetFinalResult() == "1");
	}

};