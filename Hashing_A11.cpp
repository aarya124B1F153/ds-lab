#include <iostream>
#include <cstring>   // for strcpy()
using namespace std;

// Structure to store student details
struct Student {
    int id;
    char name[50];
    char branch[20];
    int year;
    Student* next;   // pointer to handle collisions (chaining)
};

// Hash Table class
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    Student* table[TABLE_SIZE];

    // Simple hash function
    int hashFunction(int id) {
        return id % TABLE_SIZE;
    }

public:
    // Constructor to initialize table
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    // Function to insert student record
    void insertStudent(int id, const char name[], const char branch[], int year) {
        int index = hashFunction(id);

        // Create new student node
        Student* newStudent = new Student;
        newStudent->id = id;
        strcpy(newStudent->name, name);
        strcpy(newStudent->branch, branch);
        newStudent->year = year;
        newStudent->next = NULL;

        // If no collision
        if (table[index] == NULL) {
            table[index] = newStudent;
        } 
        else {
            // Collision handling (chaining)
            Student* temp = table[index];
            while (temp->next != NULL) {
                if (temp->id == id) {
                    cout << "Student with this ID already exists! Updating record.\n";
                    strcpy(temp->name, name);
                    strcpy(temp->branch, branch);
                    temp->year = year;
                    delete newStudent;
                    return;
                }
                temp = temp->next;
            }
            temp->next = newStudent;
        }
        cout << "Student record added successfully!\n";
    }

    // Function to search student by ID
    void searchStudent(int id) {
        int index = hashFunction(id);
        Student* temp = table[index];
        while (temp != NULL) {
            if (temp->id == id) {
                cout << "\n--- Student Found ---\n";
                cout << "Student ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Branch: " << temp->branch << endl;
                cout << "Year: " << temp->year << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No student found with ID " << id << "!\n";
    }

    // Function to delete student record
    void deleteStudent(int id) {
        int index = hashFunction(id);
        Student* temp = table[index];
        Student* prev = NULL;

        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "No record found with ID " << id << "!\n";
            return;
        }

        if (prev == NULL)
            table[index] = temp->next;
        else
            prev->next = temp->next;

        delete temp;
        cout << "Student record deleted successfully!\n";
    }

    // Function to display all student records
    void displayAll() {
        cout << "\n--- All Student Records ---\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << i << ": ";
            Student* temp = table[i];
            if (temp == NULL) {
                cout << "Empty\n";
                continue;
            }
            while (temp != NULL) {
                cout << "[" << temp->id << ", " << temp->name << ", " 
                     << temp->branch << ", Year " << temp->year << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

// Main function
int main() {
    HashTable ht;
    int choice, id, year;
    char name[50], branch[20];

    do {
        cout << "\n========== Student Information System ==========\n";
        cout << "1. Add New Student\n";
        cout << "2. Search Student by ID\n";
        cout << "3. Delete Student by ID\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Branch: ";
            cin >> branch;
            cout << "Enter Year: ";
            cin >> year;
            ht.insertStudent(id, name, branch, year);
            break;

        case 2:
            cout << "Enter Student ID to search: ";
            cin >> id;
            ht.searchStudent(id);
            break;

        case 3:
            cout << "Enter Student ID to delete: ";
            cin >> id;
            ht.deleteStudent(id);
            break;

        case 4:
            ht.displayAll();
            break;

        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}



