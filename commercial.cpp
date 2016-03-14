#include "commercial.h"

/* Default constructor */
Commercial::Commercial(): license(defString) {}

/* Destructor */
Commercial::~Commercial() {}

/* Constructor */
Commercial::Commercial(string theEmpID, string theOwner, string theAddress,
      string theSuburb, int thePostcode, string theLicense): Property(theEmpID,
      theOwner, theAddress, theSuburb, thePostcode) {
         license = theLicense;
}

/* Copy constructor */
Commercial::Commercial(const Commercial &commercial) {
   owner = commercial.owner;
   address = commercial.address;
   suburb = commercial.suburb;
   postcode = commercial.postcode;
   license = commercial.license;
}

/* *** GETTERS *** */

string Commercial::getLicense() const {
   return license;
}

/* *** SETTERS *** */

void Commercial::setLicense(string theLicense) {
   license = theLicense;
}

/* Method to accept user input and set member variables */
void Commercial::input() {

   string theLicense;

   Property::input();

   cout << "Input license details: ";
   getline(cin, theLicense);

   license = theLicense;
}

/* Method to output details of object to screen */
void Commercial::print() {

   Property::print();

   cout << "License details: " << license << endl;

}

/* Method to determine instance type of object */
bool Commercial::isProperty(Property &property) {

   try {
      Commercial res = dynamic_cast<Commercial&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
