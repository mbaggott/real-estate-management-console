#include "res_rentals.h"

/* Default constructor */
ResRentals::ResRentals() {}

/* Destructor */
ResRentals::~ResRentals() {}

/* Constructor */
ResRentals::ResRentals(string theEmpID, string theOwner, string theAddress,
      string theSuburb, int thePostcode, int theBedrooms, double theBond,
      double theMonthlyRent): Property(theEmpID, theOwner, theAddress,
      theSuburb, thePostcode), Residential(theEmpID, theOwner, theAddress,
      theSuburb, thePostcode, theBedrooms), Rentals(theEmpID, theOwner,
      theAddress, theSuburb, thePostcode, theBond, theMonthlyRent) {
}

/* Copy constructor */
ResRentals::ResRentals(const ResRentals &resrentals) {

   owner = resrentals.owner;
   address = resrentals.address;
   suburb = resrentals.suburb;
   postcode = resrentals.postcode;
   bedrooms = resrentals.bedrooms;
   bond = resrentals.bond;
   monthlyRent = resrentals.monthlyRent;

}

/* Method to accept user input and set member variables */
void ResRentals::input() {

   int theBedrooms;
   bool valid = false;

   Rentals::input();

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
void ResRentals::print() {

   Rentals::print();

   cout << "Bedrooms: " << bedrooms << endl;
   cout << "\n";

}

/* Method to determine instance type of object */
bool ResRentals::isProperty(Property &property) {

   try {
      ResRentals res = dynamic_cast<ResRentals&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
