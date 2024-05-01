#include "Array.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    srand(time(nullptr)); // Ініціалізуємо генератор випадкових чисел

    double* dynamicArray = Array::generateDynamicArray(n); // Генеруємо динамічний масив

    if (dynamicArray == nullptr) {
        cout << "No negative numbers found in the array.\n";
        return 0;
    }

    cout << "Generated array:\n";
    for (int i = 0; i < n; ++i) {
        // Генеруємо випадкове число у діапазоні від -50 до 50
        dynamicArray[i] = rand() % 101 - 50;
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    // Знаходимо півсуму
    double sum = 0.0;
    int negativeIndex = -1;
    for (int i = 0; i < n; ++i) {
        sum += dynamicArray[i];
        if (dynamicArray[i] < 0 && negativeIndex == -1) {
            negativeIndex = i;
        }
    }
    double halfSum = sum / 2.0;

    cout << "Half sum: " << halfSum << endl;

    // Розділяємо кожне число на півсуму
    cout << "Array divided by half sum:\n";
    for (int i = 0; i < n; ++i) {
        dynamicArray[i] /= halfSum;
        cout << dynamicArray[i] << " ";
    }
    cout << endl;

    // Звільняємо пам'ять, виділену для динамічного масиву
    delete[] dynamicArray;

    return 0;
}
