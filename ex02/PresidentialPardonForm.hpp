#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class   PresidentialPardonForm: public AForm {
    /* PUBLIC */
    // Requirements (Orthodox Canonical Form)
    public:
        PresidentialPardonForm( const std::string& target );
        PresidentialPardonForm( const PresidentialPardonForm& copy );
        PresidentialPardonForm&  operator=(
            const PresidentialPardonForm& copy
        );
        ~PresidentialPardonForm( void );

    // Member functions
    public:
        void    executeForm( void ) const;

    /* PRIVATE */
    // Member functions
    private:
        PresidentialPardonForm( void );

    // Attributes
    private:
        std::string _target;
};

#endif
