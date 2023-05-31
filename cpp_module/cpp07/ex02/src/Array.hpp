#pragma once

#include "CoutUtil.hpp"

template<typename T>
class Array
{
	public:
		Array()
		: _size(0)
		{
			_arr = new T[0];
		}

		Array(unsigned int n)
		: _size(n)
		{
			_arr = new T[n];
		}

		Array(const Array& src)
		: _size(src._size)
		{
			CoutUtil::regularCout("Array copy constructor called");
			_arr = new T[src._size];
			for (unsigned int i = 0; i < src._size; i++)
				_arr[i] = src._arr[i];
		}

		// 이거 활용해서 cpp05? 하기
		Array&	operator=(const Array& src)
		{
			CoutUtil::regularCout("Array operator= called");
			if (this == &src)
				return *this;
			this->~Array();
			new (this) Array(src);
			return *this;
		}

		~Array()
		{
			CoutUtil::regularCout("Array destructor called");
			if (_arr)
				delete [] _arr;
		}

		T& operator[](const unsigned int idx) const
		{
			if (idx >= _size)
				throw ArrayOutOfBoundsException();
			return _arr[idx];
		}

		// 첫 번째 const: 함수가 반환하는 값의 타입인 unsigned int& 앞에 있는 const는 반환 값의 상수성을 나타냅니다. 즉, 반환된 레퍼런스를 통해 값을 수정할 수 없음을 의미합니다.
		// 두 번째 const: 함수의 매개변수 int a 앞에 있는 const는 매개변수 a의 상수성을 나타냅니다. 이 매개변수는 값이 읽기 전용이며, 함수 내에서 수정할 수 없습니다.
		// 세 번째 const: 함수의 멤버 함수 선언의 끝에 있는 const는 멤버 함수 자체의 상수성을 나타냅니다. 이는 멤버 함수가 객체의 상태를 변경하지 않음을 의미합니다. 즉, 이 멤버 함수 내에서는 객체의 멤버 변수를 수정할 수 없습니다.
		const unsigned int& size(void) const
		{
			return _size;
		}

	private:
		const unsigned int _size;
		T* _arr;
		class ArrayOutOfBoundsException : public std::exception
		{
			const char* what(void) const throw()
			{
				return "Access of invalid index!";
			}
		};
};
