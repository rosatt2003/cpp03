#include "ClapTrap.hpp"
#include <climits>

ClapTrap::ClapTrap() : new_name("Lorenzo"), hit_point(10), energy_point(10), attack_damage(0) {
	std::cout << "constructor default called " << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : new_name(name), hit_point(10), energy_point(10), attack_damage(0) {
	std::cout << "constructor called with name " << new_name << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "destructor called " << new_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: new_name(other.new_name),
	  hit_point(other.hit_point),
	  energy_point(other.energy_point),
	  attack_damage(other.attack_damage) {
	std::cout << "copy constructor called " << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "copy assignment operator called " << std::endl;
	if (this != &other) {
		new_name = other.new_name;
		hit_point = other.hit_point;
		energy_point = other.energy_point;
		attack_damage = other.attack_damage;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (energy_point > 0 && hit_point > 0) {
		std::cout << "ClapTrap " << new_name << " attacks " << target
		          << ", causing " << attack_damage << " points of damage!" << std::endl;
		energy_point--;
	} else {
		std::cout << "ClapTrap " << new_name << " has no energy or hit points to attack!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_point > 0) {
		unsigned int real_damage = (amount >= hit_point) ? hit_point : amount;
		hit_point -= real_damage;
		std::cout << "ClapTrap " << new_name << " takes " << real_damage
		          << " points of damage! Remaining hit points: "
		          << hit_point << std::endl;
	} else {
		std::cout << "ClapTrap " << new_name << " is already dead!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (energy_point > 0 && hit_point > 0) {
		unsigned int real_repair = amount;
		if (real_repair > UINT_MAX - hit_point)
			real_repair = UINT_MAX - hit_point;
		hit_point += real_repair;
		energy_point--;
		std::cout << "ClapTrap " << new_name << " is repaired by " << real_repair
		          << " points! Current hit points: " << hit_point << std::endl;
	} else {
		std::cout << "ClapTrap " << new_name << " has no energy or hit points to repair!" << std::endl;
	}
}