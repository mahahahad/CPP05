#include "Form.hpp"

int main(void) {
    {
        Form bruhForm("Bruh Form", 10, 5);
        Bureaucrat john("John", 2);
        std::cout << bruhForm;
        john.signForm(bruhForm);
        std::cout << bruhForm;
    }
    {
        try {
            Form extremelyImportantForm("ExtremelyImportantForm", 1, 1);
            Bureaucrat joe("Joe", 2);
            std::cout << extremelyImportantForm;
            joe.signForm(extremelyImportantForm);
            std::cout << extremelyImportantForm;
        } catch (Form::GradeTooLowException &e) {
            std::cout << e.what();
        }
    }
}
