#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main(){
    ClapTrap a("Alice");
    ClapTrap b("Bob");
    ClapTrap c;

    a.attack("peppe");
    b.takeDamage(3);
    b.beRepaired(2);

    std::cout << "--- Test: energy exhausted ---" << std::endl;
    ClapTrap x("Charlie");
    for (int i = 0; i < 10; i++)
        x.attack("Bob");
    x.attack("Bob");
    x.beRepaired(5);
    std::cout << "--- Test: hit points depleted ---" << std::endl;
    ClapTrap d("giovanni");
    d.takeDamage(15);
    d.takeDamage(1);
    d.beRepaired(1);
    d.attack("target");
    std::cout << "--- Test: copy and assignment ---" << std::endl;
       ClapTrap y("caio");
    y.takeDamage(4);
    y.attack("target");

    ClapTrap f(y);
    f.takeDamage(0);
    f.takeDamage(3);
    y.takeDamage(1);

    ClapTrap g;
    g = y;
    g.takeDamage(0);

    ClapTrap &alias = y;
    y = alias;
    y.takeDamage(0);
    std::cout << "--- Test: limit values ---" << std::endl;
    ClapTrap h("huge_damage");
    h.takeDamage(4294967295u);
    ClapTrap k("huge_repair");
    k.beRepaired(4294967295u);
    k.takeDamage(0);

    return 0;
}