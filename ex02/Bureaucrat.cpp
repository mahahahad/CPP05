#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, const int grade):
    name(name), grade(grade)
{
    if (grade > 150) {
        throw GradeTooLowException();
    } else if (grade < 1) {
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat " BOLD ITALIC << name
        << RESET " was constructed" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat& copy):
    name(copy.name), grade(copy.grade)
{
    if (grade > 150) {
        throw GradeTooLowException();
    } else if (grade < 1) {
        throw GradeTooHighException();
    }
    std::cout << "Bureaucrat " BOLD ITALIC << name
        << RESET " was copied" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
    grade = copy.grade;
    std::cout << "Bureaucrat " BOLD ITALIC << name
        << RESET " was copied (assignment operator)" << std::endl;
    return (*this);
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " BOLD ITALIC << name
        << RESET " was destructed" << std::endl;
}

std::string Bureaucrat::getName(void) const {
    return (name);
}

int Bureaucrat::getGrade(void) const {
    return (grade);
}

void    Bureaucrat::increaseGrade(void) {
    if (grade == 1) {
        throw GradeTooHighException();
    } else {
        grade--;
    }
}

void    Bureaucrat::decreaseGrade(void) {
    if (grade == 150) {
        throw GradeTooLowException();
    } else {
        grade++;
    }
}

void    Bureaucrat::executeForm(const AForm& form) {
    (void) form;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return (RED "ERROR:" RESET "The provided grade is too low\n");
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return (RED "ERROR:" RESET "The provided grade is too high\n");
}

// Stream insertion overload
std::ostream&   operator<<(std::ostream& output, const Bureaucrat& bc) {
    output << bc.getName() << ", bureaucrat grade " << bc.getGrade()
        << std::endl;
    return (output);
}
