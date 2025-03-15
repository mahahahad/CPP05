#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {
    try {
        ShrubberyCreationForm a("home");
        RobotomyRequestForm b("Joseph Martello");
        PresidentialPardonForm c("This Year's Domestic Turkey");
        Bureaucrat  jo("Jo", 137);
        Bureaucrat  powerful("powerful", 1);

        a.beSigned(jo);
        a.execute(jo);
        b.beSigned(powerful);
        b.execute(powerful);
        c.beSigned(powerful);
        c.execute(powerful);
    } catch (std::exception &e) {
        std::cout << e.what();
    }
}
