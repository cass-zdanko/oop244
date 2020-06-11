/***********************************************************************
// OOP244 Workshop 9: Templates
// File NumbersBox.h
// Version 1.0
// Date	2020/3/30
// Author	Pat Zdanko
// Description
// Contains the container class NumbersBox, used to calculate numbers
/////////////////////////////////////////////////////////////////
***********************************************************************/
#pragma once
#ifndef SDDS_NUMBERSBOX_H__
#define SDDS_NUMBERSBOX_H__

#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
const int MAX_NAME = 15;

template <typename T>
class NumbersBox {
    char m_name[MAX_NAME + 1];
    int m_size;
    T* m_items;

public:
    NumbersBox() {
        setEmpty();
    }
    NumbersBox(int size, const char* name) {
        setEmpty();
        if (size > 0 && name && strlen(name) > 0 && strlen(name) <= MAX_NAME) {
            m_size = size;
            strcpy(m_name, name);
            m_items = new T[m_size];
        }
    }
    ~NumbersBox(){
        delete [] m_items;
        m_items = nullptr;
    }
    void setEmpty() {
        strcpy(m_name, "");
        m_size = 0;
        m_items = nullptr;
    }
    T& operator[](int i) {
        return m_items[i];
    }
    NumbersBox<T>& operator*=(const NumbersBox<T>& other) {
        if (m_size == other.m_size) {
            for (int i = 0; i < m_size; i++) {
                m_items[i] *= other.m_items[i];
            }
        }
        return *this;
    }
    NumbersBox<T>& operator+=(T num) {
        T* temp_items = nullptr;
        temp_items = new T[m_size];
        for (int i = 0; i < m_size; i++) {
            temp_items[i] = m_items[i];
        }
        delete[] m_items;
        m_items = nullptr;
        m_items = new T[m_size + 1];
        for (int i = 0; i < m_size; i++) {
            m_items[i] = temp_items[i];
        }
        m_items[m_size] = num;
        m_size++;
        delete[] temp_items;
        return *this;
    }
    ostream& display(ostream& os) const {
        if (m_items){
            os << "Box name: " << m_name << endl;
            for (int i = 0; i < m_size; i++){
                os << m_items[i];
                if (i < (m_size - 1)){
                    os << ", ";
                } else {
                    os << endl;
                }
            }
        } else {
            os << "Empty Box" << endl;
        }
        return os;
    }
};
template <typename T>
ostream& operator<<(ostream& os, NumbersBox<T>& box) {
    return box.display(os);
}
}

#endif // !SDDS_NUMBERSBOX_H__
