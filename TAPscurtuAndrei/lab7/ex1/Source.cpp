#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
template <typename T>
T Min(const T* arr, int size) {
    if (size <= 0) {
        return T{};
    }
    T minValue = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minValue) {
            minValue = arr[i];
        }
    }
    return minValue;
}

template <typename T>
T Max(const T* arr, int size) {
    if (size <= 0) {
        return T{};
    }
    T maxValue = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }
    return maxValue;
}

template <typename T>
bool CautareSecventiala(const T* arr, int size, const T& element) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == element) {
            return true; 
        }
    }
    return false; 
}

template <typename T>
bool CautareBinar(const T* arr, int size, const T& element) {
    int stanga = 0;
    int dreapta = size - 1;
    while (stanga <= dreapta) {
        int mijloc = stanga + (dreapta - stanga) / 2;

        if (arr[mijloc] == element) {
            return true; 
        }
        if (arr[mijloc] < element) {
            stanga = mijloc + 1;
        }
        else {
            dreapta = mijloc - 1;
        }
    }

    return false; 
}

//template <typename T>
//void OrdonareBule(T* arr, int size) {
//    for (int i = 0; i < size - 1; ++i) {
//        for (int j = 0; j < size - i - 1; ++j) {
//            if (arr[j] > arr[j + 1]) {
//                T temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
// am folosit swap din libraria algoritm pentru ca imi genera erori fara
template <typename T>
void OrdonareBule(T* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
template <>
void OrdonareBule(char** arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (strcmp(arr[j], arr[j + 1]) < 0) {
                char* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr1[] = { 4, 2, 8, 1, 5 };
    cout << "Min: " << Min(arr1, 5) << ", Max: " << Max(arr1, 5) << endl;

    double arr2[] = { 3.14, 1.0, 2.71, 0.5 };
    cout << "Min: " << Min(arr2, 4) << ", Max: " << Max(arr2, 4) << endl;

    char arr3[][10] = { "abc", "xyz", "def", "ghi" };
    OrdonareBule(arr3, 4);
    cout << "sortat in ordine invers alfabetica ";
    for (const auto& str : arr3) {
        cout << str << " ";
    }

    return 0;
}