// OOP244 Workshop 7: Inheritance
// File: Car.h
// Version: 1.0
// Date: 03/11/2020
// Author: Pat Zdanko
// Description:
// Header file for the car module
/////////////////////////////////////////////////////////////////
#pragma once
#ifndef SDDS_CAR_H__
#define SDDS_CAR_H__

#include "Vehicle.h"
#include <iostream>

namespace sdds {
const int MAX_CHAR = 20;
const int MIN_YEAR = 2000;

class Car : public Vehicle {
private:
    char m_carType[MAX_CHAR + 1];
    int m_regYear; //must be less than MIN_YEAR
public:
    Car();
    Car(const char* carType, int year, int speed, int noOfSeats);
    void finetune();
    void setCarEmpty();
    bool isCarEmpty() const;
    std::ostream& display(std::ostream& os) const;
    std::istream& input(std::istream& in);
};
std::ostream& operator<<(std::ostream& os, const Car& C);
std::istream& operator>>(std::istream& in, Car& C);
}

#endif // !SDDS_CAR_H__