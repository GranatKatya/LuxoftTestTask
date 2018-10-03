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
		a->Action("a test1 very",' ');
		a->Action("very", ' ');
		a->Action("long", ' ');
		a->Action("string test2 +_)", ' ');
		a->Action("(_+", ' ');
		assert(a->GetFinalResult() == "+_)(_+ a test1 test2 veryverylongstring");
		//cout << "good";
	}
	// 	
	void GetFinalResultTest() {
		ArgumentA *a = new ArgumentA;
		a->Action("a test1 very", ' ');
		a->Action("very", ' ');
		a->Action("long", ' ');
		a->Action("string test2 +_)", ' ');
		a->Action("(_+", ' ');

		string result = a->GetFinalResult();
		assert("+_)(_+ a test1 test2 veryverylongstring" == result);
	}

	void IsEqual() {
		ArgumentA *a = new ArgumentA;
		a->Action("a test1 very", ' ');
		a->Action("very", ' ');
		a->Action("long", ' ');
		a->Action("aaaa aaaa test", ' ');
		a->Action("very", ' ');
		a->Action("very", ' ');
		a->Action("long", ' ');

		assert(a->IsUnique("long"));
	}


};


class ArgumentBTest {
public:

	void actionTest() {
		ArgumentB *b = new ArgumentB;
		string result = b->Action("a test1 very", ' ');
		
		//cout << "00000000000" << endl;
		assert(result ==  "atest1very");
		//cout << "00000000000" << endl;
	}
	// 	
	void GetFinalResultTest() {
		ArgumentB *b = new ArgumentB;
		b->Action("a test1 very", ' ');
		b->Action("very", ' ');
		b->Action("long", ' ');
		b->Action("string test2 +_)", ' ');
		b->Action("(_+", ' ');

		string result = b->GetFinalResult();
		assert(result == "");
	}

};


class ArgumentCTest {
public:

	void actionTest() {
		ArgumentC *c = new ArgumentC;
		string result = c->Action("a test1 very", 'a');
		
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

		assert(c->GetFinalResult() == "1");
		//cout << "	WWW" << endl;
	}

};