// OOP244 Workshop 7: Inheritance
// File: Vehicle.cpp
// Version: 1.0
// Date: 03/11/2020
// Author: Pat Zdanko
// Description:
// cpp file for the vehicle module
/////////////////////////////////////////////////////////////////

#include "Vehicle.h"
#include "cstring"
#include <iostream>

using namespace std;

namespace sdds {
Vehicle::Vehicle() {
    setVehicleEmpty();
}
Vehicle::Vehicle(int speed, int noOfSeats) {
    setVehicleEmpty();
    if (speed >= MIN_SPEED && noOfSeats > 0) {
        m_speed = speed;
        m_noOfSeats = noOfSeats;
    }
}
void Vehicle::setVehicleEmpty() {
    m_speed = 0;
    m_noOfSeats = 0;
}
bool Vehicle::finetune() {
    bool tuned = false;
    if (m_speed > MAX_SPEED) {
        m_speed = MIN_SPEED;
        tuned = true;
    }
    return tuned;
}
ostream& Vehicle::display(ostream& os) const {
    os << m_speed << "|" << m_noOfSeats << endl;
    if (m_speed > MAX_SPEED) {
        cout << "Car has to be fine tuned for speed limit" << endl;
    }
    return os;
}
istream& Vehicle::input(istream& in) {
    int t_speed;
    int t_noOfSeats;
    cout << "Enter the Vehicle`s speed: ";
    in >> t_speed;
    cout << "Enter no of seats: ";
    in >> t_noOfSeats;
    if (t_noOfSeats > 0 && t_speed >= MIN_SPEED) {
        m_noOfSeats = t_noOfSeats;
        m_speed = t_speed;
    }
    return in;
}
ostream& operator<<(ostream& os, const Vehicle& V) {
    V.display(os);
    return os;
}
istream& operator>>(istream& in, Vehicle& V) {
    V.input(in);
    return in;
}
}