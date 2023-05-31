#include "PmergeMe.hpp"
#include "string"

int main(int argc, char **argv)
{
    PmergeMe pmerge_me;
    try
    {
        pmerge_me.mergeInsertionSort(argc, argv);
    }
    catch(const std::exception& e)
    {
        CoutUtil::errorCout(e.what());
    }
    return 0;
}
