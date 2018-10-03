
#include "stdafx.h"

Application::Application(char processorType, char processorArgument, string fileName) {
	_processorType = processorType;
	_processorArgument = processorArgument;
	_fileName = fileName;
}


void Application:: Execute() {

	iprocessor = &factory.SetGetIProcessors(_processorType, _processorArgument);
	//char buffer[100];

	file->OpenInFile(_fileName);
	file->OpenOutFile();
	if (file->GetFile() == NULL) perror("Ошибка открытия файла");
	else
	{
		while (!feof(file->GetFile())) {                              // пока не конец файла

			string str1 = file->Read();
			    
			if (str1.size() != 0) { // считать символы из файла
				
				file->Write(iprocessor->Action(str1, _processorArgument));

			}
		}
		string finalResult = iprocessor->GetFinalResult();
		file->Write(finalResult);
	}
}