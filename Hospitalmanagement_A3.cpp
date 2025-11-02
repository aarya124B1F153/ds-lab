#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    Patient* next;
};

Patient* head = NULL;

void addPatient(int id, string name) {
    Patient* newPatient = new Patient;
    newPatient->id = id;
    newPatient->name = name;
    newPatient->next = NULL;

    if (head == NULL) {
        head = newPatient;
    } else {
        Patient* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }
    cout << "Patient added.\n";
}

void removePatient() {
    if (head == NULL) {
        cout << "No patients to remove.\n";
        return;
    }
    Patient* temp = head;
    head = head->next;
    cout << "Removed patient: " << temp->name << endl;
    delete temp;
}

void moveUpPatient(int id) {
    if (head == NULL || head->next == NULL) {
        cout << "Not enough patients to move.\n";
        return;
    }

    Patient* prev = NULL;
    Patient* curr = head;

    while (curr != NULL && curr->id != id) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        cout << "Patient not found.\n";
        return;
    }

    if (prev == NULL) {
        cout << "Patient already at front.\n";
        return;
    }

    Patient* beforePrev = NULL;
    Patient* temp = head;
    while (temp != NULL && temp->next != prev) {
        temp = temp->next;
    }
    beforePrev = temp;

    prev->next = curr->next;
    curr->next = prev;

    if (beforePrev == NULL) {
        head = curr;
    } else {
        beforePrev->next = curr;
    }

    cout << "Patient moved up.\n";
}

void display() {
    if (head == NULL) {
        cout << "Queue is empty.\n";
        return;
    }
    Patient* temp = head;
    cout << "Patients in queue:\n";
    while (temp != NULL) {
        cout << temp->id << " - " << temp->name << endl;
        temp = temp->next;
    }
}

void searchPatient(int id) {
    Patient* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Found patient: " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient not found.\n";
}

int main() {
    int choice, id;
    string name;

    do {
        cout << "\n1. Add Patient\n2. Remove Patient\n3. Move Patient Up\n4. Display Queue\n5. Search Patient\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter id: ";
                cin >> id;
                cout << "Enter name: ";
                cin >> name;
                addPatient(id, name);
                break;
            case 2:
                removePatient();
                break;
            case 3:
                cout << "Enter patient id to move up: ";
                cin >> id;
                moveUpPatient(id);
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Enter id to search: ";
                cin >> id;
                searchPatient(id);
                break;
            case 6:
                cout << "Bye!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}


