#include "rentals_staff.h"

/* Default  constructor */
RentalsStaff::RentalsStaff(): Staff(), bonus(defaultDouble) {}

/* Destructor */
RentalsStaff::~RentalsStaff() {}

/* Constructor */
RentalsStaff::RentalsStaff(string theEmpID, string theName, double theSalary,
      string theMobileNo, double theBonus): Staff(theEmpID, theName,
      theSalary, theMobileNo), bonus(theBonus) {}

/* Copy constructor */
RentalsStaff::RentalsStaff(const RentalsStaff &rentalsStaff) {

   empID = rentalsStaff.empID;
   name = rentalsStaff.name;
   salary = rentalsStaff.salary;
   mobileNo = rentalsStaff.mobileNo;
   bonus = rentalsStaff.bonus;
}

/* Gets input from user and configures instance variables */
void RentalsStaff::input() {

   string input;
   bool valid = false;

   Staff::input();

   do {
      cout << "Input bonus amount: ";
      cin >> input;

      try {
         bonus = boost::lexical_cast<double>(input);
         if (isDouble(input)) {
            clearInputBuffer();
            valid = true;
         }
      }
      catch (boost::bad_lexical_cast &c) {
         cout << endl << "Please enter a valid dollar amount" << endl
              << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   }
   while (!valid);

}

/* Outputs object properties to screen */
void RentalsStaff::print() {

   Staff::print();

   locale comma_locale(locale(), new Comma_Numpunct());
   cout.imbue(comma_locale);
   cout << "Bonus: $" << setprecision(2) << fixed << bonus << endl;
   locale global(locale("C"));
   cout.imbue(global);
}

/* *** GETTERS *** */

double RentalsStaff::getBonus() const {
   return bonus;
}

/* *** SETTERS *** */

void RentalsStaff::setBonus(double newBonus) {
   bonus = newBonus;
}
