#include "Form.hpp"

Form::Form(
    const std::string& name,
    const int signGrade,
    const int execGrade
):
    name(name),
    isSigned(false),
    signGrade(signGrade),
    execGrade(execGrade)
{
    if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    } else if (signGrade < 1 || execGrade < 1) {
        throw GradeTooHighException();
    }
    std::cout << "Form " BOLD ITALIC << name
        << RESET " was constructed" << std::endl;
};

Form::Form(const Form& copy):
    name(copy.name),
    isSigned(copy.isSigned),
    signGrade(copy.signGrade),
    execGrade(copy.execGrade)
{
    if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    } else if (signGrade < 1 || execGrade < 1) {
        throw GradeTooHighException();
    }
    std::cout << "Form " BOLD ITALIC << name
        << RESET " was copied" << std::endl;
}

Form& Form::operator=(const Form& copy) {
    isSigned = copy.isSigned;
    std::cout << "Form " BOLD ITALIC << name
        << RESET " was copied (assignment operator)" << std::endl;
    return (*this);
}

Form::~Form() {
    std::cout << "Form " BOLD ITALIC << name
        << RESET " was destructed" << std::endl;
}

std::string Form::getName(void) const {
    return (name);
}

bool    Form::getIsSigned(void) const {
    return (isSigned);
}

int Form::getSignGrade(void) const {
    return (signGrade);
}

int Form::getExecGrade(void) const {
    return (execGrade);
}

void    Form::beSigned(const Bureaucrat& bc) {
    if (bc.getGrade() <= signGrade) {
        isSigned = true;
        std::cout << "Bureaucrat " BOLD ITALIC << bc.getName()
            << RESET GREEN " signed " RESET BOLD ITALIC << name
            << RESET GREEN " successfully" RESET << std::endl;
    } else {
        std::cout << "Bureaucrat " BOLD ITALIC << bc.getName()
            << RESET RED " couldn't sign " RESET BOLD ITALIC << name
            << RESET YELLOW " because their grade was too low." RESET
            << std::endl;
        throw Form::GradeTooLowException();
    }
}

const char* Form::GradeTooLowException::what() const throw() {
    return (BOLD RED "ERROR: " RESET "The provided grade is too low\n");
}

const char* Form::GradeTooHighException::what() const throw() {
    return (BOLD RED "ERROR: " RESET "The provided grade is too high\n");
}

// Stream insertion overload
std::ostream&   operator<<(std::ostream& output, const Form& form) {
    output << form.getName() << ":\n"
        << (form.getIsSigned() ? "- Signed\n": "- Not Signed\n")
        << "- Required grade to sign: " << form.getSignGrade() << "\n"
        << "- Required grade to execute: " << form.getExecGrade()
        << std::endl;
    return (output);
}
