#ifndef USER_H
#define USER_H

#include "person.h"
#include <string>
using namespace std;

class User : public Person {
    string username;
    string password;

public:
    User(string uname = "", string pwd = "");

    string getUsername() const;
    bool authenticate(const string &pwd) const;

    void displayProfile() const override;
    string getRole() const override;

    string serialize() const;
    static User deserialize(const string &data);
};

#endif
