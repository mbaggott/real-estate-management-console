//
// shop.h
//
// derived class
//

#ifndef __COMMERCIAL_H__
#define __COMMERCIAL_H__


#include "property.h"
#include <typeinfo>

class Commercial :  virtual public Property
{
protected:
  string license;

public:
   Commercial(); // Default constructor
   Commercial(string theEmpID, string theOwner, string theAddress,
         string theSuburb, int thePostcode, string theLicense); // Constructor
   virtual ~Commercial() ; // Destructor
   Commercial(const Commercial &commercial); // Copy constructor
   void input() ;   // Data input for a Commercial object
   void print() ;  // Data output for a Commercial object
   bool isProperty(Property&); // Determine type of object

   string getLicense() const;  // Getter, const prevents modification of object

   void setLicense(string theLicense); // Setter

};

#endif
