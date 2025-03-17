#include "AForm.hpp"

AForm::AForm(
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

AForm::AForm(const AForm& copy):
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

AForm& AForm::operator=(const AForm& copy) {
    isSigned = copy.isSigned;
    std::cout << "Form " BOLD ITALIC << name
        << RESET " was copied (assignment operator)" << std::endl;
    return (*this);
}

AForm::~AForm() {
    std::cout << "Form " BOLD ITALIC << name
        << RESET " was destructed" << std::endl;
}

std::string AForm::getName(void) const {
    return (name);
}

bool    AForm::getIsSigned(void) const {
    return (isSigned);
}

int AForm::getSignGrade(void) const {
    return (signGrade);
}

int AForm::getExecGrade(void) const {
    return (execGrade);
}

void    AForm::beSigned(const Bureaucrat& bc) {
    if (bc.getGrade() > signGrade) {
        std::cerr << "Bureaucrat " BOLD ITALIC << bc.getName()
            << RESET RED " couldn't sign " RESET BOLD ITALIC << name
            << RESET YELLOW " because their grade was too low." RESET
            << std::endl;
        std::cerr << YELLOW "- (Required grade: " << getSignGrade() << ")" RESET
            << std::endl;
        std::cerr << YELLOW "- (Provided grade: " << bc.getGrade()
            << ")" RESET << std::endl;
        throw GradeTooLowException();
    }

    // Set the sign status to true
    isSigned = true;

    // Display a message indicating the successful signing
    std::cout << "Bureaucrat " BOLD ITALIC << bc.getName()
        << RESET GREEN " signed " RESET BOLD ITALIC << name
        << RESET GREEN " successfully" RESET << std::endl;
}

void    AForm::execute(const Bureaucrat & executor) const {
    if (!getIsSigned()) {
        std::cerr
            << "The request" RED " could not be executed" RESET " because "
            << BOLD ITALIC << getName() << RESET " is"
            << RED " not signed." RESET << std::endl;
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecGrade()) {
        std::cerr << "Bureaucrat " BOLD ITALIC << executor.getName()
            << RESET RED " couldn't execute " RESET BOLD ITALIC << getName()
            << RESET YELLOW " because their grade was too low." RESET
            << std::endl;
        std::cerr << YELLOW "- (Required grade: " << getExecGrade() << ")" RESET
            << std::endl;
        std::cerr << YELLOW "- (Provided grade: " << executor.getGrade()
            << ")" RESET << std::endl;
        throw GradeTooLowException();
    }

    // Call the method specific to each derived class
    beExecuted();

    // Display a message indicating successful execution
    std::cout << "Bureaucrat " BOLD ITALIC << executor.getName()
        << RESET GREEN " executed " RESET BOLD ITALIC << getName()
        << RESET GREEN " successfully" RESET << std::endl;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return (BOLD RED "ERROR: " RESET "The provided grade is too low\n");
}

const char* AForm::GradeTooHighException::what() const throw() {
    return (BOLD RED "ERROR: " RESET "The provided grade is too high\n");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return (BOLD RED "ERROR: " RESET "The form is not signed\n");
}

// Stream insertion overload
std::ostream&   operator<<(std::ostream& output, const AForm& form) {
    output << form.getName() << ":\n"
        << (form.getIsSigned() ? "- Signed\n": "- Not Signed\n")
        << "- Required grade to sign: " << form.getSignGrade() << "\n"
        << "- Required grade to execute: " << form.getExecGrade()
        << std::endl;
    return (output);
}
