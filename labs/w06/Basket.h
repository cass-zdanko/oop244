// File: BasketTester.cpp
// Version: 1.1
// Date: 03/05/2020
// Author: Pat Zdanko
// Description:
// Contains the function declarations of the
// basket module.
/////////////////////////////////////////////

#pragma once
#ifndef SDDS_BASKET_H__
#define SDDS_BASKET_H__

#include <iostream>

namespace sdds {
class Basket {
    char* m_fruitName;
    int m_qty;
    double m_price;

public:
    Basket();
    Basket(const char* fruitName, int qty, double price);
    Basket(const Basket& src);
    ~Basket();
    void setEmpty();
    void clearMemory();
    void setName(const char* n_fruitName);
    void setQty(int n_qty);
    void setPrice(double n_price);
    bool isempty() const;
    bool addPrice(double add);
    std::ostream& display(std::ostream& os) const;
    Basket& operator=(const Basket& src);
    bool operator==(const Basket& test);
    bool operator!=(const Basket&);
};
std::ostream& operator<<(std::ostream& os, const Basket& bsk);
}

#endif