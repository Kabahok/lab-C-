#include <iostream>
#include <math.h>
#include <iomanip>
#include <time.h>
using namespace std;

const int n = 50;
const int a = -100;
const int b = 100;
int main() {
    srand(time(nullptr));

    int arr[n];
    long p = 1;
    int cntOtr = 0;

    for (int i = 0; i < n; i++) {
        arr[i] = a + (rand() % (b - a));
    }

    for(int i = 0; i < n; i++) {
        if (arr[i] > 0 && i % 2 != 0) {
            p *= arr[i];
        }
        if (arr[i] < 0) {
            cntOtr += 1;
        }
        cout << arr[i] << endl;
    }

    cout << "Произведение равно: " << p << endl;
    cout << "Количество отрицательных элементов равно: " << cntOtr << endl;


    return 0;
}
