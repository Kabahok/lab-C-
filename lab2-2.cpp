#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


int main() {
    int x,y;

    cout << "Введите значение х: "; cin >> x;
    cout << "Введите значение y: "; cin >> y;

    if ((y <= 1.5 * x) && (y <= -1.5 * x + 6) && ( y >= 0)) {
        cout << "Точка принадлежит заштрихованной области";
    } else {
        cout << "Точка не принадлежит заштрихованной области";
    }

    return 0;
}
