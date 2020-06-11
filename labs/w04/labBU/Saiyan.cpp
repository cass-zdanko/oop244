/***********************************************************************
// OOP244 Workshop 3: 
// File Train.h
// Version 1.0
// Date 2020/01/31
// Author Pat Zdanko
// Student ID 129430195
// Section NAA
// Description
// Code that holds the information for an alien race known as Saiyans.
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Saiyan.h"

#include <cstring>
#include <iostream>

using namespace std;

namespace sdds
{

Saiyan::Saiyan()
{
    m_name[0] = '\0';
    m_dob = MAX_DOB;
    m_power = 0;
    m_super = false;
}
Saiyan::Saiyan(const char* name, int dob, int power, bool super = false)
{
    if (name && name[0] != '\0' && strlen(name) < MAX_NAME && (dob < MAX_DOB) && power > 0)
    {
        strcpy(m_name, name);
        m_dob = dob;
        m_power = power;
        m_super = super;
    }
    else {
        setEmpty();
    }
}
bool Saiyan::isSuper() const
{
    return m_super;
}
bool Saiyan::isValid() const
{

    //assumes false
    bool valid = false;

    //checks if true
    if (m_name[0] != '\0' && (m_dob < MAX_DOB) && m_power > 0)
    {
        valid = true;
    }

    return valid;
}
void Saiyan::setEmpty()
{
    m_name[0] = '\0';
    m_dob = MAX_DOB;
    m_power = 0;
    m_super = false;
}
void Saiyan::display() const
{
    if (isValid)
    {
        cout << m_name << endl;
        cout << "DOB: " << m_dob << " Power: " << m_power << endl;
        cout << "Super Saiyan Ability: ";
        if (m_super)
        {
            cout << "Super Saiyan." << endl;
        }
        else
        {
            cout << "Not super Saiyan." << endl;
        }
        cout << endl;
  
    }
    else {
        cout << "Invali Saiyan!" << endl;
    }
}
void Saiyan::set(const char* name, int dob, int power, bool super = false)
{
    if (name && name[0] != '\0' && strlen(name) < MAX_NAME && (dob < MAX_DOB) && power > 0)
    {
        strcpy(m_name, name);
        m_dob = dob;
        m_power = power;
        m_super = super;
    }
    else {
        setEmpty();
    }

}
bool Saiyan::hasLost(const Saiyan other) const
{
    return (m_power > other.m_power);
}

} // namespace sdds