#include "residential.h"
#include "utility1.h"

/* Default constructor */
Residential::Residential(): bedrooms(defNum)  {}

/* Destructor */
Residential::~Residential() {}

/* Constructor */
Residential::Residential(string theEmpID, string theOwner, string theAddress,
      string theSuburb, int thePostcode, int theBedrooms):
      Property(theEmpID, theOwner, theAddress, theSuburb, thePostcode) {
      bedrooms = theBedrooms;
}

/* Copy constructor */
Residential::Residential(const Residential &residential) {

   owner = residential.owner;
   address = residential.address;
   suburb = residential.suburb;
   postcode = residential.postcode;
   bedrooms = residential.bedrooms;

}

/* *** GETTERS *** */

int Residential::getBedrooms() const {
   return bedrooms;
}

/* *** SETTERS *** */

void Residential::setBedrooms(int theBedrooms) {

   bedrooms = theBedrooms;
}

/* Method to accept user input and set member variables */
void Residential::input() {

   int theBedrooms;
   bool valid = false;

   Property::input();

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
void Residential::print() {

   Property::print();

   cout << "Bedrooms: " << bedrooms << endl;
}

/* Method to determine instance type of object */
bool Residential::isProperty(Property &property) {

   try {
      Residential res = dynamic_cast<Residential&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
