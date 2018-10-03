#include "stdafx.h"

#include "ApplicationTest.h" 
#include "FactoryTest.h" 
#include "FileTest.h" 
#include "IProcessorsTests.h" 

int debug = 1;
int main(int argc, char* argv[]) {
	debug=1;

	setlocale(LC_ALL, "rus");
	
	ApplicationTest app = ApplicationTest();
	app.ExecuteTestA();
	app.ExecuteTestB();
	app.ExecuteTestC();


	FactoryTeat f = FactoryTeat();
	f.SetGetIProcessorsTest();

	FileTest ft = FileTest();
	ft.ReadTest();
	ft.WriteTest();

	ArgumentATest at = ArgumentATest();
	at.actionTest();
	at.addToContainerTest();
	at.GetFinalResultTest();

	ArgumentBTest bt = ArgumentBTest();
	bt.actionTest();
	bt.GetFinalResultTest();

	ArgumentCTest ct = ArgumentCTest();
	ct.actionTest();
	ct.GetFinalResultTest();


	return 0;
}
