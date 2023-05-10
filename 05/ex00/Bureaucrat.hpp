#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat {
	class GradeTooHighException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  public:
		virtual const char *what() const throw();
	};

  public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	Bureaucrat &operator=(Bureaucrat const &rhs);

	void incrementGrade(void);
	void decrementGrade(void);

	std::string const getName(void) const;
	int getGrade(void) const;

  private:
	std::string const _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* ****************************************************** BUREAUCRAT_H  \
		*/