#include "sales_staff.h"

/* Default  constructor */
SalesStaff::SalesStaff(): Staff(), commission(defaultDouble) {}

/* Destructor */
SalesStaff::~SalesStaff() {}

/* Constructor */
SalesStaff::SalesStaff(string theEmpID, string theName, double theSalary,
      string theMobileNo, double theCommission): Staff(theEmpID, theName,
      theSalary, theMobileNo), commission(theCommission) {}

/* Copy constructor */
SalesStaff::SalesStaff(const SalesStaff &salesStaff) {

   empID = salesStaff.empID;
   name = salesStaff.name;
   salary = salesStaff.salary;
   mobileNo = salesStaff.mobileNo;
   commission = salesStaff.commission;
}

/* Receives user input for object and configures instance variables */
void SalesStaff::input() {

   string input;
   bool valid = false;

   Staff::input();

   do {
      cout << "Input commission: ";
      cin >> input;

      try {
         commission = boost::lexical_cast<double>(input);
         if (isDouble(input)) {
            if (commission >= 0 && commission <= 100) {
               clearInputBuffer();
               valid = true;
            }
         }
         if (valid == false) {
            cout << endl << "Please enter a valid percentage (1 - 100)!"
                 << endl;
         }
      }
      catch (boost::bad_lexical_cast &c) {
         cout << endl << "Please enter a valid percentage (1 - 100)!" << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   }
   while (!valid);

}

/* Outputs details of object to screen */
void SalesStaff::print() {

   Staff::print();

   locale comma_locale(locale(), new Comma_Numpunct());
   cout.imbue(comma_locale);
   cout << "Commission: %" << setprecision(2) << fixed << commission << endl;
   locale global(locale("C"));
   cout.imbue(global);
}

/* *** GETTERS *** */

double SalesStaff::getCommission() const {
   return commission;
}

/* *** SETTERS *** */

void SalesStaff::setCommission(double newCommission) {
   commission = newCommission;
}
