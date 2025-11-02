#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        cout << "Duplicate value " << value << " not inserted.\n";
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == NULL)
        return root;
    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

bool search(Node* root, int value) {
    if (root == NULL)
        return false;
    if (root->data == value)
        return true;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int depth(Node* root) {
    if (root == NULL)
        return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return max(left, right) + 1;
}

void mirror(Node* root) {
    if (root == NULL)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

Node* copyTree(Node* root) {
    if (root == NULL)
        return NULL;
    Node* newNode = createNode(root->data);
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}

void showParentChild(Node* root) {
    if (root == NULL)
        return;
    if (root->left != NULL || root->right != NULL) {
        cout << "Parent " << root->data << " -> ";
        if (root->left) cout << "Left: " << root->left->data << " ";
        if (root->right) cout << "Right: " << root->right->data;
        cout << endl;
    }
    showParentChild(root->left);
    showParentChild(root->right);
}

void showLeaves(Node* root) {
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";
    showLeaves(root->left);
    showLeaves(root->right);
}

void levelWise(Node* root) {
    if (root == NULL)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            Node* temp = q.front(); q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display (Inorder/Preorder/Postorder)\n";
        cout << "5. Depth of tree\n6. Mirror image\n7. Copy tree\n";
        cout << "8. Show parent and child nodes\n9. Show leaf nodes\n10. Display level-wise\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << value << " found in tree.\n";
            else
                cout << value << " not found.\n";
            break;
        case 4:
            cout << "Inorder: ";
            inorder(root);
            cout << "\nPreorder: ";
            preorder(root);
            cout << "\nPostorder: ";
            postorder(root);
            cout << endl;
            break;
        case 5:
            cout << "Depth of tree: " << depth(root) << endl;
            break;
        case 6:
            mirror(root);
            cout << "Tree mirrored.\n";
            break;
        case 7: {
            Node* copy = copyTree(root);
            cout << "Copied tree (Inorder): ";
            inorder(copy);
            cout << endl;
            break;
        }
        case 8:
            showParentChild(root);
            break;
        case 9:
            cout << "Leaf nodes: ";
            showLeaves(root);
            cout << endl;
            break;
        case 10:
            cout << "Level-wise display:\n";
            levelWise(root);
            break;
        }
    } while (choice != 0);

    return 0;
}


