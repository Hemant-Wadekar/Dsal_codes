#include <iostream>
#include <cstring> 
using namespace std;

struct Node {
    char title[50];
    Node* next;
    Node* sub;
};

Node* createNode(const char* title) {
    Node* newNode = new Node;
    strcpy(newNode->title, title);
    newNode->next = NULL;
    newNode->sub = NULL;
    return newNode;
}

void insert(Node*& head, const char* title) {
    Node* newNode = createNode(title);
    if (head == NULL)
        head = newNode;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}
void display(Node* head, int level = 0) {
    if (!head) return;
    for (int i = 0; i < level; i++) cout << "  ";
    cout << "- " << head->title << "\n";
    display(head->sub, level + 1);
    display(head->next, level);
}

int main() {
    Node* book = NULL;
    int choice;
    char title[50];

    do {
        cout << "\n********* PRACTICAL NO-03(B-5) *********\n \n********* MENU *********\n1. Insert\n2. Display\n3. Exit\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            if (book == NULL) {
                cout << "Enter Book Title: ";
                cin.getline(title, 50);
                book = createNode(title);
            }

            cout << "Enter Chapter Title: ";
            cin.getline(title, 50);
            insert(book->sub, title);

            cout << "Enter Section Title: ";
            cin.getline(title, 50);
            insert(book->sub->sub, title);

            cout << "Enter Subsection Title: ";
            cin.getline(title, 50);
            insert(book->sub->sub->sub, title);

            cout << "Inserted Successfully!\n";
        }
        else if (choice == 2) {
            if (book == NULL) {
                cout << "No book structure available. Insert first.\n";
            } else {
                cout << "\nBook Structure:\n";
                display(book);
            }
        }
    } while (choice != 3);
    cout << "Exiting...\n";
    return 0;
}
