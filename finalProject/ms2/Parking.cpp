/* Citation and Sources...
Final Project Milestone 2
Module: Parking
Filename: Parking.cpp
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
#include "Parking.h"
#include "Menu.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {
Parking::Parking() {
    setEmpty();
}
Parking::Parking(const char* fileName) {
    setEmpty();
    if (fileName && strlen(fileName) > 0) {
        m_fileName = new char[strlen(fileName) + 1];
        strcpy(m_fileName, fileName);
    }
    if (loadData()) {
        m_parkMenu = Menu("Parking Menu, select an action:");
        m_parkMenu << "Park Vehicle"
                   << "Return Vehicle"
                   << "List Parked Vehicles"
                   << "Close Parking (End of day)"
                   << "Exit Program";
        m_vehicleMenu = Menu("Select type of the vehicle:", 1);
        m_vehicleMenu << "Car"
                      << "Motorcycle"
                      << "Cancel";
    } else {
        cout << "Error in data file" << endl;
    }
}
Parking::~Parking() {
    saveData();
    clearMemory();
}
int Parking::run() {
    int error = 1;
    bool done = false;
    if (!isEmpty()) {
        error = 0;
        do {
            parkingStatus();
            int parkChoice = m_parkMenu;
            if (parkChoice == 1) { //Park vehicle
                parkVehicle();
            } else if (parkChoice == 2) { //Return Vehicle
                returnVehicle();
            } else if (parkChoice == 3) { //List Parked Vehicles
                listVehicles();
            } else if (parkChoice == 4) { //Close Parking
                done = closeParking();
            } else if (parkChoice == 5) { //Exit
                done = exitParking();
                if(done){
                    cout << "Exiting program!" << endl;
                }
            } else { //error
                cout << "Parking menu error - unrecognizable option selected" << endl;
                done = true;
            }
        } while (!done);
    }
    return error;
}
void Parking::setEmpty() {
    m_fileName = nullptr;
}
void Parking::clearMemory() {
    delete[] m_fileName;
    m_fileName = nullptr;
}
bool Parking::isEmpty() {
    return (m_fileName == nullptr);
}
void Parking::parkingStatus() {
    cout << "****** Seneca Valet Parking ******" << endl;
}
void Parking::parkVehicle() {
    int choice = m_vehicleMenu;
    if (choice == 1) { //car
        cout << "Parking Car" << endl;
    } else if (choice == 2) { //motorcycle
        cout << "Parking Motorcycle" << endl;
    } else if (choice == 3) { //cancel
        cout << "Cancelled parking" << endl;
    } else { //error
        cout << "Vehicle menu error - unrecognizable option selected" << endl;
    }
}
void Parking::returnVehicle() {
    cout << "Returning Vehicle" << endl;
}
void Parking::listVehicles() {
    cout << "Listing Parked Vehicles" << endl;
}
bool Parking::closeParking() {
    cout << "Closing Parking" << endl;
    return true;
}
bool Parking::exitParking() {
    char answer[3];
    bool done = false;
    cout << "This will terminate the program!" << endl;
    cout << "Are you sure? (Y)es/(N)o: ";
    do {
        cin >> answer;
        if (cin.fail()) {
            cin.clear();
        } else if ((answer[0] == 'Y' || answer[0] == 'N' || answer[0] == 'y' || answer[0] == 'n') && answer[1] == '\0') {
            done = true;
        }
        if (!done) {
            cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
        }
        cin.ignore(1000, '\n');
    } while (!done);
    return (answer[0] == 'Y' || answer[0] == 'y');
}
bool Parking::loadData() {
    bool loaded = false;
    if (!isEmpty()) {
        cout << "loading data from " << m_fileName << endl;
        loaded = true;
    }
    return loaded;
}
void Parking::saveData() {
    if (!isEmpty()) {
        cout << "Saving data into " << m_fileName << endl;
    }
}
}