/***********************************************************************
// OOP244 Workshop 4
// File Train.h
// Version 1.0
// Date 2020/02/12
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
        setEmpty();
    }
    Saiyan::Saiyan(const char* name, int dob, int power, int level, bool super)
    {
        setEmpty();

        //checks if values are valid and then sets them
        if (name && name[0] != '\0' && (dob < MAX_DOB) && power > 0 && level >= 0)
        {
            m_size = strlen(name);
            m_name = new char[m_size + 1];
            strcpy(m_name, name);
            m_dob = dob;
            m_power = power;
            m_level = level;
            m_super = super;
        }
    }
    Saiyan::Saiyan(const Saiyan& S)
    {
        setEmpty();

        //checks if values are valid and then sets them
        if (S.m_name && S.m_name[0] != '\0' && (S.m_dob < MAX_DOB) && S.m_power > 0 && S.m_level >= 0)
        {
            m_size = strlen(S.m_name);
            m_name = new char[m_size + 1];
            strcpy(m_name, S.m_name);
            m_dob = S.m_dob;
            m_power = S.m_power;
            m_level = S.m_level;
            m_super = S.m_super;
        }
    }
    Saiyan::~Saiyan()
    {
        delete[] m_name;
        m_name = nullptr;
        
    }
    bool Saiyan::isSuper() const
    {
        return m_super;
    }
    bool Saiyan::isValid() const
    {
        //assumes false
        bool valid = false;

        //checks if Saiyan is not empty state
        if (m_name && (m_dob < MAX_DOB) && m_power > 0)
        {
            valid = true;
        }

        return valid;
    }
    void Saiyan::setEmpty()
    {
        //empty state valies
        m_name = nullptr;
        m_size = 0;
        // assignment states dob must be less than 2020, so 2020 is a safe empty value
        m_dob = MAX_DOB;
        m_power = 0;
        m_level = 0;
        m_super = false;
    }
    void Saiyan::display() const
    {
        if (isValid())
        {
            cout << m_name << endl;
            cout << "DOB: " << m_dob << " Power: " << m_power << endl;
            cout << "Super Saiyan Ability: ";
            if (m_super)
            {
                cout << "Super Saiyan." << endl;
                cout << "Super Saiyan level is: " << m_level << endl;
            }
            else
            {
                cout << "Not super Saiyan." << endl;
                cout << endl;
            }
        }
        else
        {
            cout << "Invalid Saiyan!" << endl;
        }
    }
    void Saiyan::set(const char* name, int dob, int power, int level, bool super)
    {
        //clears previous dynamic memory
        delete[] m_name;
        setEmpty();
        
        //checks if values are valid and then sets them
        if (name && name[0] != '\0' && (dob < MAX_DOB) && power > 0 && level >= 0)
        {
            m_size = strlen(name);
            m_name = new char[m_size + 1];
            strcpy(m_name, name);
            m_dob = dob;
            m_power = power;
            m_level = level;
            m_super = super;
        }

    }
    bool Saiyan::hasLost(Saiyan other)
    {
        powerup();
        other.powerup();
        
        // In case of tie, this saiyan loses. This is based on
        // the interpretation of the pdf:
        /* "A battle is won when the power of the current objects 
        exceeds the power of the other object." */
        // Since the "current object" must exceed to win, a tie is 
        // a loss for the current object
        return (m_power <= other.m_power);
    }

    void Saiyan::powerup()
    {
        // since the assignment does not specify, it is
        // assumed powerup permanently changes the power level
        if (isSuper()) {
            m_power *= (m_level + 1);
        }
    }

} // namespace sdds