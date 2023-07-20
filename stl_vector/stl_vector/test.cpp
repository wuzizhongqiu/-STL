#define _CRT_SECURE_NO_WARNINGS 1

#include "vector.h"

void test() {
	xl::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (auto e : v) cout << e << " ";
	cout << endl;
}

void test1() {
	xl::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (int i = 0; i < 5; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

void Print(const xl::vector<int>& v) {
	for (auto e : v) cout << e << " ";
	cout << endl;
}

void test2() {
	xl::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);

	xl::vector<int>::iterator it = v.begin() + 2;
	v.insert(it, 3);
	*it += 10;

	for (auto e : v) cout << e << " ";
	cout << endl;

}

void test3() {
	xl::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	xl::vector<int>::iterator it = v.begin();
	v.pop_back();
	xl::vector<int> v2(v);

	for (auto e : v2) cout << e << " ";
	cout << endl;
}

void test4() {
	int i = 0;
	int j = 1;

	int a = int();
	int b = int(1);

	cout << i << " " << j << " " << a << " " << b << endl;
}

int main()
{
	//test();	
	//test1();
	//test2();
	test3();
	//test4();


	return 0;
}

