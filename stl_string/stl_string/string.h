#pragma once

#include <iostream>
#include <string>

#include <assert.h>
#include <string.h>

using namespace std;

namespace xl {
	class string {
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		const static size_t npos = -1; // 可以这样用，但不建议，违背了C++的语法准则（建议声明和定义分离）

	public:
		string(const char* str = "")
			: _size(strlen(str))
			, _capacity(_size)
		{
			_str = new char[_capacity + 1];
			memcpy(_str, str, _size + 1);
		}

		//// 传统写法
		//string(const string& s) {
		//	_str = new char[s._capacity + 1];
		//	memcpy(_str, s._str, s._size + 1);
		//	_size = s._size;
		//	_capacity = s._capacity; 
		//}

		// 现代写法
		string(const string& s) 
			: _str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			swap(tmp);
		}

		//// 传统写法
		//string& operator=(const string& s) {
		//	if (this != &s) {
		//		char* tmp = new char[s._capacity + 1];
		//		memcpy(tmp, s._str, s._size + 1);
		//		delete[] _str;
		//		_str = tmp;
		//	}
		//	return *this;
		//}

		void swap(string& tmp) {
			::swap(_str, tmp._str);
			::swap(_size, tmp._size);
			::swap(_capacity, tmp._capacity);
		}

		// 现代写法
		string& operator=(string tmp) {
			swap(tmp);
			return *this;
		}

		~string()
		{
			delete[] _str; 
			_str = nullptr;
			_size = _capacity = 0;
		}

	public:
		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin() {
			return _str;
		}

		iterator end() {
			return _str + _size;
		}

		const_iterator begin() const {
			return _str;
		}

		const_iterator end() const {
			return _str + _size;
		}

	public:
		void reserve(size_t n) {
			if (n > _capacity) {
				char* tmp = new char[n + 1];
				memcpy(tmp, _str, _size + 1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0') {
			if (n < _size) {
				_size = n;
				_str[_size] = '\0';
			}
			else {
				reserve(n);
				for (size_t i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch) {
			if (_size == _capacity) {
				// 2倍扩容
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		
		void append(const char* str) {
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				// 至少扩容到 _size + len
				reserve(_size + len);
			}
			memcpy(_str + _size, str, len + 1);
			_size += len; 
		}

		string& operator+=(char ch) {
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str) {
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t n, char ch) {
			assert(pos <= _size);
			if (_size + n > _capacity) {
				// 至少扩容到_size + n
				reserve(_size + n);
			}
			// 挪动数据
			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + n] = _str[end];
				end--; 
			}
			// 填值
			for (size_t i = 0; i < n; i++) _str[pos + i] = ch;

			_size += n;
		}

		void insert(size_t pos, const char* str) {
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity) {
				// 至少扩容到_size + len
				reserve(_size + len);
			}
			// 挪动数据
			size_t end = _size;
			while (end >= pos && end != npos) {
				_str[end + len] = _str[end];
				end--;
			}
			// 填值
			for (size_t i = 0; i < len; i++) _str[pos + i] = str[i];

			_size += len;
		}

		void erase(size_t pos, size_t len = npos) {
			assert(pos <= _size);
			if (len == npos || pos + len >= _size) {
				_size = pos;
				_str[pos] = '\0';
			}	
			else {
				size_t end = pos + len;
				while (end <= _size) {
					_str[pos++] = _str[end++];
				}
				_size -= len;
			}
		}

		size_t find(char ch, size_t pos = 0) {
			for (size_t i = pos; i < _size; i++) {
				if (_str[i] == ch) return i;
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0) {
			const char* ptr = strstr(_str + pos, str);
			if (ptr) return ptr - _str;
			else return npos;
		}

		string substr(size_t pos = 0, size_t len = npos) {
			assert(pos <= _size);
			size_t n = len + pos;
			if (len == npos || pos + len > _size) {
				n = _size;
			}
			string tmp;
			tmp.reserve(n);
			for (size_t i = pos; i < n; i++) {
				tmp += _str[i];
			}
			return tmp;
		}

	public:
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}

		char& operator[](size_t pos) const {
			assert(pos < _size);
			return _str[pos];
		}

		bool operator<(const string& s) {
			int ret = memcmp(_str, s._str, _size < s._size ? _size : s._size);
			return ret == 0 ? _size < s._size : ret < 0;
		}

		bool operator==(const string& s) {
			return _size == s._size && memcmp(_str, s._str, _size) == 0;
		}

		bool operator<=(const string& s) {
			return *this < s || *this == s;
		}

		bool operator>(const string& s) {
			return !(*this <= s);
		}

		bool operator>=(const string& s) {
			return !(*this < s);
		}

		bool operator!=(const string& s) {
			return !(*this == s);
		}

		const char* c_str() const {
			return _str;
		}

		size_t size() const {
			return _size;
		}

		void clear() {
			_str[0] = '\0';
			_size = 0;
		}
	};

	ostream& operator<<(ostream& out, const string& s) {
		for (auto e : s) cout << e;
		return out;
	}

	istream& operator>>(istream& in, string& s) {
		s.clear();
		char ch = in.get();
		while (ch != ' ' && ch != '\n') {
			s += ch;
			ch = in.get();
		}
		return in;
	}
}



