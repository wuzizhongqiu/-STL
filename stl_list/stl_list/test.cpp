#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

void test1() {
	xl::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);

}

void test2() {
	xl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	xl::list<int>::iterator it = lt.begin();
	while (it != lt.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

struct A {
	A(int a1 = 0, int a2 = 0) 
		: _a1(a1)
		, _a2(a2)
	{}

	int _a1;
	int _a2;
};

void test3() {
	xl::list<A> lt;
	lt.push_back({ 1, 1 });
	lt.push_back({ 2, 2 });
	lt.push_back({ 3, 3 });
	lt.push_back({ 4, 4 });

	xl::list<A>::iterator it = lt.begin();
	while (it != lt.end()) {
		cout << it->_a1 << it->_a2 << endl;
		it++;
	}
}

void test4() {
	xl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	
	xl::list<int> lt3;
	xl::list<int> lt2(lt);
	lt3 = lt2;

	xl::list<int>::iterator it = lt3.begin();
	while (it != lt3.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}


