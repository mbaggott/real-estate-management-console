//
// residential.h
//
// derived class
//

#ifndef __RESIDENTIAL_H__
#define __RESIDENTIAL_H__

#include <typeinfo>
#include "property.h"


int validateBedrooms(int bedrooms);

class Residential : virtual public Property
{
protected:
  int bedrooms;

public:
   Residential(); // Default constructor
   Residential(string theEmpID, string theOwner, string theAddress,
         string theSuburb, int thePostcode, int theBedrooms); // Constructor
   virtual ~Residential() ; // Destructor
    Residential(const Residential &residential); // Copy constructor
   void input() ;   // Data input for a Residential object
   void print() ;  // Data output for a Residential object
   bool isProperty(Property &property); // Determine type of object

   int getBedrooms() const;   // Getter, const prevents modification of object

   void setBedrooms(int theBedrooms); // Setter

};

#endif
