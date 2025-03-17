#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class   ShrubberyCreationForm: public AForm {
    /* PUBLIC */
    // Requirements (Orthodox Canonical Form)
    public:
        ShrubberyCreationForm( const std::string& target );
        ShrubberyCreationForm( const ShrubberyCreationForm& copy );
        ShrubberyCreationForm&  operator=( const ShrubberyCreationForm& copy );
        ~ShrubberyCreationForm();

    // Member functions
    public:
        void    beExecuted( void ) const;

    /* PRIVATE */
    // Member functions
    private:
        ShrubberyCreationForm( void );

    // Attributes
    private:
        std::string _target;
};

#endif
