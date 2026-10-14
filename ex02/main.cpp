#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "--- Test: ScavTrap ---" << std::endl;
	ScavTrap s("Ludovico");
	ScavTrap sa("andrea");
	ScavTrap sb;
	s.attack("luigi");
	sa.takeDamage(30);
	sa.takeDamage(20);
	sb.guardGate();

	std::cout << "--- Test: FragTrap ---" << std::endl;
	FragTrap f("Marco");
	FragTrap fd;
	f.attack("target");
	f.highFivesGuys();
	fd.takeDamage(40);
	fd.beRepaired(10);

	std::cout << "--- Test: ClapTrap ---" << std::endl;
	ClapTrap c("Alice");
	c.attack("dummy");
	c.takeDamage(3);
	c.beRepaired(2);

	std::cout << "--- Test: copy and assignment ---" << std::endl;
	FragTrap fcopy(f);
	FragTrap fassign("tmp");
	fassign = fd;
	fcopy.highFivesGuys();
	fassign.attack("target2");

	std::cout << "--- Test: polymorphism ---" << std::endl;
	ClapTrap* p1 = new ScavTrap("poly_scav");
	ClapTrap* p2 = new FragTrap("poly_frag");
	p1->attack("enemy");
	p2->attack("enemy");
	delete p1;
	delete p2;

	return 0;
}