#ifndef __COM_SALES_H__
#define __COM_SALES_H__

#include "property.h"
#include "commercial.h"
#include "sales.h"
#include <typeinfo>

class ComSales : public Commercial, public Sales {

   public:
      ComSales(); // Default constructor
      ComSales(string theEmpID, string theOwner, string theAddress,
            string theSuburb, int thePostcode, string theLicense,
            string theAuctionDate, double thePrice); // Constructor
      virtual ~ComSales(); // Destructor
      ComSales(const ComSales &comsales); // Copy constructor
      void input(); // Data input for a ComSales object
      void print(); // Data output for a ComSales object
      bool isProperty(Property&); // Method to determine instance type of object

};

#endif
