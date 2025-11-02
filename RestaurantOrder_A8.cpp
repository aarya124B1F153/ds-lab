#include <iostream>
using namespace std;

struct Order {
    int id;
    char items[50];
    char customer[50];
};

int main() {
    Order orders[50];
    int front = 0, rear = 2;  // front = first order, rear = last order
    int size = 3;              // initial 3 orders
    int capacity = 50;
    int choice;

    // Initial orders provided
    orders[0] = {101, "Burger_Fries_Drink", "Rahul_Sharma"};
    orders[1] = {102, "Chicken_Salad_Drink", "Priya_Patel"};
    orders[2] = {103, "Pizza_Wings_Drink", "Aarav_Gupta"};

    do {
        cout << "\n1. Add new order\n";
        cout << "2. Process next order\n";
        cout << "3. Display pending orders\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (size == capacity) {
                cout << "Queue is full.\n";
            } else {
                rear = (rear + 1) % capacity;
                cout << "Enter order ID: ";
                cin >> orders[rear].id;
                cout << "Enter items (use _ instead of spaces): ";
                cin >> orders[rear].items;
                cout << "Enter customer name (use _ instead of spaces): ";
                cin >> orders[rear].customer;
                size++;
                cout << "Order added.\n";
            }
        } else if (choice == 2) {
            if (size == 0) {
                cout << "No orders to process.\n";
            } else {
                cout << "\nProcessing Order ID: " << orders[front].id << "\n";
                cout << "Customer: " << orders[front].customer << "\n";
                cout << "Items: " << orders[front].items << "\n";
                front = (front + 1) % capacity;
                size--;
            }
        } else if (choice == 3) {
            if (size == 0) {
                cout << "No pending orders.\n";
            } else {
                cout << "\nPending Orders:\n";
                int count = size;
                int i = front;
                while (count--) {
                    cout << orders[i].id << " " << orders[i].items << " " << orders[i].customer << "\n";
                    i = (i + 1) % capacity;
                }
            }
        } else if (choice == 4) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}

