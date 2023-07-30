#pragma once

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

namespace xl {
	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue {
	private:
		Container _con;

	public:
		priority_queue() {}

		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
		{
			while (first != last) {
				_con.push_back(*first);
				first++;
			}

			// 向下调整建堆
			// 需要从最后一个非叶子节点开始，而找父亲的方法是通过(孩子的下标 - 1) / 2 找到
			// 这里的第一个 -1 是找下标，第二个 -1 是找父亲的时候的 -1。
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--) {
				AdjustDown(i);
			}
		}

	public:
		void pop() {
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		void push(const T& x) {
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}

		const T& top() { return _con[0]; }

		bool empty() { return _con.empty(); }

		size_t size() { return _con.size(); }

	private:
		void AdjustDown(int parent) {
			Compare com;
			int child = parent * 2 + 1;
			while (child < _con.size()) {
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1])) child++;
				if (com(_con[parent], _con[child])) {
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else break;
			}
		}

		void AdjustUp(int child) {
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0) {
				if (com(_con[parent], _con[child])) {
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}
	};

	template<class T>
	class less {
	public:
		bool operator()(const T& x, const T& y) {
			return x < y;
		}
	};

	template<class T>
	class greater {
	public:
		bool operator()(const T& x, const T& y) {
			return x > y;
		}
	};
}