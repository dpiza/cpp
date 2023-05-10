#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

  public:
	Animal();
	Animal(Animal const &);
	virtual ~Animal();

	Animal &operator=(Animal const &);

	std::string getType(void) const;
	void setType(std::string);

	virtual void makeSound(void) const = 0;

  protected:
	std::string _type;
};

std::ostream &operator<<(std::ostream &, Animal const &);

#endif /* ********************************************************** ANIMAL_H  \
		*/