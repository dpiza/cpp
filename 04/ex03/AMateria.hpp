#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria {

  public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	virtual ~AMateria();

	AMateria &operator=(AMateria const &rhs);

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target) = 0;

	std::string const &getType(void) const;

  protected:
	std::string const _type;
};

std::ostream &operator<<(std::ostream &o, AMateria const &i);

#endif /* ******************************************************** AMATERIA_H  \
		*/