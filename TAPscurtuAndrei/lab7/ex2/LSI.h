#pragma once
#ifndef LSI_H
#define LSI_H

#include <iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(const T& value);
};

template <typename T>
class LSI {
private:
    Node<T>* head;

public:
    LSI();

    LSI(const LSI& other);

    ~LSI();

    LSI& operator=(const LSI& other);

    bool operator==(const LSI& other) const;

    template <typename U>
    friend ostream& operator<<(ostream& os, const LSI<U>& list);

    template <typename U>
    friend istream& operator>>(istream& is, LSI<U>& list);


    void insert(const T& value);

    void remove(const T& value);

private:
    void copyList(const Node<T>* otherHead);

    void clear();
};

#endif 

