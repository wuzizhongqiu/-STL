#pragma once

#include "iterator.h"

#include <iostream>
#include <list>

#include <assert.h>

using namespace std;

namespace xl {
	template<class T>
	struct list_node {
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val = T())
			: _next(nullptr)
			, _prev(nullptr)
			, _val(val)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator {
		typedef __list_iterator<T, Ref, Ptr> self;

		typedef list_node<T> Node;

		Node* _node;

		__list_iterator(Node* node)
			: _node(node)
		{}

		Ref operator*() {
			return _node->_val;
		}

		Ptr operator->() {
			return &_node->_val;
		}

		self& operator++() {
			_node = _node->_next;
			return *this;
		}

		self operator++(int) {
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--() {
			_node = _node->_prev;
			return *this;
		}

		self operator--(int) {
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& it) {
			return _node != it._node;
		}

		bool operator==(const self& it) {
			return _node != it._node;
		}
	};

	template<class T>
	class list {
	public:
		typedef list_node<T> Node;

		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		typedef reverse_iterator<iterator, const T&, const T*> const_reverse_iterator;
		typedef reverse_iterator<iterator, T&, T*> reverse_iterator;

		iterator begin() { return _head->_next; }
		const_iterator begin() const { return _head->_next; }
		iterator end() { return _head; }
		const_iterator end() const { return _head; }

		reverse_iterator rbegin() { return reverse_iterator(end()); }
		const_reverse_iterator rbegin() const { return reverse_iterator(end()); }
		reverse_iterator rend() { return reverse_iterator(begin()); }
		const_reverse_iterator rend() const { return reverse_iterator(begin()); }

	private:
		Node* _head;

	public:
		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list<T>& lt)
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;

			for (auto& e : lt) {
				push_back(e);
			}
		}

		void swap(list<T>& lt) { ::swap(_head, lt._head); }

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

	public:
		void push_back(const T& x) {
			insert(end(), x);
		}

		void push_front(const T& x) {
			insert(begin(), x);
		}

		void pop_back() {
			erase(--end());
		}

		void pop_front() {
			erase(begin());
		}

		// pos 位置之前插入
		iterator insert(iterator pos, const T& x) {
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_next = cur;

			cur->_prev = newnode;
			newnode->_prev = prev;

			return newnode;
		}

		iterator erase(iterator pos) {
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			return next;
		}

	public:
		size_t size() {
			size_t sz = 0;
			iterator it = begin();
			while (it != end()) {
				sz++;
				it++;
			}
			return sz;
		}

		void clear() {
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
			}
		}

	};
}



