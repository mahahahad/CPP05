#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
    AForm("ShrubberyCreationForm", 145, 137),
    _target(target)
{
    std::cout << BOLD ITALIC << getName() << " was created" RESET << std::endl;
}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm& copy
):
    AForm(copy),
    _target(copy._target)
{
    std::cout << BOLD ITALIC << getName() << " was copied" RESET << std::endl;
}

// Copy Assignment Operator
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy) {
    _target = copy._target;
    return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "Destructor called for " BOLD ITALIC << getName()
        << RESET << std::endl;
}

void    ShrubberyCreationForm::beExecuted(void) const {
    std::ofstream outputFile((_target + "_shrubbery").c_str());

    outputFile
    << "        # #### ####" << "\n"
    << "     ### \\/#|### |/####" << "\n"
    << "    ##\\/#/ \\||/##/_/##/_#" << "\n"
    << "   ###  \\/###|/ \\/ # ###  " << "\n"
    << " ##_\\_#\\_\\## | #/###_/_####" << "\n"
    << "## #### # \\ #| /  #### ##/##" << "\n"
    << " __#_--###`  |{,###---###-~" << "\n"
    << "           \\ }{" << "\n"
    << "             }}{" << "\n"
    << "             }}{" << "\n"
    << "             {{}" << "\n"
    << "       , -=-~{ .-^- _" << "\n"
    << "             `}" << "\n"
    << "              {" << "\n";
    outputFile.close();
}
