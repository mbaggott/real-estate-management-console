#include "utility1.h"
// function to clear the input buffer

void clearInputBuffer() {
   char symbol;
   do
   {
      cin.get(symbol);
   }
   while(symbol != '\n');
}

// Method to set the dollar value delimiter
char Comma_Numpunct::do_thousands_sep() {
   return ',';
}

// Method to set the grouping for dollar values to maximum 3
string Comma_Numpunct::do_grouping() const {
   return "\03";
}

// Method to test if input is an integer
bool isInteger(string str) {

   try {
      lexical_cast<int>(str);
      return true;
   } catch (bad_lexical_cast &c) {
      return false;
   }
}

/* Checks if supplied argument is of double format */
bool isDouble(string str) {

   try {
      lexical_cast<double>(str);
      return true;
   } catch (bad_lexical_cast &c) {
      return false;
   }
}

/* Validates employee ID to assumed criteria of eX where x is any int */
bool validateID(string id) {

   if (id[0] != 'e') {
      return false;
   }

   id.erase(0, 1);

   try {
      lexical_cast<int>(id);
   }
   catch (bad_lexical_cast &c) {
      return false;
   }

   return true;
}

/* Validates staff types to two choices only */
bool validateStaffType(string type) {

   to_upper(type);

   if (type == "SS" || type == "SR") {
      return true;
   }

   return false;
}

/* Validates commercial property types to two choices only */
bool validateCommercialType(string type) {

   if (type == "CS" || type == "CR") {
      return true;
   }

   return false;
}

/* Validates residential property types to two choices only */
bool validateResidentialType(string type) {

   if (type == "RS" || type == "RR") {
      return true;
   }

   return false;
}

/* Validate property type to an arbitrary value for file input */
bool validatePropertyType(string type) {

   if (type == "CS" || type == "CR" || type == "RS" || type == "RR") {
      return true;
   }

   return false;
}

