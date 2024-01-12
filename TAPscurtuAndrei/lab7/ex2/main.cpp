#include "LSI.h"
#include <iostream>
using namespace std;
int main() {
    LSI<int> intList;
    intList.insert(1);
    intList.insert(2);
    intList.insert(3);
    cout << intList << std::endl;

    LSI<int> intListCopy = intList; 
    cout << intListCopy << std::endl;

    LSI<double> doubleList;
    doubleList.insert(2.5);
    doubleList.insert(3.7);
    cout  << doubleList << std::endl;

    intList = intListCopy; 
    cout  << intList << std::endl;

    intList.remove(2); 
    cout << intList << std::endl;

    return 0;
}