#ifndef INTERN_HPP
#define INTERN_HPP

#include <cstring>
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class   Intern {
    /* PUBLIC */
    // Requirements (Orthodox Canonical Form)
    public:
        Intern( void );
        Intern( const Intern& copy );
        Intern&  operator=( const Intern& copy );
        ~Intern( void );
    
    // Member functions
    public:
        AForm   *makeForm(
            const std::string& formName,
            const std::string& formTarget
        );
    
    public:
        class   InvalidFormNameException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

    /* PRIVATE */
    // Member functions
    private:
        // Functions

    // Attributes
    private:
        // Attributes
};

#endif
