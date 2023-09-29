#include "ScalarConverter.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    CoutUtil::errorCout("error: bad arguments");
    return EXIT_FAILURE;
  }

  ScalarConverter::convert(av[1]);

  return EXIT_SUCCESS;
}
