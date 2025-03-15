#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void) {
    {
        Intern someRandomIntern;
        Bureaucrat bigMan("Big Show", 1);
        AForm *result;
        try {
            result = someRandomIntern.makeForm("shrubbery creation", "Bender");
            result->beSigned(bigMan);
            result->execute(bigMan);
            delete result;
        } catch (std::exception &e) {
            std::cerr << e.what();
        }
    }
}
