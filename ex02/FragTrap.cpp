#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("francesco") {
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "FragTrap default constructor called for " << new_name << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	hit_point = 100;
	energy_point = 100;
	attack_damage = 30;
	std::cout << "FragTrap constructor called with name " << new_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called for " << new_name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << new_name << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (energy_point > 0 && hit_point > 0) {
		std::cout << "FragTrap " << new_name << " attacks " << target
		          << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_point--;
	} else {
		std::cout << "FragTrap " << new_name
		          << " has no energy or hit points to attack!" << std::endl;
	}
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << new_name << " asks for a high five!" << std::endl;
}