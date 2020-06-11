/* Citation and Sources...
Final Project Milestone 4
Module: Vehicle
Filename: Vehicle.h
Version 1.0
Author: Pat Zdanko
Student Id: 129430195
Revision History 
-----------------------------------------------------------
Date       Reason
2020/03/27 Initial Submission
----------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 
-----------------------------------------------------------*/
#pragma once
#ifndef SDDS_VEHICLE_H__
#define SDDS_VEHICLE_H__

#include "ReadWritable.h"
#include <iostream>
using namespace std;

namespace sdds {
const int MAX_LICENSE = 8; //character limit for license plates
class Vehicle : public ReadWritable {
private:
    char* m_license;
    char* m_makeModel;
    int m_parkSpot;

protected:
    void setEmpty();
    void clearMakeModel();
    void clearLicense();
    bool isEmpty() const;
    void setLicensePlate(const char* license);
    const char* getLicensePlate() const;
    const char* getMakeModel() const;
    void setMakeModel(const char* makeModel);

public:
    Vehicle();
    Vehicle(const char* license, const char* makeModel);
    ~Vehicle();
    Vehicle(const Vehicle&) = delete;
    Vehicle& operator=(const Vehicle&) = delete;
    int getParkingSpot() const;
    void setParkingSpot(int parkSpot);
    bool operator==(const char* license) const;
    bool operator==(const Vehicle& other) const;
    istream& read(istream& is);
    ostream& write(ostream& os) const;
};
}

#endif