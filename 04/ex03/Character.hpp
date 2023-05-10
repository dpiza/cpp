#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {

  public:
	Character(std::string name);
	Character(ICharacter const &src);
	~Character();

	Character &operator=(ICharacter const &rhs);

	AMateria *getMateria(int idx) const;
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

  private:
	std::string _name;
	AMateria *_inventory[4];
};

std::ostream &operator<<(std::ostream &o, Character const &i);

#endif /* ******************************************************* CHARACTER_H  \
		*/