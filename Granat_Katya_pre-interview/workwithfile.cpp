// Granat_Katya_pre-interview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int debug = 0;

void printHelp();
void Parse(int argc, char* argv[], char &processorType,char &processorArgument);
	
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus");
	
	char processorType;
	char processorArgument;
	
	Parse(argc, argv, processorType, processorArgument);

        if (debug == 1) {
		cout << "main: Arguments parsed" << endl;
	}
	Application a(processorType,processorArgument, argv[1]);
	
	a.Execute();

	return 0;	
}

void printHelp() {
	cout << "workwithfile - Process file content and put result to example_out.txt" << endl;
	cout << "Usage: workwithfile [<file>] {-a|-b|-c <character>|-h|--help} [-d|--debug]" << endl;
	cout << "	<file>			Input file to parse" << endl;
	cout << "	-a			Get all unique words in file (word separators are space and newline) sorted in alphabetic order" << endl;
	cout << "	-b			Remove all spaces from file" << endl;
	cout << "	-c <character>		Count occurances of <character> in file" << endl;
	cout << "	-d | --debug		Enable debug logging" << endl;
	cout << "	-h | --help		Print this help message and exit" << endl;
}
void Parse(int argc, char* argv[], char &processorType,
	char &processorArgument) {

	for (int i = 1; i < argc; i++) {
		if (string(argv[i]) == "-h" || string(argv[i]) == "--help") {
			printHelp();
			exit(0);
		}
	}
	for (int i = 2; i < argc; i++) {
		if (string(argv[i]) == "-a") {
			processorType = 'a';
			processorArgument = ' ';
		}
		else if (string(argv[i]) == "-b") {
			processorType = 'b';
			processorArgument = ' ';
		}
		else if (string(argv[i]) == "-c") {
			processorType = 'c';
			if (i + 1 < argc && strlen(argv[i + 1]) == 1) {
				processorArgument = *argv[i+1];
				i++;
			}
			else {
				cout << "error: key -c requires one character argument" << endl;
				printHelp();
				exit(1);
			}
		}
		else if (string(argv[i]) == "-d" || string(argv[i]) == "--debug") {
			debug = 1;
		}
		else {
			cout << "error: wrong argument passed" << argv[i] << endl;
			printHelp();
			exit(1);
		}
	}
}
