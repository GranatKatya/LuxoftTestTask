#pragma once
#include "stdafx.h"

class Application {

	FileReaderWritter * file = new FileReaderWritter;
	IProcessor * iprocessor;
	//Factory factopy;
	char _processorType;
	char _processorArgument;
	Factory factory;// = Factory(_processorType, _processorArgument);


public:
	Application(char processorType, char processorArgument) {
		_processorType = processorType;
		_processorArgument = processorArgument;
	}
	Application() {}
	void Execute() {

		//IProcessor &result = factory.SetGetIProcessors('-c', 'a');
		//if (typeid(result) == typeid (ArgumentC)) { cout << "KKKKKKKKKKKKKKKKKKKKKK"; }

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

