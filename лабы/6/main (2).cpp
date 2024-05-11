#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int sinArr[] = { 0, 1, 2, 3, 4, 3, 2, 1 };
int cosArr[] = { 2, 1, 0, 1, 2, 3, 4, 3 };
char arr[100][200] = {'0'};
string str;

void print();
void fillArrVoid();
void DrawSinCos(int arr[]);
void DrawLog();
void DrawExp();

int main() {
	system("chcp 1251>NULL");
	cout << "Введите строку (10+ символов):\n";
	getline(cin, str);
	fillArrVoid();
	cout << "График синуса:\n";
	DrawSinCos(sinArr);
	print();
	fillArrVoid();
	cout << "График косинуса:\n";
	DrawSinCos(cosArr);
	print();
	fillArrVoid();
	cout << "График логарифма:\n";
	DrawLog();
	print();
	fillArrVoid();
	cout << "График экспоненты:\n";
	DrawExp();
	print();
	return 0;
}

void print() {
	cout << '\n';
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < size(str); j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void fillArrVoid() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < size(str); j++) {
			arr[i][j] = ' ';
		}
	}
}

void DrawSinCos(int arr[]) {
	for (int i = 0; i < size(str); i++) {
		int j = arr[i % 8];
		arr[j][i] = str[i];
	}
}

void DrawLog() {
	int log_arr[11] = { 4, 3, 2, 2, 2, 1, 1, 1, 1, 1, 1};
	for (int i = 0; i < 11; i++) {
		int j = log_arr[i];
		arr[j][i] = str[i];
	}
	for (int i = 11; i < size(str); i++) {
		arr[0][i] = str[i];
	}
}

void DrawExp() {
	int exp_y_arr[] = { 4, 3, 2, 1, 0};
	int exp_x_arr[] = { 0, 1, 2, 2, 3};
	for (int i = 0; i < 5; i++) {
		int j = exp_y_arr[i];
		int k = exp_x_arr[i];
		arr[j][k] = str[i];
	}
}

