#include "rentals.h"

/* Default constructor */
Rentals::Rentals(): bond(defNum), monthlyRent(defNum) {}

/* Destructor */
Rentals::~Rentals() {}

/* Constructor */
Rentals::Rentals(string theEmpID, string theOwner, string theAddress,
         string theSuburb, int thePostcode, double theBond,
         double theMonthlyRent): Property(theEmpID, theOwner, theAddress,
         theSuburb, thePostcode) {
         bond = theBond;
         monthlyRent = theMonthlyRent;
}

/* Copy constructor */
Rentals::Rentals(const Rentals &rentals) {

   owner = rentals.owner;
   address = rentals.address;
   suburb = rentals.suburb;
   postcode = rentals.postcode;
   bond = rentals.bond;
   monthlyRent = rentals.monthlyRent;

}

/* *** GETTERS *** */

double Rentals::getBond() const {
   return bond;
}

double Rentals::getMonthlyRent() const {
   return monthlyRent;
}

/* *** SETTERS *** */

void Rentals::setBond(double theBond) {
   bond = theBond;
}

void Rentals::setMonthlyRent(double theMonthlyRent) {
   monthlyRent = theMonthlyRent;
}

/* Method to accept user input and set member variables */
void Rentals::input() {

   double theBond, theMonthlyRent;
   bool valid = false;

   Property::input();

   do {

      cout << "Input bond amount: ";
      cin >> theBond;

      if(cin.good()) {
         bond = theBond;
         valid = true;
         clearInputBuffer();
      }

      else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Please enter a valid floating point number!" << endl;
      }

   }
   while(!valid);

   valid = false;

   do {

      cout << "Input the monthly rent amount: ";
      cin >> theMonthlyRent;

      if(cin.good()) {
         monthlyRent = theMonthlyRent;
         valid = true;
         clearInputBuffer();
      }

      else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Please input a valid floating point number!" << endl;
      }

   } while (!valid);
}

/* Method to output details of object to screen */
void Rentals::print() {

   Property::print();

   locale comma_locale(locale(), new Comma_Numpunct());
   cout.imbue(comma_locale);
   cout << "Bond amount: $" << setprecision(2) << fixed << bond << endl;
   cout << "Monthly rent: $" << setprecision(2) << fixed << monthlyRent << endl;
   locale global(locale("C"));
   cout.imbue(global);
}

/* Method to determine instance type of object */
bool Rentals::isProperty(Property &property) {

   try {
      Rentals res = dynamic_cast<Rentals&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
