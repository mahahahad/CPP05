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
#include "Form.hpp"

class   Form;

class   Bureaucrat {
    public:
        Bureaucrat( const std::string& name, const int grade );
        ~Bureaucrat();
        Bureaucrat( const Bureaucrat& copy );
        Bureaucrat& operator=( const Bureaucrat& copy );
    
    public:
        std::string getName( void ) const;
        int         getGrade( void ) const;
        void        increaseGrade( void );
        void        decreaseGrade( void );
        void        signForm( Form& form );

    public:
        class   GradeTooLowException: public std::exception {
            public:
                virtual const char* what();
        };
        class   GradeTooHighException: public std::exception {
            public:
                virtual const char* what();
        };

    private:
        const std::string   name;
        int                 grade;

    private:
        Bureaucrat();
};

std::ostream&   operator<<( std::ostream& output, const Bureaucrat& bc );

#endif
