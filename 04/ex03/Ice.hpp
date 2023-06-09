#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Ice : public AMateria {

  public:
	Ice();
	Ice(Ice const &src);
	~Ice();

	Ice *clone() const;
	void use(ICharacter &target);

	Ice &operator=(Ice const &rhs);

  private:
};

std::ostream &operator<<(std::ostream &o, Ice const &i);

#endif /* ************************************************************* ICE_H  \
		*/