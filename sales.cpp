#include "sales.h"

/* Default constructor */
Sales::Sales(): auctionDate(defString), price(defNum) {}

/* Destructor */
Sales::~Sales() {}

/* Constructor */
Sales::Sales(string theEmpID, string theOwner, string theAddress,
      string theSuburb,int thePostcode, string theAuctionDate, double thePrice):
      Property(theEmpID, theOwner, theAddress, theSuburb, thePostcode) {
         auctionDate = theAuctionDate;
         price = thePrice;
}

/* Copy constructor */
Sales::Sales(const Sales &sales) {

   owner = sales.owner;
   address = sales.address;
   suburb = sales.suburb;
   postcode = sales.postcode;
   auctionDate = sales.auctionDate;
   price = sales.price;

}

/* *** GETTERS *** */

string Sales::getAuctionDate() const {
   return auctionDate;
}

double Sales::getPrice() const {
   return price;
}

/* *** SETTERS *** */

void Sales::setAuctionDate(string theAuctionDate) {
   auctionDate = theAuctionDate;
}

void Sales::setPrice(double thePrice) {
   price = thePrice;
}

/* Method to accept user input and set member variables */
void Sales::input() {

   string theAuctionDate;
   double thePrice;
   bool valid = false;

   Property::input();

   cout << "Input auction date: ";
   getline(cin, theAuctionDate);

   auctionDate = theAuctionDate;

   do {
      cout << "Input price: ";
      cin >> thePrice;

      if (cin.good()) {
         price = thePrice;
         valid = true;
         clearInputBuffer();
      }

      else {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Please enter a valid floating point number!" << endl;
      }

   }
   while (!valid);
}

/* Method to output details of object to screen */
void Sales::print() {

   Property::print();

   cout << "Auction date: " << auctionDate << endl;
   locale comma_locale(locale(), new Comma_Numpunct());
   cout.imbue(comma_locale);
   cout << "Price: $" << setprecision(2) << fixed << price << endl;
   locale global(locale("C"));
   cout.imbue(global);
}

/* Method to determine instance type of object */
bool Sales::isProperty(Property &property) {

   try {
      Sales res = dynamic_cast<Sales&>(property);
   }
   catch(std::bad_cast &bc) {
      return false;
   }

   return true;
}
