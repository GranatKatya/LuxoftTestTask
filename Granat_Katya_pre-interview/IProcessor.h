#pragma once

#include "stdafx.h"

//interface
class IProcessor {
protected:
	string intermediateResult;
	//string finalResult;
	
//	FileReaderWritter * _file;
	string leftover;
	
public:

	IProcessor() {}
	virtual string GetFinalResult() = 0;
	
	//IProcessor(FileReaderWritter * file) {_file = file;}
	virtual string Action(string str, char ch = ' ') = 0;
};



//realization 
class ArgumentA : public IProcessor {
	vector<string> sortWords;// TO DO: replace with indexed tree
public:
	
	void addToContainer(string str) {
	
		//string s;
		vector<string>::iterator it = sortWords.begin();
		for (int i = 0; i < sortWords.size();i++) {
			if (strcmp(str.c_str() , sortWords[i].c_str()) < 0 ) {
				//s = sortWords[i];
				//sortWords[i].push_back(str);
				sortWords.insert( it+i , str);
				return;
			}
		}
		sortWords.push_back(str);
	}
	virtual string Action(string str, char ch = ' ') {

		string word;
		//int *p = std::find (myints, myints+4, 30);

		string::iterator it;
		replace(str.begin(), str.end(), '\n', ' ');

		while (str.begin() != str.end()) {


			it = find(str.begin(), str.end(), ' ' );
			if(it != str.end()) {
				word = leftover.append(str.substr(0 ,it-str.begin()));
				leftover = "";
				str = str.substr(it- str.begin()+1,10000);// cut 
				if (word != "") {
					addToContainer(word);
				}
			}
			else {
				leftover = leftover.append(str);//add string if dont find space
				break;
			}


		}



		/*if (1) {
			sortWords.push_back(str);
		}*/

		return "";
	}
	virtual string GetFinalResult() {
		if (leftover != "") {
			addToContainer(leftover);
		}

		string result = sortWords[0];

		for (int i = 1; i < sortWords.size();i++) {
			result = result.append(" ").append(sortWords[i]);
		}
		
		return result;
	}

};

class ArgumentB : public IProcessor {
public:
	ArgumentB() {}
	
	virtual string GetFinalResult() { return ""; }
	virtual string Action(string str, char ch = ' '){


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
	
	virtual string GetFinalResult() {
		return to_string(count);
		//return finalResult;
	}

	virtual string Action(string str, char ch ) {
		

	//	while (1) {
//		string str;
		//str = _file->Read();

		//str.erase(remove(srt.begin(),str.end(), ch.c_str()), str.end());
		//str.erase(remove(str.begin(), str.end(), 'a'), str.end());

		

		for (int i = 0; i < str.size();i++) {
			if (str[i] == ch) {
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