#include "property.h"
#include "utility1.h"

/* Default constructor */
Property::Property(): empID(defString), owner(defString), address(defString),
   suburb(defString), postcode(defNum) {}

/* Destructor */
Property::~Property() {}

/* Constructor */
Property::Property(string theEmpID, string theOwner, string theAddress,
      string theSuburb, int thePostcode) {
         owner = theOwner;
         address = theAddress;
         suburb = theSuburb;
         postcode = thePostcode;

         if (validateID(theEmpID)) {
            empID = theEmpID;
         }
         else {
            cout << "Error...employee ID must be (eXX), exiting!\n";
            exit(EXIT_FAILURE);
         }

         if (validatePostcode(thePostcode)) {
            postcode = thePostcode;
         }
         else {
            cout << "Error...postcode must be (0001 - 9999), exiting!\n";
            exit(EXIT_FAILURE);
         }
}

/* Copy constructor */
Property::Property(const Property &property) {
   empID = property.empID;
   owner = property.owner;
   address = property.address;
   suburb = property.suburb;
   postcode = property.postcode;
}

/* *** GETTERS *** */

string Property::getOwner() const {
   return owner;
}

string Property::getAddress() const {
   return address;
}

string Property::getSuburb() const {
   return suburb;
}

int Property::getPostcode() const {
   return postcode;
}

string Property::getEmpID() const {
   return empID;
}

/* *** SETTERS *** */

void Property::setOwner(string newOwner){
   owner = newOwner;
}

void Property::setAddress(string newAddress){
   address = newAddress;
}

void Property::setSuburb(string newSuburb) {
   suburb = newSuburb;
}

void Property::setPostcode(int newPostcode) {

   if (validatePostcode(newPostcode)) {
      postcode = newPostcode;
   }
   else {
      cout  << "Error...employee ID must be (eXX), exiting!\n!" << endl;
      exit(EXIT_FAILURE);
   }
}

void Property::setEmpID(string newEmpID) {

   if (validateID(newEmpID)) {
      empID = newEmpID;
   }
   else {
      cout  << "Error...postcode must be (0001 - 9999), exiting!" << endl;
      exit(EXIT_FAILURE);
   }

}

/* Method to accept user input and set member variables */
void Property::input() {

   string theOwner, theAddress, theSuburb, theEmpID;
   int thePostcode;
   bool valid = false;

   cout << "\n";

   while (!valid) {
      cout << "Input Employee ID: ";
      getline(cin, theEmpID);
      if (validateID(theEmpID)) {
         valid = true;
         empID = theEmpID;
      }
      else {
         cout << endl << "Please enter a valid employee ID (eXX)!" << endl
              << endl;
      }
   }

   cout << "Input name: ";
   getline(cin, theOwner);

   cout << "Input address: ";
   getline(cin, theAddress);

   cout << "Input suburb: ";
   getline(cin, theSuburb);

   owner = theOwner;
   address = theAddress;
   suburb = theSuburb;

   valid = false;
   do {
      cout << "Input postcode: " << flush;
      cin >> thePostcode;

      if (cin.good() && validatePostcode(thePostcode)) {
         postcode = thePostcode;
         valid = true;
         clearInputBuffer();

      }
      else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Error, postcode must be a number (0001 - 9999)" << endl;
      }
   }
   while (!valid);

}

/* Method to output details of object to screen */
void Property::print() {

   cout << "\n";
   cout << "Employee ID: " << empID << endl;
   cout << "Name: " << owner << endl;
   cout << "Address:" << address << endl;
   cout << "Suburb: " << suburb << endl;
   cout << "Postcode: " << setfill('0') << setw(4) << postcode << endl;
}


/* Base method to determine instance type of object */
bool Property::isProperty(Property&) {
   return NULL;
}

/* To string function used for property set comparator */
string Property::toString() {

   string postcodeString;

   try {
      lexical_cast<string>(postcode);
   }
   catch (bad_lexical_cast &c) {
      cerr << "Error converting postcode to string! Exiting...";
      exit(EXIT_FAILURE);
   }

   return address + suburb + postcodeString;
}

bool Property::operator< (Property &prop2) {
   if (this->toString() < prop2.toString()) {
      return true;
   }

   return false;
}

// Method to override use of << operator
ostream& operator<<(ostream& os, Property &prop) {

   prop.print();

   return os;
}
// Method to override us of >> operator
istream& operator>>(istream& in, Property &prop) {

   prop.input();

   return in;
}

/* Helper method to validate Australian postcode */
int validatePostcode(int postcode) {

   if (postcode > 0000 && postcode < 99999) {
      return SUCCESS;
   }

   return FAILURE;
}
