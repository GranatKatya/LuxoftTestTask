
#include "stdafx.h"

Application::Application(char processorType, char processorArgument) {
	_processorType = processorType;
	_processorArgument = processorArgument;
}


void Application:: Execute() {

	iprocessor = &factory.SetGetIProcessors(_processorType, _processorArgument);
	char buffer[10];

	if (file->GetFile() == NULL) perror("������ �������� �����");
	else
	{
		while (!feof(file->GetFile())) {                              // ���� �� ����� �����

			string str1 = file->Read();
			    
			if (str1.size() != 0) { // ������� ������� �� �����
				
				file->Write(iprocessor->Action(str1, _processorArgument));

			}
		}
		string finalResult = iprocessor->GetFinalResult();
		file->Write(finalResult);
	}
}