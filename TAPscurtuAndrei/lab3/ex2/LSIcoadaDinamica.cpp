#include "LSIcoadaDinamica.h"
#include <iostream>
using namespace std;
Coada::Coada() : front(nullptr), rear(nullptr) {}

bool Coada::isEmpty() {
    return (front == nullptr);
}

void Coada::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    std::cout << value << " a fost adaugat in coada." << std::endl;
}

void Coada::dequeue() {
    if (isEmpty()) {
        std::cout << "Coada este goala." << std::endl;
        return;
    }

    Node* temp = front;
    front = front->next;

    std::cout << temp->data << " a fost eliminat din coada." << std::endl;
    delete temp;

    if (front == nullptr) {
        rear = nullptr;
    }
}

void Coada::print() {
    if (isEmpty()) {
        std::cout << "Coada este goala." << std::endl;
        return;
    }

    Node* temp = front;
    std::cout << "Elementele din coada sunt: ";
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Coada::~Coada() {
    while (!isEmpty()) {
        dequeue();
    }
}