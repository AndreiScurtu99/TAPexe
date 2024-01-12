#include "Tablou.h"
#include <iostream>
using namespace std;
int main() {
    Tablou<int> intArray(5);
    cout << "Enter 5 integers: ";
    cin >> intArray;
    cout << "You entered: " << intArray << std::endl;

    Tablou<char> charArray(10);
    cout << "Enter 10 characters: ";
    cin >> charArray;
    cout << "You entered: " << charArray << std::endl;

    return 0;
}