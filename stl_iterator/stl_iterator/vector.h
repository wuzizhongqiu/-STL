#pragma once

#include "iterator.h"

#include <iostream>
#include <vector>

#include <assert.h>

using namespace std;

namespace xl {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		typedef reverse_iterator<iterator, const T&, const T*> const_reverse_iterator;
		typedef reverse_iterator<iterator, T&, T*> reverse_iterator;

		iterator begin() { return _start; }
		iterator end() { return _finish; }
		const_iterator begin() const { return _start; }
		const_iterator end() const { return _finish; }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return reverse_iterator(begin()); }

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;

	public:
		vector() {}

		vector(size_t n, const T& val = T()) { resize(n, val); }

		vector(int n, const T& val = T()) { resize(n, val); }

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last) {
				push_back(*first);
				first++;
			}
		}

		// 传统写法	
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); i++) {
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
		}

		void swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}

		// 现代写法
		vector<T>& operator=(vector<T> v) {
			swap(v);
			return *this;
		}

		~vector()
		{
			if (_start) {
				delete[] _start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

	public:
		void reserve(size_t n) {
			if (n > capacity()) {
				size_t old_size = size();
				T* tmp = new T[n];
				if (_start) {
					for (size_t i = 0; i < size(); i++) {
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old_size;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T()) {
			if (n < size()) {
				_finish = _start + n;
			}
			else {
				reserve();
				while (_finish != _start + n) {
					*_finish = val;
					_finish++;
				}
			}
		}

		void push_back(const T& x) {
			//if (_finish == _end_of_storage) {
			//	size_t new_capacity = capacity() == 0 ? 4 : capacity() * 2;
			//	reserve(new_capacity);
			//}
			//*_finish = x;
			//_finish++;

			insert(end(), x);
		}

		void pop_back() {
			erase(end() - 1);
		}

		void insert(iterator pos, const T& x) {
			assert(pos >= _start && pos <= _finish);

			if (_finish == _end_of_storage) {
				size_t len = pos - _start; // 防止迭代器失效的问题（扩容之后pos仍指向旧空间）
				size_t new_capacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(new_capacity);
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *end;
				end--;
			}
			*pos = x;
			_finish++;
		}

		iterator erase(iterator pos) {
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it != _finish) {
				*(it - 1) = *it;
				it++;
			}
			_finish--;
			return pos;
		}

	public:
		T operator[](size_t pos) {
			assert(pos < size());
			return _start[pos];
		}

		const T operator[](size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}

		int size() const {
			return _finish - _start;
		}

		int capacity() const {
			return _end_of_storage - _start;
		}
	};
}


