// Granat_Katya_pre-interview.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class Application {

	File * file  = new File('f');
	IProcessor * iprocessor;
	//Factory factopy;

public:
	Application() {}
	void Execute() {
//		file.Write();
		//file.Read();
		iprocessor = new ArgumentB();
		//file->OpenInFile();



		char buffer[10];
		/*FILE * ptrFile*/
		//vector <string*> v;

		if (file->GetFile() == NULL) perror("Ошибка открытия файла");
		else
		{


			//string str;
			while (!feof(file->GetFile()))                               // пока не конец файла
			{
				if (fgets(buffer, 10, file->GetFile()) != NULL) {      // считать символы из файла
				//if (fgets(buffer, 10 != NULL) {
					fputs(buffer, stdout);
					
					string str(buffer);

					//ofstream fout("example_out.txt");
					//fout << "3455646";
					fputs(iprocessor->Action(buffer).c_str() , file->GetFileToWrite());
					//file->GetFileToWrite() << 	
					//fout<<iprocessor->Action(buffer)<<endl;
						//cout<<endl<<" 1 "<<iprocessor->Action(buffer)<<endl;

				}

				/*v.push_back(&str);
				str.erase(1);*/

			}

		}


	
	}
};



int main() {
	setlocale(LC_ALL, "rus"); // корректное отображение Кириллицы
	Application a;
	a.Execute();



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
