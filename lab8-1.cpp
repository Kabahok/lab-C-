#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string f(string input) {
   string output;
   string item;
   istringstream iss(input);

   while (iss >> item) {
       if (item == "no") {
           output += ",";
       }
       output += item + " ";
   }
   return output;
}


int main() {

//    string input;
//    getline(cin, input)

   string input = "This is no a test, no just a sample string";
   cout << "Введенная строка: " + input << endl << endl;
   string output = f(input);
   cout << "Итоговая строка: " << output << endl;

   return 0;
}
