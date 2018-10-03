#include "stdafx.h"

extern int debug;

Application::Application(char processorType, char processorArgument, string fileName) {
	_processorType = processorType;
	_processorArgument = processorArgument;
	_fileName = fileName;
}


void Application:: Execute() {
        if (debug == 1) {
		cout << "Applicaton::Execute: Running application with arguments:" << \
		" processorType='"<<  _processorType << "'," << \
		" processorArgument='"<<  _processorArgument << "'," << \
		" fileName='"<<  _fileName << "'" << \
		endl;
	}

	iprocessor = &factory.SetGetIProcessors(_processorType, _processorArgument);

	file->OpenInFile(_fileName);
        if (debug == 1) {
		cout << "Applicaton::Execute: Opened input file" << endl;
	}

	file->OpenOutFile();
        if (debug == 1) {
		cout << "Applicaton::Execute: Opened output file" << endl;
	}

	if (file->GetFile() == NULL) perror(string("Failed to open file ").append(_fileName).c_str());
	else
	{
		while (!feof(file->GetFile())) {

			string str1 = file->Read();
			    
        		if (debug == 1) {
				cout << "Applicaton::Execute: Got string from file:" << str1 << endl;
			}

			if (str1.size() != 0) {
				
				file->Write(iprocessor->Action(str1, _processorArgument));
        			if (debug == 1) {
					cout << "Applicaton::Execute: Written string to file" << endl;
				}

			}
		}
		string finalResult = iprocessor->GetFinalResult();
		file->Write(finalResult);
	}
}
