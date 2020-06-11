/* Citation and Sources...
Final Project Milestone 5
Module: Motorcycle
Filename: Motorcycle.cpp
Version 1.0
Author: Pat Zdanko
Student Id: 129430195
Revision History 
-----------------------------------------------------------
Date       Reason
2020/04/07 Initial Submission
----------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments. 
-----------------------------------------------------------*/
#include "Motorcycle.h"
#include "iostream"

using namespace std;

namespace sdds {
Motorcycle::Motorcycle() : Vehicle() {
    m_sideCar = false;
}
Motorcycle::Motorcycle(const char* license, const char* makeModel) : Vehicle(license, makeModel) {
    m_sideCar = false;
}
istream& Motorcycle::read(istream& is) {
    if (isCsv()) {
        Vehicle::read(is);
        is >> m_sideCar;
        is.ignore(2000, '\n');
    } else {
        cout << endl << "Motorcycle information entry" << endl;
        Vehicle::read(is);
        cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";
        string yesno;
        getline(is, yesno, '\n');
        while (yesno != "Y" && yesno != "y" && yesno != "N" && yesno != "n") {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
            getline(is, yesno, '\n');
        }
        m_sideCar = (yesno == "Y" || yesno == "y");
    }
    return is;
}
ostream& Motorcycle::write(ostream& os) const {
    if (isEmpty()) {
        os << "Invalid Motorcycle Object" << endl;
    } else {
        if (isCsv()) {
            os << "M,";
            Vehicle::write(os);
            os << m_sideCar << endl;
        } else {
            os << "Vehicle type: Motorcycle" << endl;
            Vehicle::write(os);
            if (m_sideCar) {
                os << "With Sidecar" << endl;
            }
        }
    }
    return os;
}
}