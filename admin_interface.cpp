void addEvent(sql::Connection* con, const std::string& event_name, const std::string& event_date, const std::string& event_time, const std::string& venue, int available_seats) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO Events(event_name, event_date, event_time, venue, available_seats) VALUES (?, ?, ?, ?, ?)");
        pstmt->setString(1, event_name);
        pstmt->setString(2, event_date);
        pstmt->setString(3, event_time);
        pstmt->setString(4, venue);
        pstmt->setInt(5, available_seats);
        pstmt->execute();
        std::cout << "Event added successfully." << std::endl;
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void deleteEvent(sql::Connection* con, int event_id) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("DELETE FROM Events WHERE event_id = ?");
        pstmt->setInt(1, event_id);
        pstmt->execute();
        std::cout << "Event deleted successfully." << std::endl;
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void updateEvent(sql::Connection* con, int event_id, const std::string& event_name, const std::string& event_date, const std::string& event_time, const std::string& venue, int available_seats) {
    try {
        sql::PreparedStatement* pstmt = con->prepareStatement("UPDATE Events SET event_name = ?, event_date = ?, event_time = ?, venue = ?, available_seats = ? WHERE event_id = ?");
        pstmt->setString(1, event_name);
        pstmt->setString(2, event_date);
        pstmt->setString(3, event_time);
        pstmt->setString(4, venue);
        pstmt->setInt(5, available_seats);
        pstmt->setInt(6, event_id);
        pstmt->execute();
        std::cout << "Event updated successfully." << std::endl;
        delete pstmt;
    } catch (sql::SQLException &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

int main() {
    sql::Connection* con = connectDatabase();
    int choice, event_id, available_seats;
    std::string event_name, event_date, event_time, venue;

    while (true) {
        std::cout << "1. Add Event\n2. Delete Event\n3. Update Event\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter event name: ";
                std::cin >> event_name;
                std::cout << "Enter event date (YYYY-MM-DD): ";
                std::cin >> event_date;
                std::cout << "Enter event time (HH:MM:SS): ";
                std::cin >> event_time;
                std::cout << "Enter venue: ";
                std::cin >> venue;
                std::cout << "Enter available seats: ";
                std::cin >> available_seats;
                addEvent(con, event_name, event_date, event_time, venue, available_seats);
                break;
            case 2:
                std::cout << "Enter event ID to delete: ";
                std::cin >> event_id;
                deleteEvent(con, event_id);
                break;
            case 3:
                std::cout << "Enter event ID to update: ";
                std::cin >> event_id;
                std::cout << "Enter new event name: ";
                std::cin >> event_name;
                std::cout << "Enter new event date (YYYY-MM-DD): ";
                std::cin >> event_date;
                std::cout << "Enter new event time (HH:MM:SS): ";
                std::cin >> event_time;
                std::cout << "Enter new venue: ";
                std::cin >> venue;
                std::cout << "Enter new available seats: ";
                std::cin >> available_seats;
                updateEvent(con, event_id, event_name, event_date, event_time, venue, available_seats);
                break;
            case 4:
                delete con;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}
