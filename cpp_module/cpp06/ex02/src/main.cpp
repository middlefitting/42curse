#include "A.cpp"
#include "B.cpp"
#include "C.cpp"
#include "CoutUtil.hpp"
// #include <ctime>
// #include <cstdlib>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
  CoutUtil::infoCout("Identify real type");
  Base* base;

  std::srand(time(NULL));
  for (int i = 0; i < 15; i++) {
    base = generate();
    identify(base);
    identify(*base);
    delete base;
  }

  CoutUtil::infoCout("\nIdentify real type with only Base");
  Base onlyBase;
  identify(onlyBase);
  identify(&onlyBase);
  return 0;
}
