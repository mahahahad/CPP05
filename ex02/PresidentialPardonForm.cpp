#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
    AForm("PresidentialPardonForm", 25, 5),
    _target(target)
{
    std::cout << BOLD ITALIC << getName() << " was created" RESET << std::endl;
}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm
& copy
):
    AForm(copy),
    _target(copy._target)
{
    std::cout << BOLD ITALIC << getName() << " was copied" RESET << std::endl;
}

// Copy Assignment Operator
PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm
& copy) {
    _target = copy._target;
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor called for " BOLD ITALIC << getName()
        << RESET << std::endl;
}

void    PresidentialPardonForm::beExecuted(void) const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox!"
        << std::endl;
}
