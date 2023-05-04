#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
using namespace std;
typedef int matr[5][7];
typedef int mas[5];
const int start_num = -100;
const int end_num = 100;

//Задать значения целочисленным элементам матриц M и N 5  7
//и сформировать массивы С и D, состоящие из количества отрицательных элементов строк матриц M и N соответственно

void input(matr a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = start_num + (rand() % (end_num - start_num + 1));
        }
    }
}

void output(matr a, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(6) << a[i][j];
        }
        cout << endl;
    }
}

void form(matr a, mas b, int n, int m) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        int cnt_otr = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] < 0) cnt_otr += 1;
        }
        b[k++] = cnt_otr;
    }
}

void output_mas(mas a, int n) {
    for (int i = 0; i < n; i++) cout << setw(6) << a[i];
    cout << endl;
}

int main() {
    srand(time(nullptr));
    
    matr a, b;
    mas p, q;
    
    input(a, 5, 7);
    cout << "Матрица А:" << endl;
    output(a, 5, 7);
    
    input(b, 5, 7);
    cout << "Матрица B:" << endl;
    output(b, 5, 7);
    
    form(a, p, 5, 7);
    form(b,q,5,7);
    
    cout << "Массив P:" << endl;
    output_mas(p,5);
    
    cout << "Массив Q:" << endl;
    output_mas(q,5);

}
