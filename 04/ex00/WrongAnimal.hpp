#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

  public:
	WrongAnimal();
	WrongAnimal(WrongAnimal const &);
	virtual ~WrongAnimal();

	WrongAnimal &operator=(WrongAnimal const &);

	std::string getType(void) const;
	void setType(std::string);

	virtual void makeSound(void) const;

  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &, WrongAnimal const &);

#endif /* ***************************************************** WRONGANIMAL_H  \
		*/