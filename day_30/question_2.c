//   Write a program to Create mini library system

#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LEN 100
#define AUTHOR_LEN 50

// Structure to store book information
struct Book {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int is_issued; // 0 = Available, 1 = Issued
};

// Global variables for simplicity in this mini-project
struct Book library[MAX_BOOKS];
int book_count = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void menu();

int main() {
    int choice;

    // Pre-populating with a couple of books so the library isn't empty at start
    library[book_count++] = (struct Book){101, "The C Programming Language", "Kernighan & Ritchie", 0};
    library[book_count++] = (struct Book){102, "To Kill a Mockingbird", "Harper Lee", 0};

    while (1) {
        menu();
        printf("Enter your choice (1-4): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("\nThank you for using the Mini Library System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n\n");
        }
    }
    return 0;
}

// Display the user menu
void menu() {
    printf("=== MINI LIBRARY SYSTEM ===\n");
    printf("1. Add a New Book\n");
    printf("2. Display All Books\n");
    printf("3. Search Book by ID\n");
    printf("4. Exit\n");
    printf("===========================\n");
}

// Function to add a book to the library
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("\nError: Library storage is full!\n\n");
        return;
    }

    struct Book new_book;
    
    printf("\nEnter Book ID (Integer): ");
    scanf("%d", &new_book.id);
    
    // Check if ID already exists
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with ID %d already exists!\n\n", new_book.id);
            return;
        }
    }

    // Clear input buffer before reading strings
    getchar(); 

    printf("Enter Book Title: ");
    fgets(new_book.title, TITLE_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0; // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(new_book.author, AUTHOR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0; // Remove trailing newline

    new_book.is_issued = 0; // New books are available by default

    // Save to array
    library[book_count] = new_book;
    book_count++;

    printf("Book added successfully!\n\n");
}

// Function to display all books
void displayBooks() {
    if (book_count == 0) {
        printf("\nThe library is currently empty.\n\n");
        return;
    }

    printf("\n%-10s %-35s %-25s %-10s\n", "ID", "Title", "Author", "Status");
    printf("-----------------------------------------------------------------------------\n");
    
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-35s %-25s %-10s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
    printf("\n");
}

// Function to search for a book by its ID
void searchBook() {
    if (book_count == 0) {
        printf("\nThe library is empty. Nothing to search.\n\n");
        return;
    }

    int search_id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\nBook Found!\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Status: %s\n\n", library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }

    printf("Book with ID %d not found.\n\n", search_id);
}