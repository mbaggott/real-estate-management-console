#include "com_sales.h"

/* Default constructor */
ComSales::ComSales() {}

/* Destructor */
ComSales::~ComSales() {}

/* Constructor */
ComSales::ComSales(string theEmpID, string theOwner, string theAddress,
      string theSuburb, int thePostcode, string theLicense,
      string theAuctionDate, double thePrice): Property(theEmpID, theOwner,
      theAddress, theSuburb, thePostcode), Commercial(theEmpID, theOwner,
      theAddress, theSuburb, thePostcode, theLicense), Sales(theEmpID, theOwner,
      theAddress, theSuburb, thePostcode, theAuctionDate, thePrice) {
}

/* Copy constructor */
ComSales::ComSales(const ComSales &comsales) {

   owner = comsales.owner;
   address = comsales.address;
   suburb = comsales.suburb;
   postcode = comsales.postcode;
   license = comsales.license;
   auctionDate = comsales.auctionDate;
   price = comsales.price;

}

/* Method to accept user input and set member variables */
void ComSales::input() {

   string theLicense;

   Sales::input();

   cout << "Input license details: ";
   getline(cin, theLicense);

   license = theLicense;

}

/* Method to output details of object to screen */
void ComSales::print() {

   Sales::print();

   cout << "License details: " << license << endl;
   cout << "\n";

}

/* Method to determine instance type of object */
bool ComSales::isProperty(Property &property) {

   try {
      ComSales res = dynamic_cast<ComSales&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
