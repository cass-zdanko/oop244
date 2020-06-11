/***********************************************************************
// OOP244 Workshop 3 diy: 
// File Train.h
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

#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
const int MAX_NAME = 30;
const int MAX_DESC = 20;
const double MAX_WEIGHT = 700.555;
const double MIN_WEIGHT = 40.444;

class Cargo
{
    char m_description[MAX_DESC + 1];
    double m_weight;

public:
    void init(const char *, double);
    void load(const Cargo &);
    void display() const;
    bool increase(double);
    bool decrease(double);
};

class Train
{
    char m_name[MAX_NAME + 1];
    int m_id;
    Cargo* m_cargo;

public:
    void setTrain(const char *, int);
    bool isEmpty() const;
    void display() const;
    void loadCargo(Cargo);
    void unloadCargo();
    bool swapCargo(Train &);
    bool increaseCargo(double);
    bool decreaseCargo(double);
};

} // namespace sdds

#endif