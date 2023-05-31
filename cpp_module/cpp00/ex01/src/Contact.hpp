#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
# include <iomanip>
#include "ContactParser.hpp"

class Contact {
    private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    public:
    Contact();
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    void info();
    void setting();
};

#endif
