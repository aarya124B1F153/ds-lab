#include <iostream>
#include <string>
using namespace std;

struct Contact {
    int id;
    string name;
    string phone;
    string email;
    Contact* left;
    Contact* right;
    int height;
};

int getHeight(Contact* n) {
    if (n == NULL)
        return 0;
    return n->height;
}

int getBalance(Contact* n) {
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

Contact* createContact(int id, string name, string phone, string email) {
    Contact* c = new Contact();
    c->id = id;
    c->name = name;
    c->phone = phone;
    c->email = email;
    c->left = c->right = NULL;
    c->height = 1;
    return c;
}

Contact* rightRotate(Contact* y) {
    Contact* x = y->left;
    Contact* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

Contact* leftRotate(Contact* x) {
    Contact* y = x->right;
    Contact* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

Contact* insert(Contact* node, int id, string name, string phone, string email) {
    if (node == NULL)
        return createContact(id, name, phone, email);

    if (id < node->id)
        node->left = insert(node->left, id, name, phone, email);
    else if (id > node->id)
        node->right = insert(node->right, id, name, phone, email);
    else
        return node; // duplicate ID not allowed

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    if (balance > 1 && id < node->left->id)
        return rightRotate(node);
    if (balance < -1 && id > node->right->id)
        return leftRotate(node);
    if (balance > 1 && id > node->left->id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && id < node->right->id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

Contact* searchByID(Contact* root, int id) {
    if (root == NULL || root->id == id)
        return root;
    if (id < root->id)
        return searchByID(root->left, id);
    else
        return searchByID(root->right, id);
}

void updateContact(Contact* root, int id, string newPhone, string newEmail) {
    Contact* c = searchByID(root, id);
    if (c != NULL) {
        c->phone = newPhone;
        c->email = newEmail;
        cout << "Contact updated for ID " << id << endl;
    } else {
        cout << "Contact not found for update." << endl;
    }
}

void searchByName(Contact* root, string name) {
    if (root == NULL)
        return;
    if (root->name == name)
        cout << "Found: " << root->name << " (" << root->phone << ", " << root->email << ")\n";
    searchByName(root->left, name);
    searchByName(root->right, name);
}

void display(Contact* root) {
    if (root != NULL) {
        display(root->left);
        cout << "ID: " << root->id << ", Name: " << root->name
             << ", Phone: " << root->phone << ", Email: " << root->email << endl;
        display(root->right);
    }
}

int main() {
    Contact* root = NULL;

    root = insert(root, 101, "Rahul Sharma", "9876543210", "rahul@example.com");
    root = insert(root, 102, "Priya Patel", "1234567890", "priya@example.com");
    root = insert(root, 103, "Aarav Gupta", "8765432109", "aarav@example.com");

    cout << "--- All Contacts (Inorder Traversal) ---\n";
    display(root);

    cout << "\n--- Searching Contact by Name: Priya Patel ---\n";
    searchByName(root, "Priya Patel");

    cout << "\n--- Updating Rahul Sharma's Contact ---\n";
    updateContact(root, 101, "9998887777", "rahul_new@example.com");

    cout << "\n--- Display After Update ---\n";
    display(root);

    return 0;
}

