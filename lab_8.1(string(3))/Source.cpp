// ƒано л≥терний р€док, €кий м≥стить посл≥довн≥сть символ≥в s[0], ..., s[n], ...
// 1. ѕ≥драхувати к≥льк≥сть входжень кожного ≥з символ≥в У+Ф, У-Ф, У=Ф в посл≥довн≥сть
//s[1], Е, s[n].
// 2.  «ам≥нити кожну пару символ≥в У++Ф, У--Ф, У==Ф тр≥йкою з≥рочок У***Ф.

#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int count(string s) {
	int pos = 0;
	int k = 0;
	while (s.find_first_of("+-=", pos) != -1) {
		pos = s.find_first_of("+-=", pos) + 1;
		k++;
	}
	return k;
}


string change(string s) {
	while (s.find("++") != -1)
		s = s.replace(s.find("++"), 2, "***");
	while (s.find("==") != -1)
		s = s.replace(s.find("=="), 2, "***");
	while (s.find("--") != -1)
		s = s.replace(s.find("--"), 2, "***");
	return s;
}
int main()
{
	string str;
	cout << "Enter string:" << endl;
	getline(cin, str);
	cout << "String contained " << count(str) << " groups of '+ -'" << endl;
	string dest = change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}