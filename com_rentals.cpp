#include "com_rentals.h"

/* Default constructor */
ComRentals::ComRentals() {}

/* Destructor */
ComRentals::~ComRentals() {}

/* Constructor */
ComRentals::ComRentals(string theEmpID, string theOwner, string theAddress,
      string theSuburb, int thePostcode, string theLicense, double theBond,
      double theMonthlyRent): Property(theEmpID, theOwner, theAddress,
      theSuburb, thePostcode), Commercial(theEmpID, theOwner, theAddress,
      theSuburb, thePostcode, theLicense), Rentals(theEmpID, theOwner,
      theAddress, theSuburb, thePostcode, theBond, theMonthlyRent) {
}

/* Copy constructor */
ComRentals::ComRentals(const ComRentals &comrentals) {

   owner = comrentals.owner;
   address = comrentals.address;
   suburb = comrentals.suburb;
   postcode = comrentals.postcode;
   license = comrentals.license;
   bond = comrentals.bond;
   monthlyRent = comrentals.monthlyRent;

}

/* Method to accept user input and set member variables */
void ComRentals::input() {

   string theLicense;

   Rentals::input();

   cout << "Input license details: ";
   getline(cin, theLicense);

   license = theLicense;

}

/* Method to output details of object to screen */
void ComRentals::print() {

   Rentals::print();

   cout << "License details: " << license << endl;
   cout << "\n";

}

/* Method to determine instance type of object */
bool ComRentals::isProperty(Property &property) {

   try {
      ComRentals res = dynamic_cast<ComRentals&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
