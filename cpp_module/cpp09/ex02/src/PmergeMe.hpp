#include <sys/time.h>
#include "CoutUtil.hpp"
#include "parser/VectorParser.hpp"
#include "parser/DequeParser.hpp"

class PmergeMe
{
	private:
		IParser<std::vector<int> > *_vector_parser;
		IParser<std::deque<int> > *_deque_parser;

		std::time_t	getCurrentTime() const;

		void coutBeforeAndAfter(std::vector<int> vec) const;
		void coutVectorInfo(std::vector<int> vec) const;

		template <typename Container>
		void calcTime(Container &src, std::string type) const;

		template <typename Container>
		void mergeInsertSort(Container &src, int start, int end) const;

		template <typename Container>
		void mergeSort(Container &src, int start, int mid, int end) const;

		template <typename Container>
		void InsertSort(Container &src, int start, int end) const;


	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &pmerge_me);
		PmergeMe& operator=(PmergeMe const &pmerge_me);

		void mergeInsertionSort(int argc, char **argv) const;
};

#include "PmergeMe.tpp"
