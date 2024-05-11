#include <iostream>
#include <algorithm>
using namespace std;

void fill(int* ring, int size);
void print(int* ring, int size, int start);
void bubbleSort(int* arr, int size);
void removeEvenElements(int* arr, int& size);


int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введиет размер кольца: ";
    int size;
    cin >> size;
    int* ring = new int[size];
    fill(ring, size);
    cout << "Введенное кольцо:\n";
    print(ring, size, 0);
    cout << "Введите стартовый индекс: ";
    int strartIndex;
    cin >> strartIndex;

    cout << "Введенное кольцо начиная с стартового индекса: ";
    print(ring, size, strartIndex);

    bubbleSort(ring, size);
    cout << "Кольцо после упорядочивания по убыванию:\n";
    print(ring, size, strartIndex);

    removeEvenElements(ring, size);
    cout << "Кольцо после удаления нечетных элементов:\n";
    print(ring, size, strartIndex);

    return 0;
}

void fill(int* ring, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> ring[i];
    }
}

void print(int* ring, int size, int start) {
    for (int i = 0; i < size; i++) {
        cout << ring[(start + i) % size] << " ";
    }
    cout << endl;
}

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void removeEvenElements(int* ring, int& size) {
    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if (ring[i] % 2 == 0) {
            ring[new_size++] = ring[i];
        }
    }
    size = new_size;
}


