#include "LSI.h"
using namespace std;
template <typename T>
Node<T>::Node(const T& value) : data(value), next(nullptr) {}

template <typename T>
LSI<T>::LSI() : head(nullptr) {}

template <typename T>
LSI<T>::LSI(const LSI& other) {
    copyList(other.head);
}

template <typename T>
LSI<T>::~LSI() {
    clear();
}

template <typename T>
LSI<T>& LSI<T>::operator=(const LSI& other) {
    if (this != &other) {
        clear();
        copyList(other.head);
    }
    return *this;
}

template <typename T>
bool LSI<T>::operator==(const LSI& other) const {
    Node<T>* currentThis = head;
    Node<T>* currentOther = other.head;

    while (currentThis && currentOther) {
        if (currentThis->data != currentOther->data) {
            return false;
        }
        currentThis = currentThis->next;
        currentOther = currentOther->next;
    }

    return (currentThis == nullptr && currentOther == nullptr);
}
//Nu inteleg ce nu merge la op >> si <<
template <typename T, typename U>
ostream& operator<<(ostream& os, const LSI<U>& list) {
    Node<U>* current = list.head;
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

template <typename T, typename U>
istream& operator>>(istream& is, LSI<U>& list) {
    U value;
    while (is >> value) {
        list.insert(value);
    }
    return is;
}

template <typename T>
void LSI<T>::insert(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

template <typename T>
void LSI<T>::remove(const T& value) {
    if (!head) {
        return;
    }

    if (head->data == value) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node<T>* current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (current->next) {
        Node<T>* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

template <typename T>
void LSI<T>::copyList(const Node<T>* otherHead) {
    if (!otherHead) {
        head = nullptr;
        return;
    }

    head = new Node<T>(otherHead->data);
    Node<T>* currentThis = head;
    const Node<T>* currentOther = otherHead->next;

    while (currentOther) {
        currentThis->next = new Node<T>(currentOther->data);
        currentThis = currentThis->next;
        currentOther = currentOther->next;
    }
}

template <typename T>
void LSI<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}