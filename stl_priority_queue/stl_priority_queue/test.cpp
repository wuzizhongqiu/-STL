#define _CRT_SECURE_NO_WARNINGS 1

#include "prioriy_queue.h"

int main()
{
	vector<int> v{ 2, 6, 7, 3, 4, 5, 0, 9, 8, 1 };
	xl::priority_queue<int> pq;
	pq.push(1);
	
	xl::priority_queue<int> pq1(v.begin(), v.end());
	while (!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;

	xl::priority_queue<int, vector<int>, xl::less<int>> pq2(v.begin(), v.end());
	while (!pq2.empty()) {
		cout << pq2.top() << " ";
		pq2.pop();
	}
	cout << endl;

	xl::priority_queue<int, vector<int>, xl::greater<int>> pq3(v.begin(), v.end());
	while (!pq3.empty()) {
		cout << pq3.top() << " ";
		pq3.pop();
	}
	cout << endl;

	return 0;
}