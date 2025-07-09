#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "user.h"
#include "admin.h"
#include <vector>
#include <map>
using namespace std;

class Library {
    vector<Book> books;
    map<string, User> users;
    string currentUser;

public:
    void loadBooks();
    void saveBooks() const;

    void loadUsers();
    void saveUsers() const;

    void addBook(const Book &book);
    void listBooks() const;

    void borrowBook(int id);
    void returnBook(int id);

    void registerUser();
    bool loginUser();
    void userMenu();
    void adminMenu(Person* admin);
};

#endif
