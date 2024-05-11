#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;

void file_copyer(string* arr, const int size, const string in_file);
void file_printer(string* arr, const int size, const string out_file);
void processing(string* arr, int size);
int elem_deleter(string* arr, int* size, int number);
void arr_printer(string* arr, const int size);
int number_counter(const string word);
bool is_digit(const char letter);
int max_searching(string* arr, const int size);

int main() {
    string in_file = "F1.txt";
    string out_file = "F2.txt";
    int size = 5;
    string* arr = new string[size];
    file_copyer(arr, size, in_file);
    //arr_printer(arr, size);
    processing(arr, size);
    file_printer(arr, size, out_file);
    cout << max_searching(arr, size);
    return 0;
}

void arr_printer(string* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " " << endl;
    }
}

void file_copyer(string* arr, const int size, const string in_file) {
    ifstream input;
    input.open(in_file);
    for (int i = 0; i < size; i++) {
        getline(input, arr[i]);
    }
    input.close();
}

void file_printer(string* arr, const int size, const string out_file) {
    ofstream output;
    output.open(out_file);
    for (int i = 0; i < size; i++)
        output << arr[i] << endl;
    output.close();
}

int elem_deleter(string* arr, int size, int number) {
    for (int i = number; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return --size;
}

void processing(string* arr, int size) {
    for (int i = 0; i < size; i++) {
        int count = 0;
        string str = arr[i];
        for (int j = 0; j < arr[i].size(); j++) {
            if (str[j] == ' ') {
                count++;
            }
        }
        if (count == 0) {
            size = elem_deleter(arr, size, i);
        }
    }
}

int number_counter(const string word) {
    int count = 0;
    for (int i = 0; i < word.size(); i++) {
        if (is_digit(word[i])) {
            count++;
        }
    }
    return count;
}

bool is_digit(const char letter) {
    for (int i = 0; i < 10; i++) {
        if (char(i) == letter) {
            cout << "!" << char(i);
            return true;
        }
    }
    return false;
}

int max_searching(string* arr, const int size) {
    int max_count = 0;
    int number = 1;
    int search_number = -1;
    for (int i = 0; i < size; i++) {
        int count = 0;
        string str = arr[i];
        cout << "i = " << i << ", arr[i] = " << arr[i] << '\n';
        for (int j = 0; j < arr[i].size(); j++) {
            cout << "j = " << j << ", str[j] = " << str[j] << " :: " << is_digit(str[j]) << '\n';
            if (str[j] != ' ') {
                count = count + is_digit(str[j]);
            }
            else {
                number++;
            }
            if (count >= max_count) {
                max_count = count;
                search_number = number;
            }
        }
        number++;
    }
    return search_number;
}


/*
1) 	Создать текстовый файл F1 не менее, чем из 10 строк и записать в него информацию
2) 	Скопировать из файла F1 в файл F2 все строки, в которых содержится не менее двух одинаковых слов.
3) 	Определить номер слова, в котором больше всего цифр.
*/