#pragma once

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>() {}

		MutantStack(MutantStack const &src): std::stack<T>(src) {};

		virtual ~MutantStack() {}

		MutantStack &operator=(MutantStack const &src)
		{
			if (this == &src)
				return *this;
			~MutantStack();
			new (this) MutantStack(src);
			return *this;
		}

	//c는 stack 내부의 container를 의미한다.
	//여기서 typedef를 사용하여 container_type을 iterator로 정의하였다. 그 이유는 iterator를 사용하기 위해서이다. 안하면 에러남.
	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	iterator begin(void) {return this->c.begin();}
	iterator end(void) {return this->c.end();}


	// typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	// reverse_iterator rbegin(void) {return this->c.rbegin();}
	// reverse_iterator rend(void) {return this->c.rend();}

	// typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	// const_iterator cbegin(void) {return this->c.cbegin();}
	// const_iterator cend(void) {return this->c.cend();}

	// typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;
	// const_iterator crbegin(void) {return this->c.crbegin();}
	// const_iterator crend(void) {return this->c.crend();}
};
