#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   AForm {
    public:
        AForm(
            const std::string& name,
            const int signGrade,
            const int execGrade
        );
        AForm( const AForm& copy );
        AForm&   operator=( const AForm& copy );
        virtual ~AForm();

    public:
        std::string         getName( void ) const;
        bool                getIsSigned( void ) const;
        int                 getSignGrade( void ) const;
        int                 getExecGrade( void ) const;
        void                beSigned( const Bureaucrat& bc );
        void                execute( Bureaucrat const & executor ) const;

    public:
        class   GradeTooLowException: public std::exception {
            public:
                virtual const char  *what() const throw();
        };
        class   GradeTooHighException: public std::exception {
            public:
                virtual const char  *what() const throw();
        };
        class   FormNotSignedException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

    protected:
        virtual void        beExecuted( void ) const = 0;

    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           execGrade;

    private:
        AForm();
};

std::ostream&   operator<<( std::ostream& output, const AForm& form );

#endif
