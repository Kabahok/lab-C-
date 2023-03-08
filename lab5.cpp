#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
using namespace std;

const int n = 5;
const int m = 6;
const int a = -100;
const int b = 100;
int main() {
    srand(time(nullptr));
    int matrix[n][m];

//  Формируем матрицу

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = a + (rand() % (b - a + 1));
        }
    }

    int t_matrix[m][n];

//    Транспонируем исходную матрицу

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            t_matrix[j][i] = matrix[i][j];
        }
    }

    int p[m];

    for (int i = 0; i < m; i++) {
        int max = t_matrix[i][0], min = t_matrix[i][n-1];

        for (int j = 0; j < n; j++) {
            if (t_matrix[i][j] < min) {
                min = t_matrix[i][j];
            } if (t_matrix[i][j] > max) {
                max = t_matrix[i][j];
            }
        }

        p[i] = min * max;
    }


//  Вывод матриц (исходной и транспанированной)

    cout << "Исходная матрица" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << "Транспонированная матрица" << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(6) << t_matrix[i][j];
        }
        cout << endl;
    }

    cout << endl;
    cout << "Массив произведений макс и мин каждого столбца" << endl;

    for (int i = 0; i < m; i++) {

        cout << setw(6) << p[i];

    }

    return 0;
}
