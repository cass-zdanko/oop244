/* Citation and Sources...
Final Project Milestone 5
Module: ReadWritable
Filename: ReadWritable.cpp
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
#include "ReadWritable.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace sdds {
ReadWritable::ReadWritable() {
    m_csvFlag = false;
}
bool ReadWritable::isCsv() const {
    return m_csvFlag;
}
void ReadWritable::setCsv(bool csvFlag) {
    m_csvFlag = csvFlag;
}
ostream& operator<<(ostream& os, const ReadWritable& rw) {
    return rw.write(os);
}
istream& operator>>(istream& is, ReadWritable& rw) {
    return rw.read(is);
}
}