#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	_vector_parser = new VectorParser();
	_deque_parser = new DequeParser();
};

PmergeMe::~PmergeMe()
{
	delete _vector_parser;
	delete _deque_parser;
};

PmergeMe::PmergeMe(PmergeMe const &pmerge_me) {
	(void) pmerge_me;
	_vector_parser = new VectorParser();
	_deque_parser = new DequeParser();
}

PmergeMe& PmergeMe::operator=(PmergeMe const &pmerge_me) {
	if (this == &pmerge_me)
		return *this;
	delete this;
	new (this) PmergeMe(pmerge_me);
	return *this;
}

void PmergeMe::mergeInsertionSort(int argc, char **argv) const
{
	std::vector<int> vec = _vector_parser->parse(argc, argv);
	std::deque<int> deq = _deque_parser->parse(argc, argv);
	if (vec.size() >= 1)
	{
		coutBeforeAndAfter(vec);

		calcTime(vec, "vector");
		calcTime(deq, "deque");
	}
}

std::time_t	PmergeMe::getCurrentTime() const
{
	struct timeval	currentTime;

	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * 1000000UL + currentTime.tv_usec;
}

void PmergeMe::coutBeforeAndAfter(std::vector<int> vec) const
{
	CoutUtil::infoCoutNoEndl("Before: ");
	coutVectorInfo(vec);
	// std::sort(vec.begin(), vec.end());
	mergeInsertSort(vec, 0, vec.size() - 1);
	CoutUtil::infoCoutNoEndl("After: ");
	coutVectorInfo(vec);
}

void PmergeMe::coutVectorInfo(std::vector<int> vec) const
{
	std::vector<int>::iterator vec_it = vec.begin();
	std::vector<int>::iterator vec_end = vec.end();
	while (vec_it != vec_end)
	{
		CoutUtil::infoCoutNoEndl(*vec_it);
		CoutUtil::infoCoutNoEndl(" ");
		vec_it++;
	}
	CoutUtil::infoCout("");
}









// void PmergeMe::mergeInsertSort(std::vector<int> &vec, int start, int end) const
// {
// 	if (start < end)
// 	{
// 		if (end - start < 70)
// 			InsertSort(vec, start, end);
// 		else
// 		{
// 			int mid = (start + end) / 2;
// 			mergeInsertSort(vec, start, mid);
// 			mergeInsertSort(vec, mid + 1, end);
// 			mergeSort(vec, start, mid, end);
// 		}
// 	}
// }

// void PmergeMe::mergeSort(std::vector<int> &vec, int start, int mid, int end) const
// {
// 	int i = start;
// 	int j = mid + 1;
// 	int k = 0;
// 	std::vector<int> tmp(end - start + 1);

// 	while (i <= mid && j <= end)
// 	{
// 		if (vec[i] > vec[j])
// 			tmp[k++] = vec[i++];
// 		else
// 			tmp[k++] = vec[j++];
// 	}
// 	while (i <= mid)
// 		tmp[k++] = vec[i++];
// 	while (j <= end)
// 		tmp[k++] = vec[j++];
// 	for (int i = start; i <= end; i++)
// 		vec[i] = tmp[i - start];
// }

// void PmergeMe::InsertSort(std::vector<int> &vec, int start, int end) const
// {
// 	for (int i = start + 1; i <= end; i++)
// 	{
// 		int tmp = vec[i];
// 		int j = i - 1;
// 		while (j >= start && vec[j] < tmp)
// 		{
// 			vec[j + 1] = vec[j];
// 			j--;
// 		}
// 		vec[j + 1] = tmp;
// 	}
// }


// void PmergeMe::mergeInsertSort(std::deque<int> &vec, int start, int end) const
// {
// 	if (start < end)
// 	{
// 		if (end - start < 70)
// 			InsertSort(vec, start, end);
// 		else
// 		{
// 			int mid = (start + end) / 2;
// 			mergeInsertSort(vec, start, mid);
// 			mergeInsertSort(vec, mid + 1, end);
// 			mergeSort(vec, start, mid, end);
// 		}
// 	}
// }

// void PmergeMe::mergeSort(std::deque<int> &vec, int start, int mid, int end) const
// {
// 	int i = start;
// 	int j = mid + 1;
// 	int k = 0;
// 	std::deque<int> tmp(end - start + 1);

// 	while (i <= mid && j <= end)
// 	{
// 		if (vec[i] > vec[j])
// 			tmp[k++] = vec[i++];
// 		else
// 			tmp[k++] = vec[j++];
// 	}
// 	while (i <= mid)
// 		tmp[k++] = vec[i++];
// 	while (j <= end)
// 		tmp[k++] = vec[j++];
// 	for (int i = start; i <= end; i++)
// 		vec[i] = tmp[i - start];
// }

// void PmergeMe::InsertSort(std::deque<int> &vec, int start, int end) const
// {
// 	for (int i = start + 1; i <= end; i++)
// 	{
// 		int tmp = vec[i];
// 		int j = i - 1;
// 		while (j >= start && vec[j] < tmp)
// 		{
// 			vec[j + 1] = vec[j];
// 			j--;
// 		}
// 		vec[j + 1] = tmp;
// 	}
// }
