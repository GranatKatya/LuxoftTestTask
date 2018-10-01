// Granat_Katya_pre-interview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int debug = 0;

class Application {

	FileReaderWritter * file  = new FileReaderWritter('f');
	IProcessor * iprocessor;
	//Factory factopy;
	char _processorType;
	char _processorArgument;
	Factory factory;// = Factory(_processorType, _processorArgument);
	

public:
	Application( char processorType, char processorArgument) {
		_processorType = processorType;
		_processorArgument = processorArgument;
	}
	Application() {}
	void Execute() {
//		file.Write();
		//file.Read();
		iprocessor = &factory.SetGetIProcessors(_processorType, _processorArgument);
		//file->OpenInFile();



		char buffer[10];
		/*FILE * ptrFile*/
		//vector <string*> v;5

		if (file->GetFile() == NULL) perror("Ошибка открытия файла");
		else 
		{


			//string str;
		
			while (!feof(file->GetFile())) {                              // пока не конец файла

				string str1 = file->Read();
				//if (file->Read().size() != 0) {      // считать символы из файла
				if (str1.size() != 0) {
					//if (fgets(buffer, 10, file->GetFile()) != NULL){

													//fputs(buffer, stdout);

													//string str(buffer);

						//ofstream fout("example_out.txt");
						//fout << "3455646";
														//fputs(iprocessor->Action(buffer).c_str() , file->GetFileToWrite());

						//fputs(iprocessor->Action(str1,"s").c_str(), file->GetFileToWrite());
					file->Write(iprocessor->Action(str1, _processorArgument));


					//file->GetFileToWrite() << 	
//fout<<iprocessor->Action(buffer)<<endl;
	//cout<<endl<<" 1 "<<iprocessor->Action(buffer)<<endl;

				}



				//string finalResult = to_string(iprocessor->GetFinalResult());
				//fputs(finalResult.c_str(), file->GetFileToWrite());



			/*v.push_back(&str);
			str.erase(1);*/

			}
				string finalResult = iprocessor->GetFinalResult();
				file->Write(finalResult);

		}


	
	}
};

void printHelp() {
	cout << "file_processor " << endl;
}


int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	
	char processorType;
	char processorArgument;
	


	for (int i = 2; i < argc; i++) {
		cout << argv[i] << endl;
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
		else if (string(argv[i]) == "-d" ) {
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
	
	
	Application a(processorType,processorArgument);
	
	a.Execute();

	return 0;
	
	
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
