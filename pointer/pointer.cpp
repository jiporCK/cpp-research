#include <iostream>

using namespace std;

void swapTwoValue(int* x, int* y);

int main() {

    int x = 10;
    int y = 20;

    cout << x << endl;

    cout << &x << endl;

    swapTwoValue(&x, &y);

    cout << x << " and " << y << endl;

    return 0;
}

void swapTwoValue(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}