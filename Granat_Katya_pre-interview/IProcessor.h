#pragma once

#include "stdafx.h"

//interface
class IProcessor {
protected:
	string intermediateResult;
	//string finalResult;
	int count = 0;
//	FileReaderWritter * _file;
public:

	IProcessor() {}
	int GetCount() {
		return count;
	}
	//IProcessor(FileReaderWritter * file) {_file = file;}
	virtual string Action(string str, string ch ="0") = 0;
};



//realization 
class ArgumentA : public IProcessor {
public:

	virtual string Action(string str, string ch = "0") {
		
		return str;
	}

};

class ArgumentB : public IProcessor {
public:
	ArgumentB() {}
	
	virtual string Action(string str, string ch = "0"){


		//string str;
	//while ( !_file->IsEof()) {
		//while (){
			//str = _file->Read();
//			for ()
			//str.erase(str.find(' '));

		str.erase(remove(str.begin(), str.end(),' '), str.end());

		return str;
		//}

	}

};


class ArgumentC : public IProcessor {
public:
	ArgumentC() {}
	


	virtual string Action(string str, string ch ) {
		

	//	while (1) {
//		string str;
		//str = _file->Read();

		//str.erase(remove(srt.begin(),str.end(), ch.c_str()), str.end());
		//str.erase(remove(str.begin(), str.end(), 'a'), str.end());

		

		for (int i = 0; i < str.size();i++) {
			if (str[i] == ch[0]) {
				count++;
			}
		}

		cout << count << endl;
		/*while () {
			if (str.find(ch)) {
				count++;

			}
		}*/
	//	}

		//example_out.txt

		/*ofstream _fout2("example_out.txt");
		_fout2 << ch;
		_fout2.close();*/

		//finalResult = finalResult.(count);
		
		return "";

	}

};