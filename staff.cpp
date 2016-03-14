#include "staff.h"

/* Default constructor */
Staff::Staff(): empID(defaultString), name(defaultString),
      salary(defaultDouble), mobileNo(defaultString)  {}

/* Destructor */
Staff::~Staff() {}

/* Constructor */
Staff::Staff(string theEmpID, string theName, double theSalary,
      string theMobileNo):empID(theEmpID), name(theName), salary(theSalary),
      mobileNo(theMobileNo) { }

/* Copy constructor */
Staff::Staff(const Staff &staff) {
   empID = staff.empID;
   name = staff.name;
   salary = staff.salary;
   mobileNo = staff.mobileNo;
}

   /* Method to accept user input and set member variables */
void Staff::input() {

   string theName, theMobileNo;
   bool valid = false;
   string input;

   cout << "\n";

   do {
      cout << "Input employee ID: ";
      getline(cin, input);

      if (validateID(input)) {
         valid = true;
         empID = input;

      }
      else {
         cout << endl << "Please enter a valid employee ID (eXX)" << endl;
      }
   }
   while (!valid);

   cout << "Input name: ";
   getline(cin, name);

   cout << "Input mobile number: ";
   getline(cin, mobileNo);

   valid = false;
   do {
      cout << "Input salary: ";
      cin >> input;

      try {
         salary = boost::lexical_cast<double>(input);
         if (isDouble(input)) {
            clearInputBuffer();
            valid = true;
         }
      }
      catch (boost::bad_lexical_cast &c) {
         cout << endl << "Please enter a valid salary amount!" << endl << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   }
   while (!valid);
}

/* Method to output object information to screen */
void Staff::print() {

   cout << "\n";
   cout << "Employee ID: " << empID << endl;
   cout << "Name: " << name << endl;
   locale comma_locale(locale(), new Comma_Numpunct());
   cout.imbue(comma_locale);
   cout << "Salary: $" << setprecision(2) << fixed << salary << endl;
   locale global(locale("C"));
   cout.imbue(global);
   cout << "Mobile Number: " << mobileNo << endl;

}

bool Staff::isStaff(Staff* staff) {
   if (dynamic_cast<Staff*>(staff)) {
      return true;
   }
   return false;
}

/* *** GETTERS *** */

string Staff::getEmpID() const {
   return empID;
}
string Staff::getName() const {
   return name;
}

double Staff::getSalary() const {
   return salary;
}

string Staff::getMobileNo() const {
   return mobileNo;
}

/* *** SETTERS *** */

void Staff::setEmpID(string newEmpID) {
   empID = newEmpID;
}

void Staff::setName(string newName) {
   name = newName;
}

void Staff::setSalary( double  newSalary) {
   salary = newSalary;
}

void Staff::setMobileNo(string  newMobileNo) {
   mobileNo = newMobileNo;
}

// Method to override use of << operator
ostream& operator<<(ostream& os, Staff &staff) {

   staff.print();

   return os;
}

// Method to override us of >> operator
istream& operator>>(istream& in, Staff &staff) {

   staff.input();

   return in;
}
