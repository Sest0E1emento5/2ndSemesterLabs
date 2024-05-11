#include <iostream>
#include <cmath>
using namespace std;

double distance_calculator(double x1, double y1, double x2, double y2);
double square(double dimension, ...);
void triangle_area(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c);
void maxDiagonalTriangleArea(double angeles, ...);

int main() {
    setlocale(LC_ALL, "Rus");
    maxDiagonalTriangleArea(5, 80.1, 70.2, 60.3, 50.4, 40.5, 30.6, 20.8, 10.9, 1.0, 1.1);
    return 0;
}

double distance_calculator(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double square(double dimension, ...) {
    double* p = &dimension;
    double side = 0;
    for (int i = 0; i < dimension * 2; i = i + 2) {
        side = side + pow(*(p + i + 1) - *(p + i + 2), 2);
    }
    return pow(side, 0.5);
}

void triangle_area(double x_a, double y_a, double x_b, double y_b, double x_c, double y_c) {
    double a = square(2, x_a, x_b, y_a, y_b);
    double b = square(2, x_b, x_c, y_b, y_c);
    double c = square(2, x_c, x_a, y_c, y_a);
    cout << "Сторона AB (a) = " << a << "\n";
    cout << "Сторона BC (b) = " << b << "\n";
    cout << "Сторона CA (c) = " << c << "\n";
    double P = a + b + c;
    cout << "Периметр: \nP = a + b + c =\n= " << a << " + " << b << " + " << c << " =\n= " << P << '\n';
    double p = P / 2;
    cout << "Полупериметр:\np = P / 2 =\n= " << P << " / 2 =\n= " << p << '\n';
    cout << "Площадь ABC:\nS = (p * (p - a) * (p - b) * (p - c))^0.5 = \n";
    cout << "= ((" << p << " * (" << p << " - " << a << ") * (" << p << " - " << b << ") * (" << p << " - " << c << ")) ^ 0.5 = \n";
    cout << "= ((" << p << " * (" << p - a << ") * (" << p - b << ") * (" << p - c << ")) ^ 0.5 = \n";
    double area = pow((p * (p - a) * (p - b) * (p - c)), 0.5);
    cout << "= (" << pow(area, 2) << ")^0.5 = " << area;
}

void maxDiagonalTriangleArea(double angeles, ...) {
    double square = 0;
    double* ptr = &angeles;
    ptr++;
    double max = 0;
    double distance;
    double point1_x;
    double point1_y;
    double point2_x;
    double point2_y;
    double point3_x;
    double point3_y;
    for (int i = 0; i < angeles * 2 - 2; i = i + 2) {
        for (int j = i + 4; j < angeles * 2; j = j + 2) {
            distance = distance_calculator(*(ptr + i), *(ptr + i + 2), *(ptr + j), *(ptr + j + 2));
            if (distance > max) {
                max = distance;
                point1_x = *(ptr + i);
                point1_y = *(ptr + i + 1);
                point2_x = *(ptr + i + 2);
                point2_y = *(ptr + i + 3);
                point3_x = *(ptr + j);
                point3_y = *(ptr + j + 1);
            }
        }
    }
    cout << "Наибольшая диагональ проходит через точки:\n(" << point1_x << ", " << point1_y << "), \
(" << point3_x << ", " << point3_y << ")\n";
    cout << "Ее длина: " << max << '\n';
    cout << "Площадь треугольника с вершинами в точках:\n";
    cout << "(" << point1_x << ", " << point1_y << "), (" << point2_x << ", " << point2_y << "), \
(" << point3_x << ", " << point3_y << ")\n";
    triangle_area(point1_x, point1_y, point2_x, point2_y, point3_x, point3_y);
}