#pragma once

namespace xl {
	template <class Iterator, class Ref, class Ptr>
	class reverse_iterator {
	private:
		Iterator _it;

	public:
		typedef reverse_iterator<Iterator, Ref, Ptr> self;

	public:
		reverse_iterator(Iterator it)
			: _it(it)
		{}

	public:
		Ref operator*() {
			Iterator tmp = _it;
			return *(--tmp);
		}

		Ptr operator->() {
			return &(operator*());
		}

		self& operator++() {
			--_it;
			return *this;
		}

		self operator++(int) {
			self tmp = *this;
			--_it;
			return tmp;
		}

		self& operator--() {
			++_it;
			return *this;
		}

		self operator--(int) {
			self tmp = *this;
			++_it;
			return tmp;
		}

		bool operator!=(const self& s) {
			return _it != s._it;
		}
	};
}




