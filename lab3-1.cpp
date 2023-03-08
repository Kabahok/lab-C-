#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int i = 4;
const double pi = 3.14;

int main() {
    double s = -1;
    while (s <= 1) {
        double y;
        if (abs(s * pi) >= 3.5) {
            y = pi * sin(s);
        } else {
            y = (pow((pi + s), 1/3)) / (pow(s, -pi) * tan(i));
        }

        cout << y << endl;

        s += 0.1;
    }

    return 0;
}
