// Granat_Katya_pre-interview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void printHelp();
void Parse(int argc, char* argv[], char &processorType,char &processorArgument);
	
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	
	char processorType;
	char processorArgument;
	
	Parse(argc, argv, processorType, processorArgument);

	Application a(processorType,processorArgument, argv[1]);
	
	a.Execute();

	return 0;	
}










int debug = 0;
void printHelp() {
	cout << "file_processor " << endl;
}
void Parse(int argc, char* argv[], char &processorType,
	char &processorArgument) {

	for (int i = 2; i < argc; i++) {
		//cout << argv[i] << endl;
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
			if (strlen(argv[i + 1]) == 1) {
				processorArgument = *argv[i + 1];
				break;
				//string.pop(argv[i+1]);
			}
			else {
				cout << "error: key -c takes one character argument" << endl;
				printHelp();
				exit(1);
			}
		}
		else if (string(argv[i]) == "-d") {
			debug = 1;
		}
		else if (string(argv[i]) == "-h" || string(argv[i]) == "--help") {
			printHelp();
			exit(0);
		}
		else {
			cout << "error: wrong arguments passed" << endl;
			printHelp();
			exit(1);
		}
	}
}



























//
//#include <stdio.h>
//
//int main(int argc, char **argv) {
//	int i;
//
//	printf("%d\n", argc);
//
//	for (i = 0; i < argc; i++)
//		puts(argv[i]);
//}


#include <stdio.h>
#include <string.h>
//
//main(int argc, char **argv) {
//	int i, ch;
//	FILE *f[5];
//
//	if (argc < 3 || argc > 7) {
//		puts("Неверное количество параметров");
//		return 1;
//	}
//
//	if (strcmp(argv[1], "-w") != 0 && strcmp(argv[1], "-a") != 0) {
//		puts("Первый параметр может быть либо -w, либо -a");
//		return 2;
//	}
//
//	for (i = 0; i < argc - 2; i++) {
//		f[i] = fopen(argv[i + 2], argv[1] + 1);
//		if (f[i] == NULL) {
//			printf("Файл %s нельзя открыть\n", argv[i + 2]);
//			return 3;
//		}
//	}
//
//	while ((ch = getchar()) != EOF)
//		for (i = 0; i < argc - 2; i++)
//			putc(ch, f[i]);
//
//	for (i = 0; i < argc - 2; i++)
//		fclose(f[i]);
//
//	return 0;
//}
