/* Citation and Sources...
Final Project Milestone 4
Module: ReadWritable
Filename: ReadWritable.h
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
#ifndef SDDS_READWRITABLE_H__
#define SDDS_READWRITABLE_H__

#include <iostream>
using namespace std;

namespace sdds {
class ReadWritable {
    bool m_csvFlag; //comma seperate value flag

public:
    ReadWritable();
    bool isCsv() const;
    void setCsv(bool csvFlag);
    virtual ostream& write(ostream& os) const = 0;
    virtual istream& read(istream& is) = 0;
    virtual ~ReadWritable() {}
};
ostream& operator<<(ostream& os, const ReadWritable& rw);
istream& operator>>(istream& is, ReadWritable& rw);
}

#endif