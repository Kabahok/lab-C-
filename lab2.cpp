#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double x, y;

    cout << "Введите значение х:" << endl;
    cin >> x;

    if (x > 2.5) {
        y =  (x + 1);
    } else if (x >= 0 && x < 2) {
        y =  (1 + pow(x,5));
    } else {
        y =  (x + log(abs(sin(x))));
    }

    cout << "Значение y равно: " << y << endl;

    cout << y << endl;
    return 0;
}
