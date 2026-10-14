#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>
#include <string>

class ClapTrap{
    public:
    ClapTrap();

    ClapTrap(const std::string& name);

    ~ClapTrap();
    
    ClapTrap(const ClapTrap &other);

    ClapTrap & operator=(const ClapTrap &other);

    void attack(const std::string& target);
    
    void takeDamage(unsigned int amount);
    
    void beRepaired(unsigned int amount);
    private:
    std::string new_name;
    unsigned int hit_point;
    unsigned int energy_point;
    unsigned int attack_damage;

};
#endif