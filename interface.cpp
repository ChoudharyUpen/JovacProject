#include <iostream>
#include <string>

int main() {
    sql::Connection* con = connectDatabase();
    int choice;
    std::string username, password, email;

    while (true) {
        std::cout << "1. Register\n2. Login\n3. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                std::cout << "Enter email: ";
                std::cin >> email;
                registerUser(con, username, password, email);
                break;
            case 2:
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;
                if (loginUser(con, username, password)) {
                    // Proceed to booking functionality
                }
                break;
            case 3:
                delete con;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
