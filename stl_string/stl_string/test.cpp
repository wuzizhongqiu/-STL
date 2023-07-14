#define _CRT_SECURE_NO_WARNINGS 1

#include "string.h"

void test1() {
	xl::string s1("hello");
	cout << s1.c_str() << endl;

	for (int i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";
	}
	cout << endl;

	xl::string::iterator it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test2() {
	xl::string s1("hello");

	xl::string::const_iterator cit = s1.begin();
	while (cit != s1.end()) {
		//*cit += 1;
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	xl::string::iterator it = s1.begin();
	while (it != s1.end()) {
		*it += 1;
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

void test3() {
	xl::string s1("hello");
	cout << s1.c_str() << endl;

	s1.push_back(' ');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back('a');
	s1.push_back(' ');
	s1.append("string");
	cout << s1.c_str() << endl;
}

void test4() {
	xl::string s1("hello");
	cout << s1.c_str() << endl;

	s1 += " ";
	s1 += "a";
	s1 += "a";
	s1 += "a";
	s1 += "a";
	s1 += "a";
	s1 += "a";
	s1 += " ";
	s1 += "string";
	cout << s1.c_str() << endl;
}

void test5() {
	xl::string s1("hello");
	cout << s1.c_str() << endl;

	s1.insert(5, 3, 'x');
	s1.insert(0, "string ");
	cout << s1.c_str() << endl;

	s1.erase(10, 3);
	cout << s1.c_str() << endl;

	s1.erase(2, 100);
	cout << s1.c_str() << endl; 
}

void test6() {
	string s1;
	cin >> s1;
	cout << s1 << endl;
	
	size_t pos = s1.find('s');
	cout << s1.substr(pos, 3) << endl;

	pos = s1.find('s');
	cout << s1.substr(pos, 100) << endl;
}

void test7() {
	string s1("hello");
	string s2("helloxx");
	string s3("hello");

	cout << (s1 == s3) << endl;
	cout << true << endl;

}

int main()
{ 
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	test7();

	return 0;
}





