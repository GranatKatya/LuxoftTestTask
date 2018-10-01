
#include "stdafx.h"

FILE * FileReaderWritter::GetFile() {
	return _fin;
}
FILE * FileReaderWritter::GetFileToWrite() {
	return _fout;
}

FileReaderWritter::FileReaderWritter() {
	OpenInFile();
	OpenOutFile();
}

string FileReaderWritter::Read() {

	char buff[10]; // буфер промежуточного хранения считываемого из файла текста
	fgets(buff, 10, _fin);

	cout << buff << endl; // напечатали эту строку
	string str(buff);
	return str;
}


void FileReaderWritter::Write(string str) {
	fputs(str.c_str(), _fout);
}
void FileReaderWritter::CloseInFile() {
	fclose(_fin);
}
void FileReaderWritter::CloseOutFile() {
	fclose(_fout);
}

FileReaderWritter:: ~FileReaderWritter() {
	fclose(_fout);
	fclose(_fin);

}