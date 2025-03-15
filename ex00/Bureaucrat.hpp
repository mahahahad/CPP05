#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RED "\033[31m"
#define RESET "\033[0m"

#include <iostream>
#include <exception>
#include <string>

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

std::ostream&   operator<<(std::ostream& output, const Bureaucrat& bc);

#endif
