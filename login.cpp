bool loginUser(sql::Connection* con, const std::string& username, const std::string& password) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("SELECT * FROM Users WHERE username = ? AND password = ?");
        pstmt->setString(1, username);
        pstmt->setString(2, password);
        sql::ResultSet* res = pstmt->executeQuery();
        if (res->next()) {
            std::cout << "Login successful." << std::endl;
            delete res;
            delete pstmt;
            return true;
        } else {
            std::cout << "Invalid username or password." << std::endl;
        }
        delete res;
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return false;
}
