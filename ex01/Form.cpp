#include "Form.hpp"

Form::Form(
    const std::string& name,
    bool isSigned,
    const int signReqGrade,
    const int execReqGrade
):
    name(name),
    isSigned(isSigned),
    signReqGrade(signReqGrade),
    execReqGrade(execReqGrade)
{
    if (signReqGrade > 150 || execReqGrade > 150) {
        throw GradeTooLowException();
    } else if (signReqGrade < 1 || execReqGrade < 1) {
        throw GradeTooHighException();
    }
    std::cout << "Form " << name << " was constructed" << std::endl;
};

Form::Form(const Form& copy):
    name(copy.name),
    isSigned(copy.isSigned),
    signReqGrade(copy.signReqGrade),
    execReqGrade(copy.execReqGrade)
{
    if (signReqGrade > 150 || execReqGrade > 150) {
        throw GradeTooLowException();
    } else if (signReqGrade < 1 || execReqGrade < 1) {
        throw GradeTooHighException();
    }
    std::cout << "Form " << name << " was copied" << std::endl;
}

Form& Form::operator=(const Form& copy) {
    isSigned = copy.isSigned;
    std::cout << "Form " << name << " was copied (assignment operator)" 
        << std::endl;
    return (*this);
}

Form::~Form() {
    std::cout << "Form " << name << " was destructed" << std::endl;
}

std::string Form::getName(void) const {
    return (name);
}

bool    Form::getIsSigned(void) const {
    return (isSigned);
}

int Form::getSignReqGrade(void) const {
    return (signReqGrade);
}

int Form::getExecReqGrade(void) const {
    return (execReqGrade);
}

void    Form::beSigned(const Bureaucrat& bc) {
    if (bc.getGrade() <= signReqGrade) {
        isSigned = true;
        std::cout << "Bureaucrat " << bc.getName() << " signed " << name
            << " form" << std::endl;
    } else {
        std::cout << "Bureaucrat " << bc.getName() << " couldn't sign " << name
            << " because their grade was too low." << std::endl;
        // throw Form::GradeTooLowException();
    }
}

const char* Form::GradeTooLowException::what() {
    return (RED "ERROR:" RESET "The provided grade is too low\n");
}

const char* Form::GradeTooHighException::what() {
    return (RED "ERROR:" RESET "The provided grade is too high\n");
}

// Stream insertion overload
std::ostream&   operator<<(std::ostream& output, const Form& form) {
    output << form.getName() << ": "
        << (form.getIsSigned() ? "Signed": "Not Signed")
        << ", Required grade to sign: " << form.getSignReqGrade()
        << ", Required grade to execute: " << form.getExecReqGrade()
        << std::endl;
    return (output);
}
