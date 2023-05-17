#include <iostream>
#include <iomanip>
using namespace std;
const int A = 1000;
const int B = 5000;
const int SIZE = 20;

struct Boot {
    string article;
    string name;
    int count;
    int price;
};

void BoubleSort(Boot boots[], int size) {
    
    for (int i = 0; i < size - 1; i++) {
        if (size == 1) break;
        
        for (int j = 0; j < size - i - 1; j++) {
            if (boots[j].name > boots[j + 1].name) {
                swap(boots[j],boots[j+1]);
            }
        }
    }
};

void output(Boot boots[], int size) {
    cout << setw(26) << "Name|" << setw(10) << "Count|" << setw(9) << "Price|" << setw(9) << "Article|" << endl;
    for (int i = 0; i < size; i ++) {
        cout << setw(55) << "____________________________________________" << endl;
        
        cout << setw(26) << boots[i].name << setw(9) << boots[i].count << setw(9) << boots[i].price << setw(10) << boots[i].article << endl;
    }
}

void output(Boot boots[], int size, int min_price, int max_price) {
    cout << setw(26) << "Name|" << setw(10) << "Count|" << setw(9) << "Price|" << setw(9) << "Article|" << endl;
    for (int i = 0; i < size; i ++) {
        
        if (boots[i].price >= min_price && boots[i].price <= max_price) {
            cout << setw(55) << "____________________________________________" << endl;
            cout << setw(26) << boots[i].name << setw(9) << boots[i].count << setw(9) << boots[i].price << setw(10) << boots[i].article << endl;
        }
    }
}

int main() {
    Boot boots[] = {
        
        {"М", "Adidas Ultraboost", 5, 2000},
        {"Д", "Nike Air Max 90", 3, 1500},
        {"П", "Reebok Classic", 10, 800},
        {"М", "Timberland Boot", 8, 1800},
        {"М", "Dr. Martens 1460", 12, 1600},
        {"М", "Vans Old Skool", 7, 7000},
        {"Д", "Converse Star", 6, 6000},
        {"М", "New Balance 574", 9, 1000},
        {"П", "Puma Suede", 4, 50},
        {"Д", "ASICS Gel-Lyte III", 2, 13000},
        {"М", "Salomon Speedcross", 5, 1500},
        {"Д", "Skechers Go Walk", 3, 70000},
        {"М", "Brooks Ghost", 10, 1200},
        {"Д", "Adidas Superstar", 6, 900},
        {"П", "Crocs Classic Clog", 8, 400},
        {"М", "Under Armour HOVR Phantom", 4, 1040},
        {"М", "Hoka One One Clifton", 7, 16000},
        {"Д", "Puma RS-X", 9, 11000},
        {"П", "Merrell Jungle Moc", 5, 9000},
        {"М", "On Cloud", 3, 1800}
        
    };
    
    
    output(boots, SIZE);
    BoubleSort(boots, SIZE);
    cout << endl << "Отсортированный ассортимент"<< endl << endl;
    output(boots, SIZE);
    cout << endl << "Товары в заданном диапазоне цен"<< endl << endl;
    output(boots, SIZE, A, B);
    
    return 0;
}
