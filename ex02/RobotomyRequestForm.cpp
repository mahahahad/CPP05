#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
    AForm("RobotomyRequestForm", 72, 45),
    _target(target)
{
    std::cout << BOLD ITALIC << getName() << " was created" RESET << std::endl;
}
    
// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(
    const RobotomyRequestForm& copy
):
    AForm(copy),
    _target(copy._target)
{
    std::cout << BOLD ITALIC << getName() << " was copied" RESET << std::endl;
}

// Copy Assignment Operator
RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    _target = copy._target;
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor called for " BOLD ITALIC << getName()
        << RESET << std::endl;
}

void    RobotomyRequestForm::executeForm(void) const {
    srand(time(0));
    std::cout << "* DRILLING NOISES *" << std::endl;
    std::cout << _target
        << (rand() % 2 ?
            " has been Robotomized successfully!" :
            " has not been Robotomized.")
        << std::endl;
}
