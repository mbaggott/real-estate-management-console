//
// sales.h
//
// derived class
//

#ifndef __SALES_H__
#define __SALES_H__


#include "property.h"
#include "utility1.h"
#include <typeinfo>

class Sales :  virtual public Property
{
protected:
  string auctionDate;
  double price;

public:
   Sales(); // Default constructor
   Sales(string theEmpID, string theOwner, string theAddress, string theSuburb,
         int thePostcode, string theAuctionDate, double thePrice); // Cnstructor
   virtual ~Sales(); // Destructor
   Sales(const Sales &sales); // Copy constructor
   void input() ;   // Data input for a Sales object
   void print() ;  // Data output for a Sales object
   bool isProperty(Property&);  // Determine type of object

   string getAuctionDate() const;  // Getter, const prevents  object
   double getPrice() const; // Getter, const prevents modification of object

   virtual void setAuctionDate(string theAuctionDate); // Setter
   virtual void setPrice(double thePrice); // Setter


};

#endif
