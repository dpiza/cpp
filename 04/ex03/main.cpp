#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
	{
		std::cout << "PDF default test" << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << "Materia polymorphism test" << std::endl;
		ICharacter *me = new Character("me");
		AMateria *ice = new Ice();
		AMateria *iceCpy;

		std::cout << "Ice->getType: " << ice->getType() << std::endl;
		ice->use(*me);

		std::cout << "Clone" << std::endl;
		iceCpy = ice->clone();
		std::cout << "IceCopy->getType: " << iceCpy->getType() << std::endl;
		iceCpy->use(*me);

		std::cout << "Assign" << std::endl;
		AMateria *iceAssign = new Ice();
		*iceAssign = *ice;
		std::cout << "iceAssign: " << iceAssign->getType() << std::endl;
		iceAssign->use(*me);
		std::cout << std::endl;

		std::cout << "Ice address:\t\t" << ice << std::endl;
		std::cout << "iceAssign address:\t" << iceAssign << std::endl;

		delete me;
		delete ice;
		delete iceCpy;
		delete iceAssign;
	}
	{
		std::cout << std::endl << "Character test" << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");
		std::cout << "Created character " << me->getName() << std::endl;
		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter *bob = new Character("bob");
		std::cout << "Created character " << bob->getName() << std::endl;
		ICharacter *meCopy = new Character(*me);
		std::cout << "Created character " << meCopy->getName()
				  << " as me's copy " << std::endl;

		std::cout << "me->use " << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(3, *bob);

		std::cout << std::endl;

		std::cout << "me->unequip(1) " << std::endl;
		me->unequip(1);
		me->use(0, *bob);
		me->use(1, *bob);

		std::cout << std::endl << "meCopy->use " << std::endl;
		meCopy->use(0, *bob);
		meCopy->use(1, *bob);

		delete me;
		delete bob;
		delete meCopy;
		delete src;
	}
	return 0;
}