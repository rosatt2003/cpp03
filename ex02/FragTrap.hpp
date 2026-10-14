#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string& name);
	~FragTrap();
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);

	void highFivesGuys();
	virtual void attack(const std::string& target);
};

#endif