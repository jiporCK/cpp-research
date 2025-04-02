#include <iostream>

using namespace std;
void sortWithBubbleSort(int arr[], int size);
void printArr(int arr[], int size);
int deleteElementInArray(int arr[], int &size, int element);

int main() {

    int score[7] = {5, 6, 7, 4, 2, 9, 30};

    int scoreLength = sizeof(score)/ sizeof(score[0]);

    sortWithBubbleSort(score, scoreLength);

    printArr(score, scoreLength);
    cout << endl;

    scoreLength = deleteElementInArray(score, scoreLength, 4);

    printArr(score, scoreLength);

    return 0;
}

int deleteElementInArray(int arr[], int &size, int element) {
    for (int i = 0; i < size; i++) {
        if (element == arr[i])
        {
            for (int j = i; j < size -1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            i--;            
        }
    }
    return size;
}

void printArr(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

}

void sortWithBubbleSort(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1]= temp;
            }
        }  
    }
}




