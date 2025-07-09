#include "../include/book.h"
#include <iostream>
#include <stdexcept>

Book::Book(int id, string title, string author, bool available)
    : id(id), title(title), author(author), isAvailable(available) {}

int Book::getId() const { return id; }
string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
bool Book::available() const { return isAvailable; }

void Book::borrowBook()
{
    if (!isAvailable)
        throw runtime_error("Book is already borrowed.");
    isAvailable = false;
}

void Book::returnBook()
{
    isAvailable = true;
}

void Book::display() const
{
    cout << "ID: " << id << " | Title: " << title << " | Author: " << author
         << " | " << (isAvailable ? "Available" : "Not Available") << endl;
}

string Book::serialize() const
{
    return to_string(id) + "," + title + "," + author + "," + (isAvailable ? "1" : "0");
}

Book Book::deserialize(const string &data)
{
    size_t p1 = data.find(',');
    size_t p2 = data.find(',', p1 + 1);
    size_t p3 = data.find(',', p2 + 1);

    int id = stoi(data.substr(0, p1));
    string title = data.substr(p1 + 1, p2 - p1 - 1);
    string author = data.substr(p2 + 1, p3 - p2 - 1);
    bool avail = data[p3 + 1] == '1';

    return Book(id, title, author, avail);
}
