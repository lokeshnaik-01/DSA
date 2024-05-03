#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Movie {
private:
    string title;
    int availableSeats;
    double ticketPrice;
    vector<vector<char>> seatMap; // 2D vector representing seat map (initials of users or '-' if available)

public:
    Movie(const string& title, int totalSeats, double price)
        : title(title), availableSeats(totalSeats), ticketPrice(price) {
        // Initialize seat map for the movie
        seatMap = vector<vector<char>>(10, vector<char>(15, '-')); // 10 rows, 15 seats per row
    }

    const string& getTitle() const { return title; }
    int getAvailableSeats() const { return availableSeats; }
    double getTicketPrice() const { return ticketPrice; }

    bool bookSeats(int numSeats, int row, int startColumn, char userInitial) {
        if (availableSeats >= numSeats && validateSeatSelection(row, startColumn, numSeats)) {
            // Book the selected seats
            for (int i = startColumn - 1; i < startColumn - 1 + numSeats; ++i) {
                seatMap[row - 1][i] = userInitial; // Mark seat with user's initial
            }
            availableSeats -= numSeats; // Update available seats
            return true; // Booking successful
        }
        return false; // Booking failed
    }

    double calculateCost(int numSeats) const {
        return numSeats * ticketPrice;
    }

    void displaySeatMap() const {
        cout << "Seat Map for " << getTitle() << ":" << endl;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 15; ++j) {
                cout << seatMap[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    bool validateSeatSelection(int row, int startColumn, int numSeats) const {
        if (row < 1 || row > 10 || startColumn < 1 || startColumn + numSeats - 1 > 15) {
            return false; // Invalid seat selection
        }
        // Check if all selected seats are available
        for (int i = startColumn - 1; i < startColumn - 1 + numSeats; ++i) {
            if (seatMap[row - 1][i] != '-') {
                return false; // Seat is already booked
            }
        }
        return true; // All selected seats are available
    }
};

int main() {
    Movie inception("Inception", 150, 12.5);

    // Display initial seat map for Inception
    inception.displaySeatMap();

    int numUsers;
    cout << "Enter the number of users: ";
    cin >> numUsers;

    for (int userIndex = 1; userIndex <= numUsers; ++userIndex) {
        cout << "User " << userIndex << " - Enter the number of tickets you want to book: ";
        int numTickets;
        cin >> numTickets;

        cout << "User " << userIndex << " - Enter the row and starting column for seat selection (e.g., 5 1): ";
        int selectedRow, selectedColumn;
        cin >> selectedRow >> selectedColumn;

        char userInitial = 'A' + userIndex - 1; // Assign initial (A, B, C, ...)

        if (inception.bookSeats(numTickets, selectedRow, selectedColumn, userInitial)) {
            cout << "User " << userInitial << " booked " << numTickets << " seat(s) successfully!" << endl;
            double totalPrice = inception.calculateCost(numTickets);
            cout << "Total cost for User " << userInitial << ": $" << totalPrice << endl;
            inception.displaySeatMap(); // Display updated seat map after booking
        } else {
            cout << "Seat booking failed for User " << userInitial << ". Please try again." << endl;
        }
    }

    return 0;
}
