// OOP244 Workshop 7: Inheritance
// File: Vehicle.h
// Version: 1.0
// Date: 03/11/2020
// Author: Pat Zdanko
// Description:
// Header file for the vehicle module
/////////////////////////////////////////////////////////////////
#pragma once
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include <iostream>

namespace sdds {
const int MIN_SPEED = 100;
const int MAX_SPEED = 140;

class Vehicle {
private:
    int m_speed; // between MIN_SPEED and MAX_SPEED
    int m_noOfSeats; // greater than 0

public:
    Vehicle();
    Vehicle(int speed, int noOfSeats);
    void clearMemory();
    void setVehicleEmpty();
    bool finetune();
    std::ostream& display(std::ostream& os) const;
    std::istream& input(std::istream& in);
};
std::ostream& operator<<(std::ostream& os, const Vehicle& V);
std::istream& operator>>(std::istream& in, Vehicle& V);
}

#endif // !SDDS_VEHICLE_H__