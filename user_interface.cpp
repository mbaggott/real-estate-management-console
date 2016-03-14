#include "user_interface.h"

using namespace std;

UserInterface::UserInterface() {} // Default Constructor

UserInterface::~UserInterface() {
   delete ptrStaffVec;
   delete ptrPropertySet;
   delete ptrMap;
} // Destructor

/* Constructor */
UserInterface::UserInterface(string file1, string file2, string file3) {

   ifstream staffIn, commercialIn, residentialIn;

   ptrStaffVec = new StaffContainer();
   ptrPropertySet = new PropertyContainer();
   ptrMap = new MapContainer();

   ptrPropertySet->setPtrMap(ptrMap);

   ptrStaffVec->setStaffFilename(file3);
   ptrPropertySet->setCommercialFilename(file1);
   ptrPropertySet->setResidentialFilename(file2);

   staffIn >> *ptrStaffVec;
   commercialIn >> *ptrPropertySet;
   residentialIn >> *ptrPropertySet;

}

StaffContainer* UserInterface::getStaffContainer() const {
   return ptrStaffVec;
}

PropertyContainer* UserInterface::getPropertyContainer() const {
   return ptrPropertySet;
}

/* Main interface interaction method */
void UserInterface::interact() {

   int selection = MENU_DEFAULT;

   while (selection != MENU_QUIT) {
      selection = getMenuSelection();

      switch(selection) {
         case 1:
            displayAll();
            break;
         case 2:
            displayResSales();
            break;
         case 3:
            displayResRentals();
            break;
         case 4:
            displayComSales();
            break;
         case 5:
            displayComRentals();
            break;
         case 6:
            findProperty();
            break;
         case 7:
            addProperty();
            break;
         case 8:
            updateProperty();
            break;
         case 9:
            listStaffProperties();
            break;
         case 10:
            addStaff();
            break;
         case 11:
            removeProperty();
            break;
         case 12:
            removeStaff();
            break;
         case 13:
            quit();
            break;
         default:
            break;
      }
   }


}

/* Output menu to screen */
void UserInterface::displayMenu() {

   cout << endl;
   cout << " 1. Display all properties" << endl;
   cout << " 2. Display residential properties - sales" << endl;
   cout << " 3. Display residential properties - rentals" << endl;
   cout << " 4. Display commercial properties - sales" << endl;
   cout << " 5. Display commercial properties - rentals" << endl;
   cout << " 6. Find a property in the list based on inputted address" << endl;
   cout << " 7. Add a property to the list" << endl;
   cout << " 8. Update a property" << endl;
   cout << " 9. List all the properties associated with a staff member-inputted"
        << " id" << endl;
   cout << "10. Add a staff member to the staff list" << endl;
   cout << "11. Remove a property" << endl;
   cout << "12. Remove a staff member" << endl;
   cout << "13. Quit (saving all data to the 3 files" << endl << endl;
}

