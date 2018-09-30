#pragma once

#include "stdafx.h"

//interface
class IProcessor {
protected:
	string intermediateResult;
	//string finalResult;
	
//	FileReaderWritter * _file;
	vector<string>sortWords;
public:

	IProcessor() {}
	virtual string GetCount() = 0;
	
	//IProcessor(FileReaderWritter * file) {_file = file;}
	virtual string Action(string str, string ch ="") = 0;
};



//realization 
class ArgumentA : public IProcessor {
public:
	virtual string GetCount() {}
	virtual string Action(string str, string ch = "") {
		
		if (1) {
			sortWords.push_back(str);
		}

		return str;
	}

};

class ArgumentB : public IProcessor {
public:
	ArgumentB() {}
	
	virtual string GetCount() { return ""; }
	virtual string Action(string str, string ch = ""){


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
	int count = 0;
public:
	ArgumentC() {}
	
	virtual string GetCount() {
		return to_string(count);
		//return finalResult;
	}

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