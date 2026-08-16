#include <iostream>
using namespace std;

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

int findMax(int arr[], int n) {
    int temp[n];
    copy(arr, arr+n, temp);
    
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify(temp, n, i);
    
    return temp[0];
}

int findMin(int arr[], int n) {
    int temp[n];
    copy(arr, arr+n, temp);
    
    for(int i = n/2 - 1; i >= 0; i--)
        minHeapify(temp, n, i);
    
    return temp[0];
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    int marks[n];
    for(int i=0; i<n; i++) {
        cout << "Marks of student " << i+1 << ": ";
        cin >> marks[i];
    }

    cout << "\nChoose operation:";
    cout << "\n1. Find Maximum Marks";
    cout << "\n2. Find Minimum Marks";
    
    int choice;
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "\nMaximum Marks: " << findMax(marks, n);
            break;
            
        case 2:
            cout << "\nMinimum Marks: " << findMin(marks, n);
            break;
            
        default:
            cout << "Invalid choice!";
    }

    return 0;
}
