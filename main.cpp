#include "include/library.h"
#include "include/admin.h"
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

int main()
{
    fs::create_directories("data");

    Library lib;
    lib.loadBooks();
    lib.loadUsers();

    cout << "Welcome to the Smart Library Management System\n";
    while (true)
    {
        cout << "\n1. Register\n2. Login as User\n3. Login as Admin\n4. Exit\nEnter choice: ";
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            lib.registerUser();
        }
        else if (choice == 2)
        {
            if (lib.loginUser())
            {
                lib.userMenu();
            }
        }
        else if (choice == 3)
        {
            Admin admin("admin");
            cout << "Admin login assumed for demo.\n";
            lib.adminMenu(&admin);
        }
        else if (choice == 4)
        {
            lib.saveBooks();
            lib.saveUsers();
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    cout << "Thank you for using the system.\n";
    return 0;
}
