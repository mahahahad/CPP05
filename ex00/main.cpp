#include "Bureaucrat.hpp"

int main(void) {
    {
        Bureaucrat john("John", 10);
        Bureaucrat jane("Jane", 5);

        std::cout << john << jane;
        // Only grade changes because name cannot be changed
        john = jane;
        std::cout << john;
    }
    {
        try {
            Bureaucrat invalid("invalid", 2);
            
            std::cout << invalid;
            invalid.increaseGrade();
            std::cout << invalid;
            invalid.increaseGrade();

        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }
    {
        try {
            Bureaucrat invalid2("invalid2", 149);
            std::cout << invalid2;
            invalid2.decreaseGrade();
            std::cout << invalid2;
            invalid2.decreaseGrade();
        } catch (std::exception &e) {
            std::cout << e.what();
        }
    }
}
