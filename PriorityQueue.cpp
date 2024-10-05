#include <iostream>
using namespace std;

class PriorityQueue {
private:
    int arr[100];   // Array to store elements
    int priority[100];  // Array to store priority of elements
    int size;

public:
    // Constructor
    PriorityQueue() {
        size = 0;
    }

    // Function to insert element with its priority
    void insert(int element, int pr) {
        arr[size] = element;
        priority[size] = pr;
        size++;
    }

    // Function to remove the element with the highest priority
    void remove() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        int highestPriorityIdx = 0;
        for (int i = 1; i < size; i++) {
            if (priority[i] > priority[highestPriorityIdx]) {
                highestPriorityIdx = i;
            }
        }

        cout << "Removed element: " << arr[highestPriorityIdx] << endl;

        // Shift elements after removal
        for (int i = highestPriorityIdx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
            priority[i] = priority[i + 1];
        }
        size--;
    }

    // Function to display the priority queue
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty" << endl;
            return;
        }

        cout << "Priority Queue elements: " << endl;
        for (int i = 0; i < size; i++) {
            cout << "Element: " << arr[i] << " | Priority: " << priority[i] << endl;
        }
    }
};

int main() {
    PriorityQueue pq;
    int choice, element, pr;

    while (true) {
        cout << "\n1. Insert element with priority\n2. Remove highest priority element\n3. Display priority queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> element;
                cout << "Enter priority: ";
                cin >> pr;
                pq.insert(element, pr);
                break;

            case 2:
                pq.remove();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                exit(0);

            default:
                cout << "Invalid choice, try again!" << endl;
        }
    }

    return 0;
}
