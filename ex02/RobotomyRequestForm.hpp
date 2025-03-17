#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class   RobotomyRequestForm: public AForm {
    /* PUBLIC */
    // Requirements (Orthodox Canonical Form)
    public:
        RobotomyRequestForm( const std::string& target );
        RobotomyRequestForm( const RobotomyRequestForm& copy );
        RobotomyRequestForm&  operator=( const RobotomyRequestForm& copy );
        ~RobotomyRequestForm();

    // Member functions
    public:
        void    beExecuted( void ) const;

    /* PRIVATE */
    // Member functions
    private:
        RobotomyRequestForm( void );

    // Attributes
    private:
        std::string _target;
};

#endif
