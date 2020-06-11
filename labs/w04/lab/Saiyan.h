/***********************************************************************
// OOP244 Workshop 3: 
// File Train.h
// Version 1.0
// Date 2020/02/07
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
    const int MAX_DOB = 2020;
    const int MAX_NAME = 30;

    class Saiyan
    {
        char m_name[MAX_NAME + 1];
        int m_dob;
        int m_power;
        bool m_super;

    public:
        Saiyan();
        Saiyan(const char* name, int dob, int power, bool super = false);
        bool isSuper() const;
        bool isValid() const;
        void setEmpty();
        void display() const;
        void set(const char* name, int dob, int power, bool super = false);
        bool hasLost(const Saiyan other) const;
    };

} // namespace sdds

#endif // !SDDS_SAIYAN_H__
