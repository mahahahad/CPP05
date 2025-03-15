#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"

#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"

class   AForm;

class   Bureaucrat {
    public:
        Bureaucrat( const std::string& name, const int grade );
        Bureaucrat( const Bureaucrat& copy );
        Bureaucrat& operator=( const Bureaucrat& copy );
        ~Bureaucrat();
    
    public:
        std::string getName( void ) const;
        int         getGrade( void ) const;
        void        increaseGrade( void );
        void        decreaseGrade( void );
        void        executeForm( const AForm& form );

    public:
        class   GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class   GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

    private:
        const std::string   name;
        int                 grade;

    private:
        Bureaucrat();
};

std::ostream&   operator<<( std::ostream& output, const Bureaucrat& bc );

#endif
