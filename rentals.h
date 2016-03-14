//
// rentals.h
//
// derived class
//

#ifndef __RENTALS_H__
#define __RENTALS_H__


#include "property.h"
#include "utility1.h"
#include <typeinfo>

class Rentals : virtual public Property
{
protected:
  double bond;
  double monthlyRent;

public:
   Rentals(); // Default constructor
   Rentals(string theEmpID, string theOwner, string theAddress,
         string theSuburb, int thePostcode, double theBond,
         double theMonthlyRent); // Constructor
   virtual ~Rentals(); // Destructor
   Rentals(const Rentals &rentals); // Copy constructor
   void input();   // Data input for a Rentals object
   void print();  // Data output for a Rentals object
   bool isProperty(Property&); // Determine type of object

   double getBond() const; // Getter, const prevents modification of object
   double getMonthlyRent() const;  // Getter, const ztops modification of object

   void setBond(double theBond); // Setter
   void setMonthlyRent(double theMonthlyRent); // Setter


};

#endif
