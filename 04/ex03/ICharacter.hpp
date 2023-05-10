#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>

class AMateria;

class ICharacter {

  public:
	virtual ~ICharacter(){};
	virtual AMateria *getMateria(int idx) const = 0;
	virtual std::string const &getName() const = 0;
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};

std::ostream &operator<<(std::ostream &o, ICharacter const &i);

#endif