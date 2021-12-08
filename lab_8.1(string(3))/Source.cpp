// ���� ������� �����, ���� ������ ����������� ������� s[0], ..., s[n], ...
// 1. ϳ��������� ������� �������� ������� �� ������� �+�, �-�, �=� � �����������
//s[1], �, s[n].
// 2.  ������� ����� ���� ������� �++�, �--�, �==� ������ ������ �***�.

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