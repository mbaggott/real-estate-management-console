#ifndef __RENTALS_STAFF_H__
#define __RENTALS_STAFF_H__

#include <iostream>
#include <cstdlib>
#include "staff.h"

class RentalsStaff: virtual public Staff {

   private:
      double bonus;

   public:
      RentalsStaff(); // Default constructor
      RentalsStaff(string theEmpID, string theName, double theSalary,
         string theMobileNo, double theBonus);
      virtual ~RentalsStaff(); // Destructor
      RentalsStaff(const RentalsStaff &rentalsStaff); // Copy constructor
      void input();
      void print();
      double getBonus() const; // Getter
      void setBonus(double newBonus); // Setter
};

#endif
