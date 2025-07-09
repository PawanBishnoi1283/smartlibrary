#include "../include/library.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

const string BOOKS_FILE = "data/books.txt";
const string USERS_FILE = "data/users.txt";

void Library::loadBooks()
{
    ifstream file(BOOKS_FILE);
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
            books.push_back(Book::deserialize(line));
    }
    file.close();
}

void Library::saveBooks() const
{
    ofstream file(BOOKS_FILE);
    for (const auto &book : books)
        file << book.serialize() << endl;
    file.close();
}

void Library::loadUsers()
{
    ifstream file(USERS_FILE);
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
        {
            User u = User::deserialize(line);
            users[u.getUsername()] = u;
        }
    }
    file.close();
}

void Library::saveUsers() const
{
    ofstream file(USERS_FILE);
    for (const auto &pair : users)
        file << pair.second.serialize() << endl;
    file.close();
}

void Library::addBook(const Book &book)
{
    books.push_back(book);
    cout << "Book added successfully.\n";
}

void Library::listBooks() const
{
    if (books.empty())
    {
        cout << "No books available.\n";
        return;
    }
    for (const auto &book : books)
        book.display();
}

void Library::borrowBook(int id)
{
    for (auto &book : books)
    {
        if (book.getId() == id)
        {
            book.borrowBook();
            cout << "Book borrowed.\n";
            return;
        }
    }
    throw runtime_error("Book ID not found.");
}

void Library::returnBook(int id)
{
    for (auto &book : books)
    {
        if (book.getId() == id)
        {
            book.returnBook();
            cout << "Book returned.\n";
            return;
        }
    }
    throw runtime_error("Book ID not found.");
}

void Library::registerUser()
{
    string uname, pwd;
    cout << "Enter new username: ";
    cin >> uname;
    if (users.find(uname) != users.end())
    {
        cout << "User already exists.\n";
        return;
    }
    cout << "Enter password: ";
    cin >> pwd;
    users[uname] = User(uname, pwd);
    cout << "User registered successfully.\n";
}

bool Library::loginUser()
{
    string uname, pwd;
    cout << "Enter username: ";
    cin >> uname;
    cout << "Enter password: ";
    cin >> pwd;

    if (users.find(uname) != users.end() && users[uname].authenticate(pwd))
    {
        cout << "Login successful.\n";
        currentUser = uname;
        return true;
    }
    cout << "Invalid credentials.\n";
    return false;
}

void Library::userMenu()
{
    while (true)
    {
        cout << "\n1. List Books\n2. Borrow Book\n3. Return Book\n4. Logout\nEnter choice: ";
        int choice;
        cin >> choice;
        try
        {
            if (choice == 1)
            {
                listBooks();
            }
            else if (choice == 2)
            {
                int id;
                cout << "Enter Book ID to borrow: ";
                cin >> id;
                borrowBook(id);
            }
            else if (choice == 3)
            {
                int id;
                cout << "Enter Book ID to return: ";
                cin >> id;
                returnBook(id);
            }
            else if (choice == 4)
            {
                currentUser = "";
                break;
            }
            else
            {
                cout << "Invalid choice.\n";
            }
        }
        catch (exception &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
}

void Library::adminMenu(Person *admin)
{
    admin->displayProfile();
    while (true)
    {
        cout << "\n1. List Books\n2. Add Book\n3. Logout\nEnter choice: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            listBooks();
        }
        else if (choice == 2)
        {
            int id;
            string title, author;
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            addBook(Book(id, title, author));
        }
        else if (choice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
}
