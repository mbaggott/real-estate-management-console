#ifndef __SALES_STAFF_H__
#define __SALES_STAFF_H__

#include <iostream>
#include <cstdlib>

#include "staff.h"

class SalesStaff: virtual public Staff {

   private:
      double commission;

   public:
      SalesStaff(); // Default constructor
      SalesStaff(string theEmpID, string theName, double theSalary,
         string theMobileNo, double theCommission);
      virtual ~SalesStaff(); // Destructor
      SalesStaff(const SalesStaff &salesStaff); // Copy constructor
      void input();
      void print();
      double getCommission() const; // Getter
      void setCommission(double newCommission); // Setter
};

#endif
