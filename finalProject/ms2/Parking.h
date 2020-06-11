/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.h
Version 1.0
Author: Pat Zdanko
Student Id: 129430195
Revision History 
-----------------------------------------------------------
Date       Reason
2020/03/19 Initial Submission
----------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 
-----------------------------------------------------------*/

#ifndef SDDS_PARKING_H__
#define SDDS_PARKING_H__

#include "Menu.h"

namespace sdds {
class Parking {
    char* m_fileName;
    Menu m_parkMenu;
    Menu m_vehicleMenu;
    Parking(const Parking& src) = delete;
    Parking& operator=(const Parking& src) = delete;
    void setEmpty();
    void clearMemory();
    bool isEmpty();
    void parkingStatus();
    void parkVehicle();
    void returnVehicle();
    void listVehicles();
    bool closeParking();
    bool exitParking();
    bool loadData();
    void saveData();

public:
    Parking();
    Parking(const char* fileName);
    ~Parking();
    int run();
};
}

#endif