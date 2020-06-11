// OOP244 Workshop 5: Operator Overloading
// File: Engine.cpp
// Version: 1.0
// Date: 2/13/2020
// Author: Pat Zdanko
// Description:
// Contains the description of the engine class
/////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include "Engine.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
Engine::Engine() {
    setEmpty();
}
Engine::Engine(const char* type, double size) {
    setEmpty();
    if (type && type[0] != '\0' && strlen(type) < 31 && size > 0){
        strcpy(m_type, type);
        m_size = size;
    }
}
Engine::~Engine() {

}
void Engine::setEmpty() {
    m_type[0] = 0;
    m_size = 0;
}
double Engine::get() const { return m_size; }
void Engine::display() const
{
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << m_size; 
    cout << " liters - " << m_type << endl;
}

} // namespace sdds