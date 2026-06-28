//    Write a program to Create ticket booking system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10
#define TICKET_PRICE 12.0 // Price per ticket in dollars

// Function declarations
void displaySeatingChart(int seats[ROWS][COLS]);
void bookTickets(int seats[ROWS][COLS]);
void viewBookingSummary(int seats[ROWS][COLS]);

int main() {
    // 0 represents Available, 1 represents Booked
    int seats[ROWS][COLS] = {0}; 
    int choice;

    // Pre-seed a few booked seats just to make it look active initially
    seats[0][2] = 1;
    seats[1][5] = 1;
    seats[3][8] = 1;

    while (1) {
        printf("\n===================================\n");
        printf("     MOVIE TICKET BOOKING SYSTEM   \n");
        printf("===================================\n");
        printf("1. View Seating Chart\n");
        printf("2. Book Tickets\n");
        printf("3. View Revenue & Booking Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                displaySeatingChart(seats);
                break;
            case 2:
                bookTickets(seats);
                break;
            case 3:
                viewBookingSummary(seats);
                break;
            case 4:
                printf("\nThank you for using the Ticket Booking System. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please select an option between 1 and 4.\n");
        }
    }

    return 0;
}

// Displays the current state of the theater seats
void displaySeatingChart(int seats[ROWS][COLS]) {
    printf("\n----------- SEATING CHART -----------\n");
    printf("   ");
    for (int j = 0; j < COLS; j++) {
        printf(" %d ", j + 1); // Column numbers
    }
    printf("\n");

    for (int i = 0; i < ROWS; i++) {
        printf("Row %c: ", 'A' + i); // Row letters (A, B, C...)
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 0) {
                printf("[O]"); // Available
            } else {
                printf("[X]"); // Booked
            }
        }
        printf("\n");
    }
    printf("-------------------------------------\n");
    printf("Legend: [O] = Available   [X] = Booked\n");
    printf("       ============ SCREEN ============\n");
}

// Handles the booking process
void bookTickets(int seats[ROWS][COLS]) {
    int numTickets;
    char rowLetter;
    int row, col;
    float totalCost = 0;

    displaySeatingChart(seats);

    printf("\nHow many tickets would you like to book? ");
    scanf("%d", &numTickets);

    if (numTickets <= 0 || numTickets > (ROWS * COLS)) {
        printf("Invalid number of tickets!\n");
        return;
    }

    for (int i = 0; i < numTickets; i++) {
        printf("\nBooking ticket %d of %d:\n", i + 1, numTickets);
        printf("Enter Row Letter (A-%c): ", 'A' + ROWS - 1);
        scanf(" %c", &rowLetter);
        
        // Convert lowercase to uppercase if needed
        if (rowLetter >= 'a' && rowLetter <= 'z') {
            rowLetter = rowLetter - 32;
        }

        printf("Enter Seat Number (1-%d): ", COLS);
        scanf("%d", &col);

        row = rowLetter - 'A'; // Convert letter to 0-indexed integer
        col = col - 1;         // Convert 1-indexed input to 0-indexed integer

        // Validate seat selection
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
            printf("Error: That seat does not exist! Please retry booking sequence.\n");
            i--; // Decrement index to make user retry this specific ticket
            continue;
        }

        // Check availability
        if (seats[row][col] == 1) {
            printf("Error: Seat %c%d is already booked! Choose another one.\n", rowLetter, col + 1);
            i--; 
            continue;
        }

        // Successfully lock in seat
        seats[row][col] = 1;
        totalCost += TICKET_PRICE;
        printf("Seat %c%d successfully selected!\n", rowLetter, col + 1);
    }

    // Print Receipt
    printf("\n===================================\n");
    printf("          BOOKING RECEIPT          \n");
    printf("===================================\n");
    printf(" Tickets Booked: %d\n", numTickets);
    printf(" Price per Ticket: $%.2f\n", TICKET_PRICE);
    printf(" Total Amount Due: $%.2f\n", totalCost);
    printf("===================================\n");
    printf("Enjoy your show!\n");
}

// Calculates and prints total seats filled and money made
void viewBookingSummary(int seats[ROWS][COLS]) {
    int bookedCount = 0;
    int totalSeats = ROWS * COLS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j] == 1) {
                bookedCount++;
            }
        }
    }

    printf("\n========= THEATER SUMMARY =========\n");
    printf("Total Capacity : %d seats\n", totalSeats);
    printf("Seats Booked   : %d\n", bookedCount);
    printf("Seats Available: %d\n", totalSeats - bookedCount);
    printf("Total Revenue  : $%.2f\n", bookedCount * TICKET_PRICE);
    printf("===================================\n");
}