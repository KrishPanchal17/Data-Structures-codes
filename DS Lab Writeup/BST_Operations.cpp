#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Create a new Binary Search Tree
Node* insert(Node* root, int data)
{
    if (root == nullptr)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}
void inorderTraversal(Node* node)
{
    if (node == nullptr)
        return;

    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}
void preorderTraversal(Node* node)
{
    if (node == nullptr)
        return;

    cout << node->data << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
void postorderTraversal(Node* node)
{
    if (node == nullptr)
        return;

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << " ";
}
bool search(Node* node, int data)
{
    if (node == nullptr)
        return false;

    if (data == node->data)
        return true;

    if (data < node->data)
        return search(node->left, data);
    else
        return search(node->right, data);
}
Node* minValueNode(Node* node)
{
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}
Node* deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == nullptr)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

int main()
{
    Node* root = nullptr;
    int choice, data;

    while (true)
    {
        cout << "\n1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Traverse Tree in Inorder\n";
        cout << "5. Traverse Tree in Preorder\n";
        cout << "6. Traverse Tree in Postorder\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> data;
            root = insert(root, data);
            break;
        case 2:
            cout << "Enter the value to be deleted: ";
            cin >> data;
            root = deleteNode(root, data);
            break;
        case 3:
            cout << "Enter the value to be searched: ";
            cin >> data;
            if (search(root, data))
                cout << "Value found\n";
            else
                cout << "Value not found\n";
            break;
        case 4:
            cout << "Inorder Traversal: ";
            inorderTraversal(root);
            cout << "\n";
            break;
        case 5:
            cout << "Preorder Traversal: ";
            preorderTraversal(root);
            cout << "\n";
            break;
        case 6:
            cout << "Postorder Traversal: ";
            postorderTraversal(root);
            cout << "\n";
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice, try again\n";
        }
    }

    return 0;
}
