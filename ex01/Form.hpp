#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class   Bureaucrat;

class   Form {
    public:
        Form(
            const std::string& name,
            bool isSigned,
            const int signReqGrade,
            const int execReqGrade
        );
        Form( const Form& copy );
        Form&   operator=( const Form& copy );
        ~Form();

    public:
        std::string         getName( void ) const;
        bool                getIsSigned( void ) const;
        int                 getSignReqGrade( void ) const;
        int                 getExecReqGrade( void ) const;
        void                beSigned( const Bureaucrat& bc );

    public:
        class   GradeTooLowException: public std::exception {
            public:
                virtual const char  *what();
        };
        class   GradeTooHighException: public std::exception {
            public: 
                virtual const char  *what();
        };

    private:
        const std::string   name;
        bool                isSigned;
        // Required grade for signing the form
        const int           signReqGrade;
        // Required grade for executing the form
        const int           execReqGrade;
};

std::ostream&   operator<<(std::ostream& output, const Form& form);

#endif
