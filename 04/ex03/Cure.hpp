#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Cure : public AMateria {

  public:
	Cure();
	Cure(Cure const &src);
	~Cure();

	Cure *clone() const;
	void use(ICharacter &target);

	Cure &operator=(Cure const &rhs);

  private:
};

std::ostream &operator<<(std::ostream &o, Cure const &i);

#endif /* ************************************************************ CURE_H  \
		*/