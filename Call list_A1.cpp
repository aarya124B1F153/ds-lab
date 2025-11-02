#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
};

int main() {
    int n;
    cout << "Enter number of contacts: ";
    cin >> n;

    Contact contacts[50];  
    for (int i = 0; i < n; i++) {
        cout << "\nEnter name of contact " << i + 1 << ": ";
        cin >> contacts[i].name;
        cout << "Enter phone number of " << contacts[i].name << ": ";
        cin >> contacts[i].phone;
    }

    string searchName;
    cout << "\nEnter the name to search: ";
    cin >> searchName;

    for (int i = 0; i < n; i++) {
        if (contacts[i].name == searchName) {
            cout << "\nContact found:\n";
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone: " << contacts[i].phone << endl;
            return 0;  // exit the program after printing
        }
    }

    cout << "\nContact not found.\n";
    return 0;
}
