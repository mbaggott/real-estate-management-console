#include "res_sales.h"

/* Default constructor */
ResSales::ResSales() {}

/* Destructor */
ResSales::~ResSales() {}

/* Constructor */
ResSales::ResSales(string theEmpID, string theOwner, string theAddress,
      string theSuburb, int thePostcode, int theBedrooms, string theAuctionDate,
      double thePrice): Property(theEmpID, theOwner, theAddress, theSuburb,
      thePostcode), Residential(theEmpID, theOwner, theAddress, theSuburb,
      thePostcode, theBedrooms), Sales(theEmpID, theOwner, theAddress,
      theSuburb, thePostcode, theAuctionDate, thePrice) {
}

/* Copy constructor */
ResSales::ResSales(const ResSales &ressales) {

   owner = ressales.owner;
   address = ressales.address;
   suburb = ressales.suburb;
   postcode = ressales.postcode;
   bedrooms = ressales.bedrooms;
   auctionDate = ressales.auctionDate;
   price = ressales.price;

}

/* Method to accept user input and set member variables */
void ResSales::input() {

   int theBedrooms;
   bool valid = false;

   Sales::input();

   do {
      cout << "Input number of bedrooms: ";
      cin >> theBedrooms;

      if (cin.good()) {
         bedrooms = theBedrooms;
         valid = true;
         clearInputBuffer();
      }

      else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Please enter a valid integer!" << endl;
      }
   }
   while (!valid);

}

/* Method to output details of object to screen */
void ResSales::print() {

   Sales::print();

   cout << "Bedrooms: " << bedrooms << endl;
   cout << "\n";

}

/* Method to determine instance type of object */
bool ResSales::isProperty(Property &property) {

   try {
      ResSales res = dynamic_cast<ResSales&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