/* Allow user to make a menu selection */
int UserInterface::getMenuSelection() {

   string input;
   int selection;
   bool valid = false;

   do {
      displayMenu();
      cout << "Enter selection: ";
      cin >> input;
      try {
         selection = boost::lexical_cast<int>(input);
         if (selection >= MENU_MIN && selection <= MENU_MAX) {
            clearInputBuffer();
            valid = true;
         }
         else {
            cout << endl << "Please enter a valid selection!" << endl << endl;
         }
      }
      catch (boost::bad_lexical_cast &c) {
         cout << endl << "Please enter a valid selection!" << endl << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
   }
   while (!valid);

   return selection;

}

void UserInterface::displayAll() {
   ptrPropertySet->showAllProperties();
}

void UserInterface::displayResSales() {
   ptrPropertySet->showResSales();
}

void UserInterface::displayResRentals(){
   ptrPropertySet->showResRentals();
}

void UserInterface::displayComSales() {
   ptrPropertySet->showComSales();
}

void UserInterface::displayComRentals() {
   ptrPropertySet->showComRentals();
}

void UserInterface::findProperty() {

   string address;
   Property *prop;

   cout << endl << "Find Property." << endl << endl;
   cout << "Please enter an address to search for: ";
   getline(cin, address);

   prop = ptrPropertySet->findProperty(address);
   if (!prop) {
      cout << endl << endl << "Property not found!" << endl;
   }
   else {
      cout <<endl << "Property Details: " << endl;
      cout << *prop;
   }
}

void UserInterface::addProperty() {

   string type;
   bool valid = false;

   cout << endl << "Add property." << endl;

   while (!valid) {
      cout << "Please enter property type (CS/CR/RS/RR): ";
      getline (cin, type);
      if (validatePropertyType(type)) {
         valid = true;
      }
      else {
         cout << endl << "Error, please enter a valid type!" << endl;
      }
   }

   if (type == "CS") {
      Property *prop = new ComSales();
      cin >> *prop;
      ptrPropertySet->addProperty(prop, ptrMap);
   }
   else if (type == "CR") {
      Property *prop = new ComRentals();
      cin >> *prop;
      ptrPropertySet->addProperty(prop, ptrMap);
   }
   else if (type == "RS") {
      Property *prop = new ResSales();
      cin >> *prop;
      ptrPropertySet->addProperty(prop, ptrMap);
   }
   else if (type == "RR") {
      Property *prop = new ResRentals();
      cin >> *prop;
      ptrPropertySet->addProperty(prop, ptrMap);
   }


}

void UserInterface::updateProperty() {

   string address, propertyType;
   Property *prop;

   cout << endl << "Update Property." << endl << endl;
   cout << "Please enter an address to update: ";
   getline(cin, address);

   prop = ptrPropertySet->findProperty(address);
   if (!prop) {
      cout << endl << endl << "Property not found!" << endl;
   }
   else {
      //cin >> *prop;
      cout << endl << "Property found." << endl << endl;

      propertyType = ptrPropertySet->getPropertyType<Property>(prop);

      cout << "    1) Employee ID" << endl;
      cout << "    2) Name" << endl;
      cout << "    3) Address" << endl;
      cout << "    4) Suburb" << endl;
      cout << "    5) Postcode" << endl;

      if (propertyType == "ResSales") {
         cout << "    6) Auction Date" << endl;
         cout << "    7) Price" << endl;
         cout << "    8) Bedrooms" << endl << endl;
      }
      else if (propertyType == "ResRentals") {
         cout << "    6) Bond Amount" << endl;
         cout << "    7) Monthly Rate" << endl;
         cout << "    8) Bedrooms" << endl << endl;
      }
      else if (propertyType == "ComSales") {
         cout << "    6) Auction Date" << endl;
         cout << "    7) Price" << endl;
         cout << "    8) License" << endl << endl;
      }
      else if (propertyType == "ComRentals") {
         cout << "    6) Bond Amount" << endl;
         cout << "    7) Monthly Rate" << endl;
         cout << "    8) License" << endl << endl;
      }

      bool valid = false;
      string selectField;
      int selection = 0;

      do {

         cout << "Please select a field to update: (1 - 8): ";
         cin >> selectField;

         try {
            selection = boost::lexical_cast<int>(selectField);
            if (selection >= FIELD_MIN && selection <= FIELD_MAX) {
               clearInputBuffer();
               valid = true;
            }
            else {
               cout << endl << "Please enter a valid selection!" << endl
                    << endl;
            }
         }
         catch (boost::bad_lexical_cast &c) {
            cout << endl << "Please enter a valid selection!" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
         }
      }
      while (!valid);

      getField(selection, propertyType, prop);
   }
}

void UserInterface::listStaffProperties() {

   string input;
   bool valid = false;

   while (!valid) {
      cout << "Input employee ID to match properties to: ";
      getline(cin, input);
      if (validateID(input)) {
         valid = true;
         if (!ptrMap->listAssociatedProperties(input)) {
            cout << "No matches found for supplied ID!" << endl;
         }
      }
      else {
         cout << "Please input a valid ID!" << endl;
      }
   }
}

/* Add staff to staff list */
void UserInterface::addStaff() {

   string type;
   bool valid = false;
   string id;

   ptrStaffVec->showAllStaff();

   cout << endl << "Add new staff member." << endl;

   /* Get type of staff, sales or rentals */
   while (valid == false) {

      cout << "Staff type Sales Staff (SS) or Rentals Staff (SR): ";
      getline(cin, type);
      if (validateStaffType(type)) {
         valid = true;
      }
      else {
         cerr << "Please enter a valid staff type!" << endl;
      }
   }

   /* Add staff to staff list */
   to_upper(type);
   if (type == "SS") {
      Staff *staff = new SalesStaff();
      cin >> *staff;
      ptrStaffVec->addStaff(staff);
   }
   else if (type == "SR") {
      Staff *staff = new RentalsStaff();
      cin >> *staff;
      ptrStaffVec->addStaff(staff);
   }
}

void UserInterface::removeProperty() {

   string address;

   cout << endl << "Remove Property." << endl << endl;
   cout << "Please enter an address to search for: ";
   getline(cin, address);

   if (!ptrPropertySet->removeProperty(address, ptrMap)) {
      cout << endl << endl << "Property not found, no property removed!"
           << endl;
   }
}

void UserInterface::removeStaff() {

   string id;

   if (ptrStaffVec->getStaffSize() == 0) {
      cout << endl << "No staff to remove!" << endl << endl;
   }
   else {
      cout << endl << "*** Remove staff ***" << endl << endl;
      ptrStaffVec->showAllStaff();
      cout << endl << "Enter employee ID to remove: ";
      cin >> id;
      if (ptrStaffVec->removeStaff(id)) {
         cout << endl << "Staff member " << id << " removed." << endl << endl;
      }
      else {
         cout << endl << "Staff member " << id
              << " not found! No staff removed." << endl << endl;
      }
   }
}

void UserInterface::quit() {

   ofstream outfile;

   string file1 = "staff.dat", file2 = "residential.dat",
         file3 = "commercial.dat";
   const char* of = file1.c_str();
   outfile.open(of);
   outfile << *ptrStaffVec;
   outfile.close();

   of = file2.c_str();
   outfile.open(of);
   outfile << *ptrPropertySet;
   outfile.close();

   of = file3.c_str();
   outfile.open(of);
   outfile << *ptrPropertySet;
   outfile.close();
}

/* Function to allow modification of property instance */
void UserInterface::getField(int selection, string PropertyType,
      Property* property) {

   bool valid = false;
   string input;
   int intValue;
   double doubleValue;

   switch(selection) {
      case 1:
         while (!valid) {
            cout << "Input new value: ";
            getline(cin, input);
            if (validateID(input)) {
               property->setEmpID(input);
               valid = true;
            }
            else {
               cout << "Please enter a valid value!" << endl;
            }
         }
         break;

      case 2:
         cout << "Input new value: ";
         getline(cin, input);
         property->setOwner(input);
         break;

      case 3:
         cout << "Input new value: ";
         getline(cin, input);
         property->setAddress(input);
         break;

      case 4:
         cout << "Input new value: ";
         getline(cin, input);
         property->setSuburb(input);
         break;

      case 5:
         do {
            cout << "Input new value: ";
            getline(cin, input);
            try {
               intValue = boost::lexical_cast<int>(input);
               if (validatePostcode(intValue)) {
                  valid = true;
                  property->setPostcode(intValue);
               }
               else {
                  cout << endl << "Please enter a valid value!" << endl;
               }
            }
            catch (boost::bad_lexical_cast &c) {
               cout << endl << "Please enter a valid value!" << endl;
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
         }
         while (!valid);
         break;

      case 6:
         if (PropertyType == "ResSales") {
            cout << "Input new value: ";
            getline(cin, input);
            ResSales *rs = dynamic_cast<ResSales*>(property);
            rs->setAuctionDate(input);
         }

         else if (PropertyType == "ResRentals") {
            ResRentals *rr = dynamic_cast<ResRentals*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  doubleValue = boost::lexical_cast<double>(input);
                  if (isDouble(input)) {
                     clearInputBuffer();
                     valid = true;
                     rr->setBond(doubleValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }

         else if (PropertyType == "ComSales") {
            cout << "Input new value: ";
            getline(cin, input);
            ComSales *cs = dynamic_cast<ComSales*>(property);
            cs->setAuctionDate(input);
         }

         else if (PropertyType == "ComRentals") {
            ComRentals *cr = dynamic_cast<ComRentals*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  doubleValue = boost::lexical_cast<double>(input);
                  if (isDouble(input)) {
                     clearInputBuffer();
                     valid = true;
                     cr->setBond(doubleValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }
         break;

      case 7:
         if (PropertyType == "ResSales") {
            ResSales *rs = dynamic_cast<ResSales*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  doubleValue = boost::lexical_cast<double>(input);
                  if (isDouble(input)) {
                     clearInputBuffer();
                     valid = true;
                     rs->setPrice(doubleValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }

         else if (PropertyType == "ResRentals") {
            ResRentals *rr = dynamic_cast<ResRentals*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  doubleValue = boost::lexical_cast<double>(input);
                  if (isDouble(input)) {
                     clearInputBuffer();
                     valid = true;
                     rr->setMonthlyRent(doubleValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }

         else if (PropertyType == "ComSales") {
            ComSales *cs = dynamic_cast<ComSales*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  doubleValue = boost::lexical_cast<double>(input);
                  if (isDouble(input)) {
                     clearInputBuffer();
                     valid = true;
                     cs->setPrice(doubleValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }

         else if (PropertyType == "ComRentals") {
            ComRentals *cr = dynamic_cast<ComRentals*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  doubleValue = boost::lexical_cast<double>(input);
                  if (isDouble(input)) {
                     clearInputBuffer();
                     valid = true;
                     cr->setMonthlyRent(doubleValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }
         break;

      case 8:
         if (PropertyType == "ResSales") {
            ResSales *rs = dynamic_cast<ResSales*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  intValue = boost::lexical_cast<double>(input);
                  if (isInteger(input)) {
                     clearInputBuffer();
                     valid = true;
                     rs->setBedrooms(intValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }

         else if (PropertyType == "ResRentals") {
            ResRentals *rr = dynamic_cast<ResRentals*>(property);
            do {
               cout << "Input new value: ";
               getline(cin, input);
               try {
                  intValue = boost::lexical_cast<double>(input);
                  if (isInteger(input)) {
                     clearInputBuffer();
                     valid = true;
                     rr->setBedrooms(intValue);
                  }
                  else {
                     cout << endl << "Please enter a valid value!" << endl;
                  }
               }
               catch (boost::bad_lexical_cast &c) {
                  cout << endl << "Please enter a valid value!" << endl;
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
               }
            }
            while (!valid);
         }

         else if (PropertyType == "ComSales") {
            cout << "Input new value: ";
            getline(cin, input);
            ComSales *cs = dynamic_cast<ComSales*>(property);
            cs->setLicense(input);
         }

         else if (PropertyType == "ComRentals") {
            cout << "Input new value: ";
            getline(cin, input);
            ComRentals *cr = dynamic_cast<ComRentals*>(property);
            cr->setLicense(input);
         }
         break;
   }
}
