#include <iostream>

using namespace std;

// Forward declaration
void printArr(int arr[], int size);
void reverseArr(int arr[], int size);
void bubbleSort(int arr[], int size);
int linearSearch(int arr[], int size, int target);
void updateArrayElement(int arr[], int size, int position, int value);
void deleteArr(int arr[], int &size, int elementToDelete);

int main() {

    //1. Declare and initialize an Array
    int numbers[8] = {4, 3, 7, 8, 5, 20, 2, 1};
  
    int size = sizeof(numbers) / sizeof(numbers[0]);

    //2. Access and Modify Array elements
    cout << numbers[2] << endl;

    //3. Print all array
    printArr(numbers, size);
    cout << endl;

    // Update array
    updateArrayElement(numbers, size, 2, 6);
    printArr(numbers, size);
    cout << endl;

    //4. Print all array (method 2)   // This is foreach: used for iterating elements in array
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    //5. Reverse array
    reverseArr(numbers, size);
    cout << endl;

    //6. Sort array(bubble sort)
    bubbleSort(numbers, size);
    cout << "Numbers sorted: " << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    //7. Search element in array (linear search)
    int target = 8;
    int index = linearSearch(numbers, size, target);
    if (index != -1)
        cout << "Element " << target << " found at index " << index << " (Linear Search)." << endl;
    else
        cout << "Element not found." << endl;

    deleteArr(numbers, size, 8);

    printArr(numbers, size);

    return 0;
}


// *** Functins for array operation ***

// Print array
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// Reverse array
void reverseArr(int arr[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
}

// Sort array with bubble sort algorithm
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1])
            {
                // int temp = numbers[j];
                // numbers[j] = numbers[j + 1];
                // numbers[j + 1] = temp;
                swap(arr[j], arr[j+1]);   // shortcut function
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Update element inside array
void updateArrayElement(int arr[], int size, int position, int newValue) {
    if (position < 0 || position >= size)
    {
        cout << "Invalid position." << endl;
        return;
    }
    arr[position] = newValue;
}

// Search element in array using linear search algorithm
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target)
        {
            return i;
        }
        
    }
    return -1;
}

// Delete an element in array 
void deleteArr(int arr[], int &size, int elementToDelete) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (elementToDelete == arr[i])
        {
            found = true;
            for (int j = i; j < size - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;
        }
    }
    
    if (!found) {
        cout << "Element " << elementToDelete << " not found in the array." << endl;
    } else {
        cout << "Element " << elementToDelete << " deleted successfully." << endl;
    }
}

