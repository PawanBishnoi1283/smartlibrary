#include "../include/user.h"
#include <iostream>

User::User(string uname, string pwd) : username(uname), password(pwd) {}

string User::getUsername() const { return username; }

bool User::authenticate(const string &pwd) const
{
    return password == pwd;
}

void User::displayProfile() const
{
    cout << "User Profile\nUsername: " << username << endl;
}

string User::getRole() const
{
    return "User";
}

string User::serialize() const
{
    return username + "," + password;
}

User User::deserialize(const string &data)
{
    size_t p = data.find(',');
    string uname = data.substr(0, p);
    string pwd = data.substr(p + 1);
    return User(uname, pwd);
}
