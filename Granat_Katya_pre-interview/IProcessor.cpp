
#include "stdafx.h"

extern int debug;

void ArgumentA::addToContainer(string str) {


        if (debug == 1) {
		cout << "ArgumentA::addToContainer: Searching for position to insert" << endl;
	}
	vector<string>::iterator it = sortWords.begin();
	for (int i = 0; i < sortWords.size(); i++) {
		if (strcmp(str.c_str(), sortWords[i].c_str()) < 0) {
			
			sortWords.insert(it + i, str);
        		if (debug == 1) {
				cout << "ArgumentA::addToContainer: Inserted at position " << i << endl;
			}
			return;
		}
	}
	sortWords.push_back(str);
        if (debug == 1) {
		cout << "ArgumentA::addToContainer: Inserted at position " << sortWords.size() - 1 << endl;
	}
}
 string ArgumentA::Action(string str, char ch = ' ') {

	string word;
	string::iterator it;
	replace(str.begin(), str.end(), '\n', ' ');

	while (str.begin() != str.end()) {


		it = find(str.begin(), str.end(), ' ');
		if (it != str.end()) {
			word = leftover.append(str.substr(0, it - str.begin()));
			leftover = "";
			str = str.substr(it - str.begin() + 1, 10000);// cut 
			if (word != "") {
				if (IsUnique(word)) {
					addToContainer(word);
				}
			}
		}
		else {
			leftover = leftover.append(str);//add string if dont find space
			break;
		}
	}
	return "";
}

 string ArgumentA::GetFinalResult() {
	if (leftover != "") {
		if (IsUnique(leftover)) {
			addToContainer(leftover);
		}
	}

	string result = sortWords[0];

	for (int i = 1; i < sortWords.size(); i++) {
		result = result.append(" ").append(sortWords[i]);
	}
        if (debug == 1) {
		cout << "ArgumentA::GetFinalResult: Returned String: " << result << endl;
	}

	return result;
}





string ArgumentB::GetFinalResult() { return ""; }
string ArgumentB::Action(string str, char ch = ' ') {

	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	if (debug == 1) {
		cout << "ArgumentB::Action: Returned String: " << str << endl;
	}
	return str;
}


//

 string ArgumentC::GetFinalResult() {
	  return to_string(count);
	  //return finalResult;
}

string ArgumentC::Action(string str, char ch) {

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ch) {
			count++;
		}
	}
	if (debug == 1) {
		cout << "ArgumentC::Action: Count is: " << count << endl;
	}

	return "";
}
