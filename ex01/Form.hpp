#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form {
    public:
        Form(
            const std::string& name,
            const int signGrade,
            const int execGrade
        );
        Form( const Form& copy );
        Form&   operator=( const Form& copy );
        ~Form();

    public:
        std::string         getName( void ) const;
        bool                getIsSigned( void ) const;
        int                 getSignGrade( void ) const;
        int                 getExecGrade( void ) const;
        void                beSigned( const Bureaucrat& bc );

    public:
        class   GradeTooLowException: public std::exception {
            public:
                virtual const char  *what() const throw();
        };
        class   GradeTooHighException: public std::exception {
            public: 
                virtual const char  *what() const throw();
        };

    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           execGrade;
};

std::ostream&   operator<<( std::ostream& output, const Form& form );

#endif
