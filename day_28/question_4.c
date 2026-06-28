//      Write a program to Create contact management system

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

// Define the contact structure
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

// Function declarations
void load_contacts();
void save_contacts();
void add_contact();
void list_contacts();
void search_contact();
void delete_contact();
void clear_buffer();

int main() {
    int choice;

    // Load existing contacts from file at startup
    load_contacts();

    while (1) {
        printf("\n=== Contact Management System ===\n");
        printf("1. Add Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_buffer();
            continue;
        }
        clear_buffer(); // Clean up newline character left by scanf

        switch (choice) {
            case 1: add_contact(); break;
            case 2: list_contacts(); break;
            case 3: search_contact(); break;
            case 4: delete_contact(); break;
            case 5:
                save_contacts();
                printf("Contacts saved. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}

// Helper function to clear input buffer (prevents fgets skipping)
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to remove trailing newline from fgets string
void remove_newline(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void load_contacts() {
    FILE *file = fopen("contacts.txt", "rb");
    if (file == NULL) {
        // File doesn't exist yet, which is fine for the first run
        return;
    }
    
    // Read contacts into the array
    contact_count = fread(contacts, sizeof(Contact), MAX_CONTACTS, file);
    fclose(file);
}

void save_contacts() {
    FILE *file = fopen("contacts.txt", "wb");
    if (file == NULL) {
        printf("Error saving contacts to file!\n");
        return;
    }
    
    fwrite(contacts, sizeof(Contact), contact_count, file);
    fclose(file);
}

void add_contact() {
    if (contact_count >= MAX_CONTACTS) {
        printf("Contact list full!\n");
        return;
    }

    Contact new_contact;

    printf("Enter Name: ");
    fgets(new_contact.name, sizeof(new_contact.name), stdin);
    remove_newline(new_contact.name);

    printf("Enter Phone: ");
    fgets(new_contact.phone, sizeof(new_contact.phone), stdin);
    remove_newline(new_contact.phone);

    printf("Enter Email: ");
    fgets(new_contact.email, sizeof(new_contact.email), stdin);
    remove_newline(new_contact.email);

    contacts[contact_count] = new_contact;
    contact_count++;
    
    // Save immediately after adding
    save_contacts();
    printf("Contact added successfully!\n");
}

void list_contacts() {
    if (contact_count == 0) {
        printf("No contacts found.\n");
        return;
    }

    printf("\n--- Contact List ---\n");
    for (int i = 0; i < contact_count; i++) {
        printf("%d. Name: %s | Phone: %s | Email: %s\n", 
               i + 1, contacts[i].name, contacts[i].phone, contacts[i].email);
    }
}

void search_contact() {
    if (contact_count == 0) {
        printf("No contacts to search.\n");
        return;
    }

    char search_name[50];
    printf("Enter name to search: ");
    fgets(search_name, sizeof(search_name), stdin);
    remove_newline(search_name);

    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        // Case-sensitive exact or partial match depending on implementation; 
        // using strstr allows partial matching (e.g., "John" matches "John Doe")
        if (strstr(contacts[i].name, search_name) != NULL) {
            printf("\nFound -> Name: %s | Phone: %s | Email: %s\n", 
                   contacts[i].name, contacts[i].phone, contacts[i].email);
            found = 1;
        }
    }

    if (!found) {
        printf("No contact found matching '%s'.\n", search_name);
    }
}

void delete_contact() {
    if (contact_count == 0) {
        printf("No contacts to delete.\n");
        return;
    }

    list_contacts();
    int index;
    printf("\nEnter the number of the contact you want to delete: ");
    if (scanf("%d", &index) != 1) {
        printf("Invalid input.\n");
        clear_buffer();
        return;
    }
    clear_buffer();

    if (index < 1 || index > contact_count) {
        printf("Invalid contact number.\n");
        return;
    }

    // Convert 1-based index to 0-based index
    int target = index - 1;

    // Shift elements left to fill the gap
    for (int i = target; i < contact_count - 1; i++) {
        contacts[i] = contacts[i + 1];
    }

    contact_count--;
    save_contacts();
    printf("Contact deleted successfully!\n");
}