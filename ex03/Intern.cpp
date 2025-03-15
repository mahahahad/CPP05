#include "Intern.hpp"
    
// Default Constructor
Intern::Intern() {
    std::cout << "Constructor called for Intern" << std::endl;
}

// Copy Constructor
Intern::Intern(const Intern& copy) {
    (void) copy;
}

// Copy Assignment Operator
Intern&  Intern::operator=(const Intern& copy) {
    (void) copy;
    return (*this);
}

// Destructor
Intern::~Intern() {
    std::cout << "Destructor called for Intern" << std::endl;
}

std::string lowercase(const std::string& str) {
    std::string output;
    for (int i = 0; i < (int) strlen(str.c_str()); i++) {
        output += tolower(str[i]);
    }
    return (output);
}

AForm   *makeShrubberyForm(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

AForm   *makeRobotomyForm(const std::string& target) {
    return (new RobotomyRequestForm(target));
}

AForm   *makePresidentialForm(const std::string& target) {
    return (new PresidentialPardonForm(target));
}

const char *Intern::InvalidFormNameException::what() const throw() {
    return (BOLD RED "ERROR: " RESET "Invalid form name specified.\n");
}

AForm   *Intern::makeForm(
    const std::string& formName,
    const std::string& formTarget
)
{
    AForm   *form = NULL;
    std::string formList[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm   *(*formCreationFns[])(const std::string& target) = {
        &makeShrubberyForm,
        &makeRobotomyForm,
        &makePresidentialForm,
    };
    
    for (int i = 0; i < 3; i++) {
        if (lowercase(formName) == formList[i]) {
            form = formCreationFns[i](formTarget);
        }
    }
    if (!form)
        throw InvalidFormNameException();
    else
        std::cout << "Intern" GREEN " created " RESET BOLD ITALIC
            << form->getName() << RESET GREEN " successfully" RESET
            << std::endl;
    return (form);
}
