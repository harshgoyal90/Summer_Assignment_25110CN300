//      Write a program to Create library management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_STR_LEN 50

// Structure to store book information
typedef struct {
    int id;
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    int is_issued; // 0 = Available, 1 = Issued
} Book;

// Global variables for simplicity
Book library[MAX_BOOKS];
int book_count = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Library Management System ---\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Search for a Book\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer(); // Clean newline left by scanf

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: 
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to safely clear standard input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Add a new book to the library
void addBook() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    Book new_book;
    printf("Enter Book ID (integer): ");
    if (scanf("%d", &new_book.id) != 1) {
        printf("Invalid ID. Failed to add book.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Check if ID already exists
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with ID %d already exists.\n", new_book.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    fgets(new_book.title, MAX_STR_LEN, stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Author Name: ");
    fgets(new_book.author, MAX_STR_LEN, stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0';

    new_book.is_issued = 0; // New books are available by default

    library[book_count] = new_book;
    book_count++;

    printf("Book \"%s\" added successfully!\n", new_book.title);
}

// 2. Display all books currently in the library
void displayBooks() {
    if (book_count == 0) {
        printf("No books available in the library.\n");
        return;
    }

    printf("\n%-10s %-25s %-25s %-10s\n", "ID", "Title", "Author", "Status");
    printf("-------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-25s %-25s %-10s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

// 3. Search for a book by title
void searchBook() {
    if (book_count == 0) {
        printf("Library is empty.\n");
        return;
    }

    char search_title[MAX_STR_LEN];
    printf("Enter the title of the book to search: ");
    fgets(search_title, MAX_STR_LEN, stdin);
    search_title[strcspn(search_title, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, search_title) == 0) { // Case-insensitive comparison
            if (!found) {
                printf("\nBook found:\n");
                printf("%-10s %-25s %-25s %-10s\n", "ID", "Title", "Author", "Status");
                printf("-------------------------------------------------------------------------\n");
            }
            printf("%-10d %-25s %-25s %-10s\n", 
                   library[i].id, library[i].title, library[i].author, 
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
        }
    }

    if (!found) {
        printf("No book found with the title \"%s\".\n", search_title);
    }
}

// 4. Issue a book (change status to Issued)
void issueBook() {
    int search_id;
    printf("Enter Book ID to issue: ");
    if (scanf("%d", &search_id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            if (library[i].is_issued == 1) {
                printf("Sorry, the book \"%s\" is already issued.\n", library[i].title);
            } else {
                library[i].is_issued = 1;
                printf("Book \"%s\" has been successfully issued.\n", library[i].title);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", search_id);
}

// 5. Return a book (change status to Available)
void returnBook() {
    int search_id;
    printf("Enter Book ID to return: ");
    if (scanf("%d", &search_id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            if (library[i].is_issued == 0) {
                printf("This book is already marked as available in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book \"%s\" has been successfully returned.\n", library[i].title);
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", search_id);
}