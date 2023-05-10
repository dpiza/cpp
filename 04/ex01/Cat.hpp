#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {

  public:
	Cat();
	Cat(Cat const &src);
	~Cat();

	Cat &operator=(Cat const &rhs);

	void makeSound(void) const;

	Brain getBrain(void);

  private:
	Brain *_brain;
};

std::ostream &operator<<(std::ostream &o, Cat const &i);

#endif /* ************************************************************* CAT_H  \
		*/