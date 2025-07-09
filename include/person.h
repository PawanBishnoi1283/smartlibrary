#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
public:
    virtual void displayProfile() const = 0;
    virtual std::string getRole() const = 0;
    virtual ~Person() {}
};

#endif
