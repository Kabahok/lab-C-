#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const int i = 4;
const double pi = 3.14;

int main() {
    int firstNum;
    int cnt = 0;
    for (int i = 0; ; i++) {
        int currNum; cout << "Введите число" << endl; cin >> currNum;
        if (i == 0) {
            firstNum = currNum;
            continue;
        } else if (currNum == 99) {
            break;
        } else if (currNum > firstNum) {
            cnt += 1;
        }
    }

    cout << "Количество чисел, которые больше первого, равно: " << cnt;

    return 0;
}
