/*How do Dynamic arrays work*/

#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

    // Grow the array by doubling its capacity
    void growArray() {
        int* temp = new int[capacity * 2];
        capacity *= 2;

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    // Shrink the array to fit its size
    void shrinkArray() {
        capacity = size;
        int* temp = new int[capacity];

        for (int i = 0; i < size; i++) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

public:
    // Default constructor with initial capacity of 1
    DynamicArray(){
        capacity = 1;
        size = 0;
        arr = new int[capacity];
    }

    // Constructor with user-defined capacity
    DynamicArray(int capacity){
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
    }

    // Destructor to free allocated memory
    ~DynamicArray() {
        delete[] arr;
    }

    // Add an element to the end of the array
    void push_back(int value) {
        if (size == capacity) {
            growArray();
        }
        arr[size++] = value;
    }

    // Remove the last element of the array
    void pop() {
        if (size > 0) {
            size--;
            if (size <= capacity / 2) {
                shrinkArray();
            }
        }
    }

    // Print all elements in the array
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Search for an element in the array and return its index
    int search(int key) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                return i;
            }
        }
        return -1; // Element not found
    }

    // Check if the array is empty
    bool isEmpty() {
        return size == 0;
    }

    // Insert an element at the specified index
    void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (size == capacity) {
            growArray();
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    // Delete an element at the specified index
    void deleteAt(int index) {
        if (index < 0 || index >= size) {
            cout << "Index out of bounds" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        if (size <= capacity / 2) {
            shrinkArray();
        }
    }
};

int main() {
    DynamicArray v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    cout << "The elements are: ";
    v.print();

    v.pop();
    v.pop();

    cout << "After popping the elements are: ";
    v.print();

    v.insertAt(3, 50);
    v.insertAt(1, 25);

    cout << "After inserting the elements are: ";
    v.print();

    v.deleteAt(4);
    v.deleteAt(2);

    cout << "After deleting the elements are: ";
    v.print();

    return 0;
}
