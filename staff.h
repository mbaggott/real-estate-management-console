//
// staff.h
//
// Parent staff class
//

#ifndef __STAFF_H__
#define __STAFF_H__


/* HEADER FILES AND NAMESPACES*/
#include <iostream>
#include <string>
#include <iomanip>
#include "utility1.h"
#include "boost/lexical_cast.hpp"

using namespace std;
using namespace boost;

/* Constants */
static const string defaultString = "";
static const double defaultDouble = 0.0;

class Staff
{
   protected:
   string empID;
   string name;
   double salary;
   string mobileNo;

   public:
   Staff();
   Staff(string theEmpID, string theName, double theSalary, string theMobileNo);
   virtual ~Staff() ;
   virtual void input() = 0 ;   // Data input for a Staff object
   virtual void print() = 0 ;  // Data output for a Staff object
   Staff(const Staff &staff); // Copy constructor
   friend istream& operator>>(istream& in, Staff &staff);
   friend ostream& operator<<(ostream& os, Staff &staff);
   virtual bool isStaff(Staff* staff);

   string getEmpID() const; // Getter
   string getName() const; // Getter
   double getSalary() const; // Getter
   string getMobileNo() const; // Getter

   void setEmpID(string newEmpID); // Setter
   void setName(string newName); // Setter
   void setSalary( double  newSalary); // Setter
   void setMobileNo(string  newMobileNo); // Setter
};

#endif
