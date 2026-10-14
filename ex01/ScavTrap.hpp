#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap{
    public:
    ScavTrap();
    ScavTrap(const std::string& name);
    virtual ~ScavTrap();
    ScavTrap(const ScavTrap &other);
    ScavTrap & operator=(const ScavTrap &other);
    void guardGate() const;
    virtual void attack(const std::string& target);
};
#endif