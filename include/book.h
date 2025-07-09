#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
    int id;
    string title;
    string author;
    bool isAvailable;

public:
    Book(int id = 0, string title = "", string author = "", bool available = true);

    int getId() const;
    string getTitle() const;
    string getAuthor() const;
    bool available() const;

    void borrowBook();
    void returnBook();
    void display() const;

    string serialize() const;
    static Book deserialize(const string &data);
};

#endif
