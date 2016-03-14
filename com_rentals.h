#ifndef __COM_RENTALS_H__
#define __COM_RENTALS_H__

#include "property.h"
#include "commercial.h"
#include "rentals.h"
#include <typeinfo>

class ComRentals : public Commercial, public Rentals {

   public:
      ComRentals(); // Default constructor
      ComRentals(string theEmpID, string theOwner, string theAddress,
            string theSuburb, int thePostcode, string theLicense,
            double theBond, double theMonthlyRent); // Constructor
      virtual ~ComRentals(); // Destructor
      ComRentals(const ComRentals &comrentals); // Copy constructor
      void input(); // Data input for a ComRentals object
      void print(); // Data output for a ComRentals object
      bool isProperty(Property&); // Method to determine instance type of object

};

#endif
