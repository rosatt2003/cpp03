#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main(){
    std::cout<< "--- Test: ScavTrap ---" << std::endl;
    ScavTrap s("Ludovico");
    ScavTrap sa("andrea");
    ScavTrap sb;
    s.attack("luigi");
    sa.takeDamage(30);
    sa.takeDamage(20);
    sb.guardGate();

    std::cout << "--- Test: ScavTrap copy and assignment ---" << std::endl;
    ScavTrap scopy(s);
    ScavTrap sassign("tmp");
    sassign = sa;
    scopy.guardGate();
    sassign.attack("target");

    std::cout << "--- Test: polymorphism ---" << std::endl;
    ClapTrap* poly = new ScavTrap("poly");
    poly->attack("enemy");
    delete poly;

    std::cout << "--- Test: ScavTrap energy exhausted ---" << std::endl;
    for (int i = 0; i < 50; i++)
        s.attack("dummy");
    s.attack("dummy");
    s.beRepaired(1);
    
    ClapTrap a("Alice");
    ClapTrap b("Bob");
    ClapTrap c;
    a.attack("peppe");
    b.takeDamage(3);
    c.attack("training_dummy");

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