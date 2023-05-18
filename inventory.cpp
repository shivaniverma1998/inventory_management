#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    std::string name;
    int quantity;
    double price;
};

void addItem(std::vector<Item>& inventory) {
    Item newItem;
    std::cout << "Enter item name: ";
    std::cin >> newItem.name;
    std::cout << "Enter quantity: ";
    std::cin >> newItem.quantity;
    std::cout << "Enter price: ";
    std::cin >> newItem.price;

    inventory.push_back(newItem);
    std::cout << "Item added successfully!" << std::endl;
}

void displayInventory(const std::vector<Item>& inventory) {
    std::cout << "Inventory:" << std::endl;
    for (const Item& item : inventory) {
        std::cout << "Name: " << item.name << ", Quantity: " << item.quantity << ", Price: $" << item.price << std::endl;
    }
}

void sortInventoryByName(std::vector<Item>& inventory) {
    std::sort(inventory.begin(), inventory.end(), [](const Item& a, const Item& b) {
        return a.name < b.name;
    });
}

int main() {
    std::vector<Item> inventory;

    int choice;
    do {
        std::cout << "Inventory Management System" << std::endl;
        std::cout << "1. Add Item" << std::endl;
        std::cout << "2. Display Inventory" << std::endl;
        std::cout << "3. Sort Inventory by Name" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addItem(inventory);
                std::cout << std::endl;
                break;
            case 2:
                if (inventory.empty()) {
                    std::cout << "Inventory is empty." << std::endl;
                } else {
                    displayInventory(inventory);
                }
                std::cout << std::endl;
                break;
            case 3:
                if (inventory.empty()) {
                    std::cout << "Inventory is empty." << std::endl;
                } else {
                    sortInventoryByName(inventory);
                    std::cout << "Inventory sorted by name." << std::endl;
                }
                std::cout << std::endl;
                break;
            case 4:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                std::cout << std::endl;
        }
    } while (choice != 4);

    return 0;
}
