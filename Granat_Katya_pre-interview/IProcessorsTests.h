#pragma once
#include "stdafx.h"
#include "assert.h"

class ArgumentATest {

	
public:
	void addToContainerTest() {
		cout << "[Test]: ArgumentATest::addToContainerTest START" << endl;
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
		cout << "[Test]: ArgumentATest::addToContainerTest FINISH" << endl;
	}
	void actionTest() {
		cout << "[Test]: ArgumentATest::actionTest START" << endl;
		ArgumentA *a = new ArgumentA;
		a->Action("a test1 very",' ');
		a->Action("very", ' ');
		a->Action("long", ' ');
		a->Action("string test2 +_)", ' ');
		a->Action("(_+", ' ');
		assert(a->GetFinalResult() == "+_)(_+ a test1 test2 veryverylongstring");
		cout << "[Test]: ArgumentATest::actionTest FINISH" << endl;
	}
	// 	
	void GetFinalResultTest() {
		cout << "[Test]: ArgumentATest::GetFinalResultTest START" << endl;
		ArgumentA *a = new ArgumentA;
		a->Action("a test1 very", ' ');
		a->Action("very", ' ');
		a->Action("long", ' ');
		a->Action("string test2 +_)", ' ');
		a->Action("(_+", ' ');

		string result = a->GetFinalResult();
		assert("+_)(_+ a test1 test2 veryverylongstring" == result);
		cout << "[Test]: ArgumentATest::GetFinalResultTest FINISH" << endl;
	}


};


class ArgumentBTest {
public:

	void actionTest() {
		cout << "[Test]: ArgumentBTest::actionTest START" << endl;
		ArgumentB *b = new ArgumentB;
		string result = b->Action("a test1 very", ' ');
		
		assert(result ==  "atest1very");
		cout << "[Test]: ArgumentBTest::actionTest FINISH" << endl;
	}
	// 	
	void GetFinalResultTest() {
		cout << "[Test]: ArgumentBTest::GetFinalResultTest START" << endl;
		ArgumentB *b = new ArgumentB;
		b->Action("a test1 very", ' ');
		b->Action("very", ' ');
		b->Action("long", ' ');
		b->Action("string test2 +_)", ' ');
		b->Action("(_+", ' ');

		string result = b->GetFinalResult();
		assert(result == "");
		cout << "[Test]: ArgumentBTest::GetFinalResultTest FINISH" << endl;
	}

};


class ArgumentCTest {
public:

	void actionTest() {
		cout << "[Test]: ArgumentCTest::actionTest START" << endl;
		ArgumentC *c = new ArgumentC;
		string result = c->Action("a test1 very", 'a');
		
		assert(result == "");
		cout << "[Test]: ArgumentCTest::actionTest FINISH" << endl;

	}
	// 	
	void GetFinalResultTest() {
		cout << "[Test]: ArgumentCTest::GetFinalResultTest START" << endl;
		ArgumentC *c = new ArgumentC;
		c->Action("a test1 very",'a');
		c->Action("very", 'a');
		c->Action("long", 'a');
		c->Action("string test2 +_)", 'a');
		c->Action("(_+", 'a');

		assert(c->GetFinalResult() == "1");
		cout << "[Test]: ArgumentCTest::GetFinalResultTest FINISH" << endl;
	}

};
