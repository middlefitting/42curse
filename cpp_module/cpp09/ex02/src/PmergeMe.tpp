#pragma once

template <typename Container>
void PmergeMe::calcTime(Container &src, std::string type) const
{
	double total = 0.0;
	for (int i = 0; i < 42; i++)
	{
		Container tmp(src);
		std::time_t start = getCurrentTime();
		mergeInsertSort(tmp, 0, src.size() - 1);
		std::time_t finish = getCurrentTime();
		total += static_cast<double>(finish - start);
	}
	total /= 42;
	CoutUtil::infoCoutNoEndl("Time to process a range of ");
	CoutUtil::infoCoutNoEndl(src.size());
	CoutUtil::infoCoutNoEndl(" elements with std::" + type + " : ");
	CoutUtil::infoCoutNoEndl(total);
	CoutUtil::infoCout(" us");
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container &src, int start, int end) const
{
	if (start < end)
	{
		if (end - start < 70)
			InsertSort(src, start, end);
		else
		{
			int mid = (start + end) / 2;
			mergeInsertSort(src, start, mid);
			mergeInsertSort(src, mid + 1, end);
			mergeSort(src, start, mid, end);
		}
	}
}

template <typename Container>
void PmergeMe::mergeSort(Container &src, int start, int mid, int end) const
{
	int i = start;
	int j = mid + 1;
	int k = 0;
	std::vector<int> tmp(end - start + 1);

	while (i <= mid && j <= end)
	{
		if (src[i] < src[j])
			tmp[k++] = src[i++];
		else
			tmp[k++] = src[j++];
	}
	while (i <= mid)
		tmp[k++] = src[i++];
	while (j <= end)
		tmp[k++] = src[j++];
	for (int i = start; i <= end; i++)
		src[i] = tmp[i - start];
}

template <typename Container>
void PmergeMe::InsertSort(Container &src, int start, int end) const
{
	for (int i = start + 1; i <= end; i++)
	{
		int tmp = src[i];
		int j = i - 1;
		while (j >= start && src[j] > tmp)
		{
			src[j + 1] = src[j];
			j--;
		}
		src[j + 1] = tmp;
	}
}
