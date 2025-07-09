#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"
#include <string>
using namespace std;

class Admin : public Person {
    string username;

public:
    Admin(string uname = "admin");

    void displayProfile() const override;
    string getRole() const override;
};

#endif
