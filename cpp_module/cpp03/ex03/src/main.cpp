/**
C++에서, 파생 클래스의 객체가 소멸될 때, 파생 클래스의 소멸자가 먼저 호출됩니다. 이는 파생 클래스의 객체가 기본 클래스와 파생 클래스의 멤버 변수를 모두 소멸시켜야 하기 때문입니다.

기본 클래스의 소멸자가 먼저 호출된다면, 파생 클래스의 멤버 변수는 이미 소멸되어있을 수 있습니다. 이는 파생 클래스의 소멸자에서 기본 클래스의 멤버 변수에 접근할 때 문제를 일으킬 수 있다.

따라서 C++에서는, 파생 클래스의 소멸자가 먼저 호출되어 파생 클래스의 멤버 변수를 소멸시킨 후, 기본 클래스의 소멸자가 호출되어 기본 클래스의 멤버 변수를 소멸시키는 것이 일반적입니다.
이렇게 하면 파생 클래스의 멤버 변수와 기본 클래스의 멤버 변수 모두 올바르게 소멸됩니다.
*/


#include "DiamondTrap.hpp"

int main() {
	std::cout << "\033[36m" << "/** Construct Tests **/" << "\33[0m" <<std::endl;
	DiamondTrap a("JYP");
	a.info();
	a.whoAmI();

	DiamondTrap b("HIVE");
	b.info();
	b.whoAmI();

	DiamondTrap c("SM");
	c.info();
	c.whoAmI();
	c = b;
	c.info();
	c.whoAmI();

	DiamondTrap d(c);
	d.info();
	d.whoAmI();

	std::cout << "\033[36m" << "/** Attact Tests **/" << "\33[0m" <<std::endl;
	for (int i = 0; i < 15; i ++)
		a.attack("b");
	a.info();

	std::cout << "\033[36m" << "/** Take Damage Tests **/" << "\33[0m" <<std::endl;
	for (int i = 0; i < 15; i ++)
		b.takeDamage(20);
	b.info();

	std::cout << "\033[36m" << "/** High five Tests **/" << "\33[0m" <<std::endl;
	b.highFivesGuys();
	a.highFivesGuys();

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
