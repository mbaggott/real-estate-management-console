#ifndef __RES_SALES_H__
#define __RES_SALES_H___

#include "property.h"
#include "residential.h"
#include "sales.h"
#include <typeinfo>

class ResSales : public Residential, public Sales {

   public:
      ResSales(); // Default constructor
      ResSales(string theEmpID, string theOwner, string theAddress,
            string theSuburb, int thePostcode, int theBedrooms,
            string theAuctionDate, double thePrice); // Constructor
      virtual ~ResSales(); // Destructor
      ResSales(const ResSales &ressales); // Copy constructor
      void input(); // Data input for a ResSales object
      void print(); // Data output for a ResSales object
      bool isProperty(Property&); // Method to determine instance type of object

};

#endif
