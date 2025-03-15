#!/bin/zsh
#
# Utility shell script to create classes
# Simply pass the name of the file to create and the script will create a class 
# with a header file and an implementation file with the provided name.

for file in "$@"; do
    echo "#ifndef ${file:u}_HPP
#define ${file:u}_HPP

#include <iostream>

class   $file {
    /* PUBLIC */
    // Requirements (Orthodox Canonical Form)
    public:
        $file( void );
        $file( const $file& copy );
        $file&  operator=( const $file& copy );
        ~$file( void );
    
    // Member functions
    public:
        // Members go here

    /* PRIVATE */
    // Member functions
    private:
        // Functions

    // Attributes
    private:
        // Attributes
};

#endif" > $file.hpp
    echo "#include \"$file.hpp\"
    
// Default Constructor
$file::$file() {

}

// Copy Constructor
$file::$file(const $file& copy) {

}

// Copy Assignment Operator
$file&  $file::operator=(const $file& copy) {

}

// Destructor
$file::~$file() {
    std::cout << \"Destructor called for $file\" << std::endl;
}" > $file.cpp
done
