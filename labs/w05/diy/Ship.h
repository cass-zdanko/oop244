// OOP244 Workshop 5: Operator Overloading
// File: Ship.h
// Version: 1.0
// Date: 2/21/2020
// Author: Pat Zdanko
// Description:
// This file contains protoypes for Ship.cpp
/////////////////////////////////////////////

#pragma once
#ifndef SDDS_SHIP_H__
#define SDDS_SHIP_H__

#include "Engine.h"

namespace sdds {
//const int MAX_ENG = 10;
class Ship {
    char* m_type;
    int m_tsize;
    Engine* m_engines;
    int m_enginesNo;

public:
    Ship();
    Ship(const char* m_type, Engine* engines, int enginesNo);
    ~Ship();
    void clearTypeMemory();
    void clearEnginesMemory();
    void setEmpty();
    bool empty() const;
    double calculatePower() const;
    void display() const;
    const Ship& operator+=(Engine e);
    friend bool operator==(const Ship&, const Ship&);
};

bool operator<(const Ship&, double);
} // namespace sdds
#endif // !SDDS_SHIP_H__