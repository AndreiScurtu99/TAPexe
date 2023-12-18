#pragma once
#ifndef LSICOADADINAMICA_H
#define LSICOADADINAMICA_H

class Node {
    friend class Coada;
private:
    int data;
    Node* next;

public:
    Node(int value) : data(value), next(nullptr) {}
};

class Coada {
private:
    Node* front;
    Node* rear;

public:
    Coada();
    bool isEmpty();
    void enqueue(int value);
    void dequeue();
    void print();
    ~Coada();
};

#endif