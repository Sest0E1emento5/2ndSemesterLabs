#include <iostream>
#include <string>
using namespace std;

void fill(string* const arr, const int size);
void print(const string* const arr, const int size);
void insert(string*& arr, int& size, int& number, const string value);

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "Введите размер массива: ";
	int size;
	cin >> size;
	string* arr = new string[size];
	fill(arr, size);
	print(arr, size);
	cout << "Введите номер добовляемого элемента: ";
	int number;
	cin >> number;
	number--;
	cout << "Введите значение добовляемого элемента: ";
	string value;
	cin >> value;
	insert(arr, size, number, value);
	print(arr, size);
	delete[] arr;
	return 0;
}

void fill(string* const arr, const int size) {
	for (int i = 0; i < size; i++) {
		cout << "Введите элемента массива: ";
		cin >> arr[i];
	}
}

void print(const string* const arr, const int size) {
	cout << "Наш массив:\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void insert(string*& arr, int& size, int& number, const string value) {
	size++;
	string* new_array = new string[size];
	for (int i = 0; i < number; i++) {
		new_array[i] = arr[i];
	}
	new_array[number] = value;
	for (int i = number + 1; i < size; i++) {
		new_array[i] = arr[i - 1];
	}
	delete[] arr;
	arr = new_array;
}
