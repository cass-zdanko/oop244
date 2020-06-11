// OOP244 Workshop 5: Operator Overloading
// File: Engine.h
// Version: 1.0
// Date: 2/21/2020
// Author: Pat Zdanko
// Description:
// This file contains protoypes for Engine.cpp
/////////////////////////////////////////////

#pragma once
#ifndef SDDS_ENGINE_H__
#define SDDS_ENGINE_H__

namespace sdds {
class Engine {
    double m_size; // > 0
    char m_type[31];

public:
    Engine();
    Engine(const char* type, double size);
    void setEmpty();
    double get() const; // return size
    void display() const; // display size and type
};
} // namespace sdds
#endif // !SDDS_ENGINE_H__