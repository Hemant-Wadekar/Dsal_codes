#include <iostream> 
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node *insert(Node *root, int data) {
  if (root == nullptr) return new Node(data);
  if (data < root->data) root->left = insert(root->left, data);
  else if (data > root->data) root->right = insert(root->right, data);
  else cout << "Duplicate value " << data << " not inserted." << endl;
  return root;
}

void display(Node *root) {
  if (root != nullptr) {
    display(root->left);
    cout << root->data << "->";
    display(root->right);
  }
}

int longestPath(Node *root) {
  if (root == nullptr) return 0;
  return 1 + max(longestPath(root->left), longestPath(root->right));
}

int findMinValue(Node *root) {
  if (root == nullptr) {
    cout << "Tree is empty." << endl;
    return -1; 
  }
  Node *current = root;
  while (current->left != nullptr) current = current->left;
  return current->data;
}

int findMaxValue(Node *root) {
  if (root == nullptr) {
    cout << "Tree is empty." << endl;
    return -1;
  }
  Node *current = root;
  while (current->right != nullptr) current = current->right;
  return current->data;
}

bool search(Node *root, int key) {
  if (root == nullptr) return false;
  if (key == root->data) return true;
  else if (key < root->data) return search(root->left, key);
  else return search(root->right, key);
}

Node *swapLeftRight(Node *root) {
  if (root == nullptr) return nullptr;
  Node *temp = root->left;
  root->left = root->right;
  root->right = temp;
  swapLeftRight(root->left);
  swapLeftRight(root->right);
  return root;
}

void deleteTree(Node *root) {
  if (root != nullptr) {
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
  }
}

int main() {
  Node *root = nullptr;
  int choice, value, numNodes;
  cout << "\n***********BINARY SEARCH TREE OPERATIONS***********************\n";
  do {
    cout << "\n1: Insert Nodes\n2: Display tree\n3: Number of nodes in longest path\n4: Minimum data value\n5: Search a value\n6: Swap left and right pointers\n7: Find maximum value\n8: Exit\nEnter your choice: ";
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "\nHow many nodes? ";
        cin >> numNodes;
        for (int i = 0; i < numNodes; ++i) {
          cout << "Enter value " << i + 1 << ": ";
          cin >> value;
          root = insert(root, value);
        }
        break;
      case 2:
        cout << "BST (Inorder): ";
        display(root);
        cout << endl;
        break;
      case 3:
        cout << "Longest path nodes: " << longestPath(root) << endl;
        break;
      case 4:
        value = findMinValue(root);
        if (value != -1) cout << "Minimum value: " << value << endl;
        break;
      case 5:
        cout << "Enter search value: ";
        cin >> value;
        if (search(root, value)) cout << value << " found." << endl;
        else cout << value << " not found." << endl;
        break;
      case 6:
        root = swapLeftRight(root);
        cout << "Pointers swapped." << endl;
        break;
      case 7:
        value = findMaxValue(root);
        if (value != -1) cout << "Maximum value: " << value << endl;
        break;
      case 8:
        cout << "Exiting.\n";
        break;
      default:
        cout << "Invalid choice.\n";
    }
  } while (choice != 8);
  deleteTree(root);
  root = nullptr;
  return 0;
}
