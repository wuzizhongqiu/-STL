#define _CRT_SECURE_NO_WARNINGS 1

#include "iterator.h"
#include "vector.h"
#include "list.h"

void test_list() {
	xl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);

	for (auto e : lt) cout << e << " ";
	cout << endl;

	xl::list<int>::reverse_iterator rit = lt.rbegin();
	while (rit != lt.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void test_vector() {
	xl::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	for (auto e : v) cout << e << " ";
	cout << endl;

	xl::vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

int main()
{
	//test_list();
	test_vector();

	return 0; 
}