#include <iostream>
using namespace std;

struct Request {
    int id;
    char name[50];
    char service[50];
};

int main() {
    Request q[50];
    int front = 0, rear = 2, choice;

    // initial requests provided
    q[0] = {101, "John_Doe", "Technical_Support"};
    q[1] = {102, "Jane_Smith", "Billing_Inquiry"};
    q[2] = {103, "David_Brown", "Product_Information"};

    do {
        cout << "\n1. Add new request";
        cout << "\n2. Process next request";
        cout << "\n3. Display pending requests";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rear++;
                cout << "Enter request id: ";
                cin >> q[rear].id;
                cout << "Enter customer name: ";
                cin >> q[rear].name;
                cout << "Enter service type: ";
                cin >> q[rear].service;
                cout << "Request added.\n";
                break;

            case 2:
                if (front > rear) {
                    cout << "No requests to process.\n";
                } else {
                    cout << "Processing Request ID: " << q[front].id << "\n";
                    cout << "Customer: " << q[front].name << "\n";
                    cout << "Service: " << q[front].service << "\n";
                    front++;
                }
                break;

            case 3:
                if (front > rear) {
                    cout << "No pending requests.\n";
                } else {
                    cout << "Pending Requests:\n";
                    for (int i = front; i <= rear; i++) {
                        cout << q[i].id << " " << q[i].name << " " << q[i].service << "\n";
                    }
                }
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}

