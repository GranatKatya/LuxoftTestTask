
#include "stdafx.h"


void ArgumentA::addToContainer(string str) {

	//string s;
	vector<string>::iterator it = sortWords.begin();
	for (int i = 0; i < sortWords.size(); i++) {
		if (strcmp(str.c_str(), sortWords[i].c_str()) < 0) {
			//s = sortWords[i];
			//sortWords[i].push_back(str);
			sortWords.insert(it + i, str);
			return;
		}
	}
	sortWords.push_back(str);
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
				addToContainer(word);
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
		addToContainer(leftover);
	}

	string result = sortWords[0];

	for (int i = 1; i < sortWords.size(); i++) {
		result = result.append(" ").append(sortWords[i]);
	}

	return result;
}





 //


  string ArgumentB::GetFinalResult() { return ""; }
  string ArgumentB::Action(string str, char ch = ' ') {

	  str.erase(remove(str.begin(), str.end(), ' '), str.end());
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

	  cout << count << endl;
	 
	  return "";
  }