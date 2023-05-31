#include "ClapTrap.hpp"

int main()
{
	std::cout << "\033[36m" << "/** Construct Tests **/" << "\33[0m" <<std::endl;
	ClapTrap a("JYP");
	a.info();

	ClapTrap b("HIVE");
	b.info();

	ClapTrap c("SM");
	c.info();
	c = b;
	c.info();

	ClapTrap d(c);
	d.info();

	std::cout << "\033[36m" << "/** Attact Tests **/" << "\33[0m" <<std::endl;
	for (int i = 0; i < 15; i ++)
		a.attack("b");
	a.info();

	std::cout << "\033[36m" << "/** Take Damage Tests **/" << "\33[0m" <<std::endl;
	for (int i = 0; i < 15; i ++)
		b.takeDamage(1);
	b.info();

	std::cout << "\033[36m" << "/** Repair Tests **/" << "\33[0m" <<std::endl;
	b.beRepaired(1);
	b.info();
	a.beRepaired(1);
	a.info();

	for (int i = 0; i < 15; i ++)
		c.beRepaired(-1);
	c.info();

	std::cout << "\033[36m" << "/** Destruct Tests **/" << "\33[0m" <<std::endl;

	return (0);
}
