#include "../include/admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string uname) : username(uname) {}

void Admin::displayProfile() const
{
    cout << "Admin Profile\nUsername: " << username << endl;
}

string Admin::getRole() const
{
    return "Admin";
}
