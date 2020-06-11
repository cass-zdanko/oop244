// File: BasketTester.cpp
// Version: 1.1
// Date: 03/05/2020
// Author: Pat Zdanko
// Description:
// Contains the function definitions of the
// basket module.
/////////////////////////////////////////////

#include "Basket.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
Basket::Basket() {
    setEmpty();
}
Basket::Basket(const char* fruitName, int qty, double price) {
    setEmpty();
    if (fruitName && qty > 0 && price >= 0) {
        setName(fruitName);
        setQty(qty);
        setPrice(price);
    }
}
Basket::Basket(const Basket& src) {
    if (src.m_fruitName) {
        m_fruitName = new char[strlen(src.m_fruitName) + 1];
        strcpy(m_fruitName, src.m_fruitName);
    } else {
        m_fruitName = nullptr;
    }
    m_qty = src.m_qty;
    m_price = src.m_price;
}
Basket::~Basket() {
    clearMemory();
}
void Basket::setEmpty() {
    m_fruitName = nullptr;
    m_qty = 0;
    m_price = -1;
}
void Basket::clearMemory() {
    delete[] m_fruitName;
    m_fruitName = nullptr;
}
void Basket::setName(const char* n_fruitName) {
    clearMemory();
    m_fruitName = new char[strlen(n_fruitName) + 1];
    strcpy(m_fruitName, n_fruitName);
}
void Basket::setQty(int n_qty) {
    m_qty = n_qty;
}
void Basket::setPrice(double n_price) {
    m_price = n_price;
}
bool Basket::isempty() const {
    bool empty = true;
    if (m_fruitName && m_qty > 0 && m_price >= 0) {
        empty = false;
    }
    return empty;
}
bool Basket::addPrice(double add) {
    //bool checks if the price can be added i.e. m_price is not empty state
    bool added = false;
    if (m_price >= 0) {
        m_price += add;
        added = true;
    }
    return added;
}
ostream& Basket::display(ostream& os = cout) const {
    if (isempty()) {
        os << "The Basket has not yet been filled" << endl;
    } else {
        os << "Basket Details" << endl;
        os << "Name: " << m_fruitName << endl;
        os << "Quantity: " << m_qty << endl;
        os << "Price: ";
        os.setf(ios::fixed);
        os.precision(2);
        os << m_price << endl;
        os.unsetf(ios::fixed);
    }
    return os;
}
Basket& Basket::operator=(const Basket& src) {
    //checks if values are not already equal
    if (this != &src) {
        //checks if fruitName is nullptr or not
        if (src.m_fruitName) {
            setName(src.m_fruitName);
        } else {
            m_fruitName = nullptr;
        }
        setQty(src.m_qty);
        setPrice(src.m_price);
    }
    return *this;
}
bool Basket::operator==(const Basket& test) {
    bool equal = false;
    if (m_qty == test.m_qty && m_price == test.m_price) {
        if (m_fruitName && test.m_fruitName) {
            equal = !strcmp(m_fruitName, test.m_fruitName);
        } else if (m_fruitName == nullptr && test.m_fruitName == nullptr) {
            equal = true;
        }
    }
    return equal;
}
bool Basket::operator!=(const Basket& test) {
    //opposite result of ==
    return !(this == &test);
}
ostream& operator<<(ostream& os, const Basket& bsk) {
    bsk.display(os);
    return os;
}
}
