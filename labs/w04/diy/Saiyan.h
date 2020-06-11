/***********************************************************************
// OOP244 Workshop 4 
// File Train.h
// Version 1.0
// Date 2020/02/12
// Author Pat Zdanko
// Student ID 129430195
// Section NAA
// Description
// Header file for Saiyan.cpp
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#pragma once
#ifndef SDDS_SAIYAN_H__
#define SDDS_SAIYAN_H__

namespace sdds
{
    // assignment states DOB must be less than 2020
    const int MAX_DOB = 2020;

    class Saiyan
    {
        char* m_name;
        int m_size;
        int m_dob;
        int m_power;
        int m_level;
        bool m_super;

    public:
        Saiyan();
        Saiyan(const char* name, int dob, int power, int level = 0, bool super = false);
        Saiyan(const Saiyan& S);
        ~Saiyan();
        bool isSuper() const;
        bool isValid() const;
        void setEmpty();
        void display() const;
        void set(const char* name, int dob, int power, int level = 0, bool super = false);
        bool hasLost(Saiyan other);
        void powerup();
    };

} // namespace sdds

#endif // !SDDS_SAIYAN_H__
