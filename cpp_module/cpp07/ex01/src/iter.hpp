#pragma once

// 배열 주소는 곧 시작주소라고 판단
template<typename T>
void iter(const T *array, int length, void (*fn)(T const &))
{
	for (int i = 0; i < length; i++)
		fn(array[i]);
}
