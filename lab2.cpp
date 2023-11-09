#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    string lastName;
    string department;
    int birthYear;
    int experience;
    string position;
    double salary;
    
};

bool compareByExperience(const Employee& a, const Employee& b) {
    return a.experience < b.experience;
}




int main() {

    ifstream inputFile("/Users/egoravdeev/Documents/labs/lab3/lab3/file.txt");
    
    if (!inputFile) {
        cerr << "Ошибка открытия файла" << endl;
        return 1;
    }
    
    ofstream binaryFile("employees.txt", ios::binary);
    
    if (!binaryFile) {
        cerr << "Ошибка создания бинарного файла" << endl;
        return 1;
    }
    
    Employee emp;
    
    while (inputFile >> emp.lastName >> emp.department >> emp.birthYear >> emp.experience >> emp.position >> emp.salary) {
        
        binaryFile.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));

    }
    
    inputFile.close();
    binaryFile.close();
    
    ifstream binaryInput("employees.txt", std::ios::binary);

       if (!binaryInput) {
           std::cerr << "Ошибка открытия бинарного файла" << std::endl;
           return 1;
       }

       Employee sortedEmployees[100];
       int count = 0;

       while (binaryInput.read(reinterpret_cast<char*>(&sortedEmployees[count]), sizeof(Employee))) {
           count++;
       }

       binaryInput.close();

       sort(sortedEmployees, sortedEmployees + count, compareByExperience);

       int requiredExperience = 5;

       cout << "Сотрудники с опытом работы более " << requiredExperience << " лет:" << endl;
       for (int i = 0; i < count; i++) {
           if (sortedEmployees[i].experience > requiredExperience) {
               cout << "Фамилия: " << sortedEmployees[i].lastName << ", Отдел: " << sortedEmployees[i].department
                         << ", Стаж: " << sortedEmployees[i].experience << " лет" << endl;
           }
       }

    

    return 0;
}
