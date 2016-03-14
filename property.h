//
// property_a.h
//
// Parent Property class
//

#ifndef __PROPERTY_H__
#define __PROPERTY_H__


/* REQUIRED HEADER FILES AND NAMESPACES */
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <limits>

using namespace std;

int validatePostcode(int postcode);

/* Constants */
const static int SUCCESS = 1;
const static int FAILURE = 0;
const static string defString = "";
const static int defNum = 0;

class Property
{
   protected:
      string empID;
      string owner;
      string address;
      string suburb;
      int postcode;

   public:
      Property(); // Default constructor
      Property(string theEmpID, string theOwner, string theAddress,
            string theSuburb, int thepostCode); // Constructor
      virtual ~Property() ; // Destructor
      Property(const Property &property); // Copy constructor
      string toString();
      bool operator< (Property &prop2);

      /* Functions changed to pure virtual for Task C, to allow for polymorphic
      print() and input() functions. */
      virtual void input() = 0;   // Data input for a Property object
      virtual void print() = 0;  // Data output for a Property object

      string getOwner() const;  // Getter, const stops modification of object
      string getAddress() const; // Getter, const stops modification of object
      string getSuburb() const; // Getter, const stops modification of object
      int getPostcode() const; // Getter, const stops modification of object
      string getEmpID() const; // Getter, const stops modification of object

      void setOwner(string newOwner); // Setter
      void setAddress(string newAddress); // Setter
      void setSuburb( string  newSuburb); // Setter
      void setPostcode(int  newPostcode); // Setter
      void setEmpID(string newEmpID); //Setter

      // Function added for Task C determines instance type of object
      virtual bool isProperty(Property&) = 0;

      friend ostream& operator<<(ostream& os, Property &prop); // Override <<
      friend istream& operator>>(istream& in, Property &prop); // Override >>

};

#endif
