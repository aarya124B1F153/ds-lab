#include <iostream>
using namespace std;

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    Product products[50];
    Product* ptr;
    int n, choice;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter product id: ";
        cin >> products[i].id;
        cout << "Enter product name: ";
        cin >> products[i].name;
        cout << "Enter quantity: ";
        cin >> products[i].quantity;
        cout << "Enter price: ";
        cin >> products[i].price;
    }

    do {
        cout << "\n1. Display all products";
        cout << "\n2. Add new product";
        cout << "\n3. Update quantity";
        cout << "\n4. Total inventory value";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ptr = products;
                for (int i = 0; i < n; i++) {
                    cout << "\nProduct ID: " << ptr->id;
                    cout << "\nName: " << ptr->name;
                    cout << "\nQuantity: " << ptr->quantity;
                    cout << "\nPrice: " << ptr->price << "\n";
                    ptr++;
                }
                break;

            case 2:
                cout << "\nEnter product id: ";
                cin >> products[n].id;
                cout << "Enter product name: ";
                cin >> products[n].name;
                cout << "Enter quantity: ";
                cin >> products[n].quantity;
                cout << "Enter price: ";
                cin >> products[n].price;
                n++;
                break;

            case 3: {
                int id, newQty, found = 0;
                cout << "\nEnter product id to update: ";
                cin >> id;
                for (int i = 0; i < n; i++) {
                    if (products[i].id == id) {
                        cout << "Enter new quantity: ";
                        cin >> newQty;
                        products[i].quantity = newQty;
                        found = 1;
                        break;
                    }
                }
                if (found == 0)
                    cout << "Product not found.\n";
                break;
            }

            case 4: {
                float total = 0;
                ptr = products;
                for (int i = 0; i < n; i++) {
                    total = total + (ptr->quantity * ptr->price);
                    ptr++;
                }
                cout << "\nTotal Inventory Value = " << total << "\n";
                break;
            }

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}
