#pragma once

#include <iostream>
#include <deque>

using namespace std;

namespace xl {
	template<class T, class Container = deque<T>>
	class stack {
	private:
		Container _con;

	public:
		void push(const T& x) { _con.push_back(x); }

		void pop() { _con.pop_back(); }

		T& top() { return _con.back(); }

		size_t size() { return _con.size(); }

		bool empty() { return _con.empty(); }
	};
}



