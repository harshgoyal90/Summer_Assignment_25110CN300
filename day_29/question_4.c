//    Write a program to Create inventory management system

#include <stdio.h>
#include <string.h> // Fixed: Added for strcspn()

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];
int item_count = 0;

void add_item() {
    if (item_count >= MAX_ITEMS) {
        printf("Inventory full!\n");
        return;
    }

    struct Item new_item;

    printf("Enter Item ID: ");
    scanf("%d", &new_item.id);
    getchar(); // Clear newline character from buffer

    printf("Enter Item Name: ");
    fgets(new_item.name, sizeof(new_item.name), stdin);
    new_item.name[strcspn(new_item.name, "\n")] = 0; // Remove newline

    printf("Enter Quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter Price: ");
    scanf("%f", &new_item.price);
    getchar(); // Fixed: Clear newline after scanning float to prevent menu skips

    inventory[item_count] = new_item;
    item_count++;
    printf("Item added successfully!\n");
}

void list_items() {
    if (item_count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n--- Inventory List ---\n");
    for (int i = 0; i < item_count; i++) {
        printf("ID: %d | Name: %s | Quantity: %d | Price: $%.2f\n", 
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_item() {
    if (item_count == 0) {
        printf("No items to search.\n");
        return;
    }

    int search_id;
    printf("Enter Item ID to search: ");
    scanf("%d", &search_id);
    getchar(); // Fixed: Clear newline after scanning search ID

    for (int i = 0; i < item_count; i++) {
        if (inventory[i].id == search_id) {
            printf("Item found: ID: %d | Name: %s | Quantity: %d | Price: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item not found in the inventory.\n");
}

int main() {
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Add Item\n");
        printf("2. List Items\n");
        printf("3. Search Item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                list_items();
                break;
            case 3:
                search_item();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}