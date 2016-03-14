#ifndef __RES_RENTALS_H__
#define __RES_RENTALS_H__

#include "property.h"
#include "residential.h"
#include "rentals.h"
#include <typeinfo>

class ResRentals : public Residential, public Rentals {

   public:
      ResRentals(); // Default constructor
      ResRentals(string theEmpID, string theOwner, string theAddress,
            string theSuburb, int thePostcode, int theBedrooms, double theBond,
            double theMonthlyRent); // Constructor
      virtual ~ResRentals(); // Destructor
      ResRentals(const ResRentals &resrentals); // Copy constructor
      void input(); // Data input for a ResRentals object
      void print();// Data output for a ResRentals object
      bool isProperty(Property&); // Method to determine instance type of object

};

#endif
