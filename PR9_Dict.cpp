#include <bits/stdc++.h>
using namespace std;

class dictionary;
class node {
    string word, meaning;
    node* left;
    node* right;
public:
    friend class dictionary;
    node() {
        left = NULL;
        right = NULL;
    }
    node(string word, string meaning) {
        this->word = word;
        this->meaning = meaning;
        left = NULL;
        right = NULL;
    }
};

class dictionary {
    node* root;

public:
    dictionary() {
        root = NULL;
    }
    void insertWord();
    bool insert(string word, string meaning);
    void inorder_rec(node* rnode);
    void postorder_rec(node* rnode);
    void inorder() {
        if (root == NULL) {
            cout << "\nDictionary is empty.\n";
            return;
        }
        inorder_rec(root);
    }
    void postorder() {
        if (root == NULL) {
            cout << "\nDictionary is empty.\n";
            return;
        }
        postorder_rec(root);
    }
    int search(string key);
};

void dictionary::insertWord() {
    string wordI, meaningI;
    cout << "\nEnter word: ";
    cin >> ws; // consume any leading whitespace
    getline(cin, wordI);
    cout << "Enter meaning: ";
    getline(cin, meaningI);
    if (insert(wordI, meaningI)) {
        cout << "Word inserted successfully.\n";
    }
}

bool dictionary::insert(string word, string meaning) {
    node* p = new node(word, meaning);
    if (root == NULL) {
        root = p;
        return true;
    }
    node* cur = root;
    node* par = NULL;
    while (cur != NULL) {
        par = cur;
        if (word == cur->word) {
            cout << "\nWord is already in the dictionary.\n";
            delete p;
            return false;
        }
        else if (word > cur->word) {
            cur = cur->right;
        }
        else {
            cur = cur->left;
        }
    }
    if (word > par->word)
        par->right = p;
    else
        par->left = p;
    return true;
}

void dictionary::inorder_rec(node* rnode) {
    if (rnode) {
        inorder_rec(rnode->left);
        cout << " " << rnode->word << " : " << rnode->meaning << endl;
        inorder_rec(rnode->right);
    }
}

void dictionary::postorder_rec(node* rnode) {
    if (rnode) {
        postorder_rec(rnode->right);
        cout << " " << rnode->word << " : " << rnode->meaning << endl;
        postorder_rec(rnode->left);
    }
}

int dictionary::search(string key) {
    node* tmp = root;
    int count = 0;
    if (tmp == NULL)
        return -1;
    while (tmp != NULL) {
        count++;
        if (tmp->word == key) {
            cout << "\nWord : " << key << "\nMeaning : " << tmp->meaning << "\n";
            return count;
        }
        else if (tmp->word > key) {
            tmp = tmp->left;
        }
        else {
            tmp = tmp->right;
        }
    }
    return -1;
}

int main() {
    dictionary dict;
    int choice;
    string word;

    do {
        cout << "\n==== Dictionary Menu ====\n";
        cout << "1. Insert a word\n";
        cout << "2. Display dictionary in ascending order\n";
        cout << "3. Display dictionary in descending order\n";
        cout << "4. Search for a word\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            dict.insertWord();
            break;
        case 2:
            cout << "\nDictionary in ascending order:\n";
            dict.inorder();
            break;
        case 3:
            cout << "\nDictionary in descending order:\n";
            dict.postorder();
            break;
        case 4:
            cout << "\nEnter word to search: ";
            cin >> ws;
            getline(cin, word);
            int comparisons;
            comparisons = dict.search(word);
            if (comparisons == -1)
                cout << "\nWord not found!\n";
            else
                cout << "\nFound in " << comparisons << " comparisons.\n";
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
