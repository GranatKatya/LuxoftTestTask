#pragma once
#include "stdafx.h"
#include "assert.h"


class FileTest {
	//void OpenInFileTest() {
		// TODO: Test that nonexisting file returns valid error message
		//FileReaderWritter * fileReader = new FileReaderWritter;
		//fileReader->OpenInFile("nonexistingfile");



	//}
	void ReadTest() {
		FileReaderWritter * fileReader = new FileReaderWritter;
		fileReader->OpenInFile("FileTest.ReadTest");
		assert(fileReader->Read() == "test_string\ntest");
	}
	void WriteTest() {
		FileReaderWritter * fileWriter = new FileReaderWritter;
		fileWriter->OpenOutFile("FileTest.WriteTest");
		fileWriter->Write("FirstString");
		fileWriter->Write("SecondString");
		fileWriter->CloseOutFile();
		fileWriter->OpenInFile("FileTest.WriteTest");
		assert(fileWriter->Read() == "FirstStringSecondString");
	}

};