// OOP244 Workshop 7: Inheritance
// File: Car.cpp
// Version: 1.0
// Date: 03/11/2020
// Author: Pat Zdanko
// Description:
// Cpp file for the car module
/////////////////////////////////////////////////////////////////

#include "Car.h"
#include "Vehicle.h"
#include "cstring"
#include <iostream>

using namespace std;

namespace sdds {
Car::Car()
    : Vehicle() {
    setCarEmpty();
}
Car::Car(const char* carType, int year, int speed, int noOfSeats)
    : Vehicle(speed, noOfSeats) {
    setCarEmpty();
    if (carType && strlen(carType) < 20 && year >= 2000) {
        strcpy(m_carType, carType);
        m_regYear = year;
    }
}
void Car::setCarEmpty() {
    m_carType[0] = 0;
    m_regYear = 0;
}
bool Car::isCarEmpty() const {
    return (m_regYear < 2000 || m_carType[0] == 0);
}
void Car::finetune() {
    if (!isCarEmpty()) {
        if (Vehicle::finetune()) {
            cout << "This car is finely tuned to default speed" << endl;
        } else {
            cout << "Idk if this is supposed to say something" << endl;
        }
    } else {
        cout << "Car cannot be tuned and has to be scraped" << endl;
    }
}
ostream& Car::display(ostream& os) const {
    if (isCarEmpty()) {
        os << "Car is not initiated yet" << endl;
    } else {
        os.width(20);
        os.setf(ios::left);
        os << m_carType << m_regYear << "|";
        Vehicle::display(os);
    }
    return os;
}
istream& Car::input(istream& in) {
    char t_carType[MAX_CHAR + 1];
    int t_year;
    cout << "Enter the car type: ";
    in >> t_carType;
    cout << "Enter the car registration year: ";
    in >> t_year;
    if (t_year >= 2000) {
        strcpy(m_carType, t_carType);
        m_regYear = t_year;
    }
    Vehicle::input(in);
    return in;
}
ostream& operator<<(ostream& os, const Car& C) {
    C.display(os);
    return os;
}
istream& operator>>(istream& in, Car& C) {
    C.input(in);
    return in;
}
}