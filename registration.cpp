#include <iostream>
#include <cppconn/prepared_statement.h>

void registerUser(sql::Connection* con, const std::string& username, const std::string& password, const std::string& email) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Users(username, password, email) VALUES (?, ?, ?)");
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        pstmt->setString(3, email);
        pstmt->execute();
        std::cout << "User registered successfully." << std::endl;
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
