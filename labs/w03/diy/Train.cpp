/***********************************************************************
// OOP244 Workshop 3 diy:
// File Train.cpp
// Version 1.0
// Date 2020/02/05
// Author Pat Zdanko
// Student ID 129430195
// Section NAA
// Description
// Header function with the prototypes for functions in Train.cpp
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS

#include "Train.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{

void Train::setTrain(const char *setName, int setID)
{
    //checks if data values are invalid and sets default values, or else data is valid
    if (!setName || setID < 1 || setName[0] == '\0')
    {
        m_id = 0;
        m_name[0] = '\0';
    }
    else
    {
        strcpy(m_name, setName);
        m_id = setID;
    }

    // sets m_cargo to nullptr regardless of status
    m_cargo = nullptr;
}

bool Train::isEmpty() const
{
    //assumes train is not empty
    bool emptyTest = false;

    //tests if train is empty
    if (m_id < 1 || m_name[0] == 0)
    {
        emptyTest = true;
    }

    return emptyTest;
}

void Train::display() const
{
    cout << "***Train Summary***" << endl;

    //if train is empty/invalid
    if (isEmpty())
    {
        cout << "This is an empty train." << endl;
    }

    //train must be not empty
    else
    {
        cout << "Name: " << m_name << " ID: " << m_id << endl;

        //if train has cargo or else if must not have cargo
        if (m_cargo)
        {
            m_cargo->display();
        }
        else
        {
            cout << "No cargo on this train." << endl;
        }
    }
}

void Train::loadCargo(Cargo setCargo)
{
    //dynamic allocated memory for cargo
    m_cargo = new Cargo;

    //copies new cargo to train's cargo
    m_cargo->load(setCargo);
}

void Train::unloadCargo()
{
    // deletes the allocated memory for cargo
    delete m_cargo;

    //sets cargo back to nullptr to indicate no cargo
    m_cargo = nullptr;
}

bool Train::swapCargo(Train &swapTrain)
{
    //by default swapCargo is assumed to fail
    bool swapSuccess = false;

    //checks if both cargos exist
    if (m_cargo != nullptr && swapTrain.m_cargo != nullptr)
    {
        //temp cargo variable to facilitate swpa
        Cargo* temp = swapTrain.m_cargo;
        swapTrain.m_cargo = m_cargo;
        m_cargo = temp;

        //deleting memory allocated to temp

        //indicates swap was successful
        swapSuccess = true;
    }

    //returns false unless if function activated
    return swapSuccess;
}

bool Train::increaseCargo(double incWeight)
{
    //assumes the function will fail
    bool incSuccess = false;

    //tests if this train has cargo
    if (m_cargo)
    {
        //moves to the cargo increase function and checks for return status
        incSuccess = m_cargo->increase(incWeight);
    }

    //returns the status of this function
    return incSuccess;
}

bool Train::decreaseCargo(double decWeight)
{
    //assumes the function will fail
    bool decSuccess = false;

    //tests if this train has cargo
    if (m_cargo)
    {
        //moves to the cargo decrease function and checks for return status
        decSuccess = m_cargo->decrease(decWeight);
    }

    //returns the status of this function
    return decSuccess;
}

void Cargo::init(const char *nDesc, double nWeight)
{

    //checks if new description is not too long
    if (strlen(nDesc) <= MAX_DESC)
    {
        strcpy(m_description, nDesc);
    }
    else
    {
        cout << "Invalid Train Description, must be shorter than" << endl;
    }

    //checks for proper weight or else defaults the weight to min_weight
    if (nWeight <= MAX_WEIGHT && nWeight >= MIN_WEIGHT)
    {
        m_weight = nWeight;
    }
    else
    {
        m_weight = MIN_WEIGHT;
    }
}

void Cargo::load(const Cargo &nCargo)
{
    //copies cargo from new cargo to this cargo
    strcpy(m_description, nCargo.m_description);
    m_weight = nCargo.m_weight;
}

void Cargo::display() const
{
    //displays this Cargo class's cargo
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Cargo: " << m_description << " Weight: " << m_weight << endl;
}

bool Cargo::increase(double inc)
{
    //assumes failure
    bool incSuccess = false;

    //checks if weight can be increased
    if (m_weight < MAX_WEIGHT)
    {
        m_weight += inc;
        //if weight increase goes over max, edits weight to max
        if (m_weight > MAX_WEIGHT)
        {
            m_weight = MAX_WEIGHT;
        }
        //indicates the weight was editted succesfully
        incSuccess = true;
    }

    return incSuccess;
}

bool Cargo::decrease(double dec)
{
    //assumes failure
    bool decSuccess = false;

    //checks if weight can be decreased
    if ((m_weight - dec) > MIN_WEIGHT)
    {
        m_weight -= dec;

        decSuccess = true;
    }

    //returns status of function
    return decSuccess;
}

} // namespace sdds
