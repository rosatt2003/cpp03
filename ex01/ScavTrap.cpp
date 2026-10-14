#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_scavtrap"){
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap default constructor called for " << new_name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name){
    hit_point = 100;
    energy_point = 50;
    attack_damage = 20;
    std::cout << "ScavTrap constructor called with name " << new_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other){
    std::cout << "ScavTrap copy constructor called for " << new_name << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap &other){
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    if (this != &other){
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructor called for " << new_name << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (energy_point > 0 && hit_point > 0){
        std::cout << "ScavTrap " << new_name << " attacks " << target
                  << ", causing " << attack_damage << " points of damage!" << std::endl;
        energy_point--;
    }
    else{
        std::cout << "ScavTrap " << new_name
                  << " has no energy or hit points to attack!" << std::endl;
    }
}

void ScavTrap::guardGate() const{
    std::cout << "ScavTrap " << new_name << " is now in Gate keeper mode" << std::endl;
}