#include "property_container.h"

/* Default Constructor */
PropertyContainer::PropertyContainer(): commercialFilename(""),
residentialFilename(""), outputFileStage("file1"), inputFileStage("file1") {}

/* Destructor */
PropertyContainer::~PropertyContainer() {

   set<Property*>::iterator it;

   for (it = property.begin(); it != property.end(); ++it) {
      delete *it;
   }
}

ofstream& operator<<(ofstream& outfile, PropertyContainer& container) {

   if (container.getOutputFileStage() == "file1") {
      container.printResidential(outfile, container);
      container.setOutputFileStage("file2");
   }
   else if (container.getOutputFileStage() == "file2") {
      container.printCommercial(outfile, container);
   }

   return outfile;

}

ifstream& operator>>(ifstream& infile, PropertyContainer& container) {

   if (container.getInputFileStage() == "file1") {
      container.loadCommercialProperties(infile,
            container.getCommercialFilename(), container.getPtrMap());
            container.setInputFileStage("file2");
   }
   else if (container.getInputFileStage() == "file2") {
      container.loadResidentialProperties(infile,
            container.getResidentialFilename(), container.getPtrMap());
   }
   return infile;
}

/* *** GETTERS *** */

MapContainer* PropertyContainer::getPtrMap() const {
   return ptrMap;
}

string PropertyContainer::getOutputFileStage() const {
   return outputFileStage;
}

string PropertyContainer::getInputFileStage() const {
   return inputFileStage;
}


string PropertyContainer::getCommercialFilename() const {
   return commercialFilename;
}

string PropertyContainer::getResidentialFilename() const {
   return residentialFilename;
}

/* *** SETTERS *** */
void PropertyContainer::setPtrMap(MapContainer* thePtrMap) {
   ptrMap = thePtrMap;
}

void PropertyContainer::setOutputFileStage(string theOutputFileStage) {
   outputFileStage = theOutputFileStage;
}

void PropertyContainer::setInputFileStage(string theInputFileStage) {
   inputFileStage = theInputFileStage;
}

void PropertyContainer::setCommercialFilename(string filename) {
   commercialFilename = filename;
}

void PropertyContainer::setResidentialFilename(string filename) {
   residentialFilename = filename;
}

/* Adds a property to the property container */
void PropertyContainer::addProperty(Property *propertyInstance,
      MapContainer *mapContainer) {

   property.insert(propertyInstance);
   mapContainer->addProperty(propertyInstance);

}

/* Output all property details to the screen */
void PropertyContainer::showAllProperties() {

   set<Property*>::iterator it;

   for (it = property.begin(); it != property.end(); ++it) {
      cout << **it;
   }
}

/* Output all ResSales data to the screen */
void PropertyContainer::showResSales() {

   set<Property*>::iterator it;

   map<const type_info*, string> m;
   m[&typeid(ResSales)] = "ResSales";

   for (it = property.begin(); it != property.end(); ++it) {
      if ((*it)->isProperty(**it)) {
         if (m[&typeid(**it)] == "ResSales") {
            cout << **it;
         }
      }
   }

}

/* Output all ResRentals data to the screen */
void PropertyContainer::showResRentals() {

   set<Property*>::iterator it;

   map<const type_info*, string> m;
   m[&typeid(ResRentals)] = "ResRentals";

   for (it = property.begin(); it != property.end(); ++it) {
      if ((*it)->isProperty(**it)) {
         if (m[&typeid(**it)] == "ResRentals") {
            cout << **it;
         }
      }
   }

}

/* Output all ComSales data to the screen */
void PropertyContainer::showComSales() {

   set<Property*>::iterator it;

   map<const type_info*, string> m;
   m[&typeid(ComSales)] = "ComSales";

   for (it = property.begin(); it != property.end(); ++it) {
      if ((*it)->isProperty(**it)) {
         if (m[&typeid(**it)] == "ComSales") {
            cout << **it;
         }
      }
   }

}

/* Output all ComRentals data to the screen */
void PropertyContainer::showComRentals() {

   set<Property*>::iterator it;

   map<const type_info*, string> m;
   m[&typeid(ComRentals)] = "ComRentals";

   for (it = property.begin(); it != property.end(); ++it) {
      if ((*it)->isProperty(**it)) {
         if (m[&typeid(**it)] == "ComRentals") {
            cout << **it;
         }
      }
   }

}


/* Request user input to select a property, and remove it from the property
   container. Also delete the instance from memory */
bool PropertyContainer::removeProperty(string address,
      MapContainer* mapContainer) {

   int numMatches = 0, deleted = 0;
   string response;

   set<Property*>::iterator it;

   for (it = property.begin(); it != property.end(); ++it) {
      if (to_upper_copy((*it)->getAddress()).find(to_upper_copy(address)) !=
            string::npos) {
         numMatches++;
         cout << "Match found!" << endl << endl << **it << endl << endl
            << "Delete this property? (Y/N): ";
         getline(cin, response);
         if (to_upper_copy(response) == "Y") {
            mapContainer->removeProperty(*it);
            delete *it;
            property.erase(it);
            deleted++;
            cout << endl << "Property deleted." << endl << endl;
            break;
         }
      }
   }

   cout << numMatches << " properties matched, " << deleted
        << " properties deleted. Finished searching." << endl << endl;

   if (deleted == true) {
      return true;
   }
   return false;

}

/* Find a property that matches the given address string andd return it */
Property* PropertyContainer::findProperty(string address)
      const {

      string response;
      set<Property*>::iterator it;

      for (it = property.begin(); it != property.end(); ++it) {
      if (to_upper_copy((*it)->getAddress()).find(to_upper_copy(address)) !=
            string::npos) {
         cout << "Match found!" << endl << endl << **it << endl << endl
            << "Select this property? (Y/N): ";
         getline(cin, response);
         if (to_upper_copy(response) == "Y") {
            return *it;
         }
      }
   }
   return NULL;

}


/* Get the property container and return it for outside functions to be
   able to iterate through it */
set<Property*, ComparatorProperty>& PropertyContainer::getAllProperties() {
   return property;
}

void PropertyContainer::loadCommercialProperties(ifstream &infile, string file1,
      MapContainer* ptrMap) {

   string line, subLine;

   int numLines, numTokens;
   string typeId;
   string type;
   string id;
   string name;
   string address;
   string suburb;
   int postcode;
   string license;
   string auctionDate;
   double price;
   double bond;
   double monthlyRent;

   /* convert filename to constant *char for opening and open file*/
   const char *c = file1.c_str();
   infile.open(c);

   /* Check for problems with file, abort if any found */
   if (!infile) {
      cout << "Error opening " << file1 << ", exiting...";
      exit(EXIT_FAILURE);
   }

   /* Iterate through file line by line */
   while (infile.good()) {

      numLines = 0;
      subLine = "";

      /* Retrieve property data line by line from sub entries delimited by '*'
      */
;      while (infile.good() && subLine != "*") {

         numLines++;
         getline(infile, subLine);
         if(infile.eof()) break;

         switch(numLines) {
            case 1:
            {

               /* Tokenise subline that is seperated by a space */
               char_separator<char> subSep(" ");
               tokenizer<char_separator<char> > tokens(subLine, subSep);
               numTokens = 0;

               BOOST_FOREACH(string subT, tokens) {
                  numTokens++;
                  if (numTokens == 1) {
                     type = subT;
                  }
                  else if (numTokens == 2) {
                        id = subT;
                  }
               }
               if (!validateCommercialType(type)) {
                  cerr << "Error, commercial property type must be CS or CR! "
                       << "Exiting...";
                  exit(EXIT_FAILURE);
               }
               if (!validateID(id)) {
                  cerr << "Error, employee ID's must be of format 'eXX',"
                       << "exiting...";
                  exit(EXIT_FAILURE);
               }
               break;
            }
            case 2:
               name = subLine;
               break;
            case 3:
               address = subLine;
               break;
            case 4:
               suburb = subLine;
               break;
            case 5:
               if (isInteger(subLine)) {
                  postcode = lexical_cast<int>(subLine);
               }
               else {
                  cout << "Error, postocde must be an integer! Exiting...";
                  exit(EXIT_FAILURE);
               }
               break;
            case 6:
               license = subLine;
               break;
            case 7:
            {
               /* Tokenise subline that is seperated by a space */
               char_separator<char> subSep(" ");
               tokenizer<char_separator<char> > tokens(subLine, subSep);
               numTokens = 0;

               BOOST_FOREACH(string subT, tokens) {
                  numTokens++;
                  if (numTokens == 1) {
                     if (type == "CS") {
                        if (isDouble(subT)) {
                           price = lexical_cast<double>(subT);
                        }
                        else {
                           cout << "Error, price must be a double! Exiting...";
                           exit(EXIT_FAILURE);
                        }
                     }
                     else if (type == "CR") {
                        if (isDouble(subT)) {
                           bond = lexical_cast<double>(subT);
                        }
                        else {
                           cout << "Error, bond must be a double! Exiting...";
                           exit(EXIT_FAILURE);
                        }
                     }
                  }
                  else if (numTokens == 2) {
                     if (type == "CS") {
                        auctionDate = subT;
                     }
                     else if (type == "CR") {
                        if (isDouble(subT)) {
                           monthlyRent = lexical_cast<double>(subT);
                        }
                        else {
                           cout << "Error, rent must be a double! Exiting...";
                           exit(EXIT_FAILURE);
                        }
                     }
                  }
               }
               break;
            }
            default:
               break;
         }
      }
      if(infile.eof()) break;

      /* Create new property and add to property list based on type */
      if (type == "CS") {
         addProperty(new ComSales(id, name, address, suburb, postcode, license,
               auctionDate, price), ptrMap);
      }
      if (type == "CR") {
         addProperty(new ComRentals(id, name, address, suburb, postcode,
               license, bond, monthlyRent), ptrMap);
      }
   }
   infile.close();
}

void PropertyContainer::loadResidentialProperties(ifstream& infile,
      string file2, MapContainer* ptrMap) {

   string line, subLine;

   int numLines, numTokens;
   string typeId;
   string type;
   string id;
   string name;
   string address;
   string suburb;
   int postcode;
   int bedrooms;
   string auctionDate;
   double price;
   double bond;
   double monthlyRent;

   /* convert filename to constant *char for opening and open file*/
   const char *c = file2.c_str();
   infile.open(c);

   /* Check for problems with file, abort if any found */
   if (!infile) {
      cout << "Error opening " << file2 << ", exiting...";
      exit(EXIT_FAILURE);
   }

   /* Iterate through file line by line */
   while (infile.good()) {

      numLines = 0;
      subLine = "";

      /* Retrieve property data line by line from sub entries delimited by '*'
      */
      while (infile.good() && subLine != "*") {

         numLines++;
         getline(infile, subLine);
         if(infile.eof()) break;

         switch(numLines) {
            case 1:
            {

               /* Tokenise subline that is seperated by a space */
               char_separator<char> subSep(" ");
               tokenizer<char_separator<char> > tokens(subLine, subSep);
               numTokens = 0;

               BOOST_FOREACH(string subT, tokens) {
                  numTokens++;
                  if (numTokens == 1) {
                     type = subT;
                  }
                  else if (numTokens == 2) {
                        id = subT;
                  }
               }
               if (!validateResidentialType(type)) {
                  cerr << "Error, residential property type must be RS or RR! "
                       << "Exiting...";
                  exit(EXIT_FAILURE);
               }
               if (!validateID(id)) {
                  cerr << "Error, employee ID's must be of format 'eXX',"
                       << "exiting...";
                  exit(EXIT_FAILURE);
               }
               break;
            }
            case 2:
               name = subLine;
               break;
            case 3:
               address = subLine;
               break;
            case 4:
               suburb = subLine;
               break;
            case 5:
               if (isInteger(subLine)) {
                  postcode = lexical_cast<int>(subLine);
               }
               else {
                  cout << "Error, postcode must be an integer! Exiting...";
                  exit(EXIT_FAILURE);
               }
               break;
            case 6:
               if (isInteger(subLine)) {
                  bedrooms = lexical_cast<int>(subLine);
               }
               else {
                  cout << "Error, bedrooms must be an integer! Exiting...";
                  exit(EXIT_FAILURE);
               }
            case 7:
            {
               /* Tokenise subline that is seperated by a space */
               char_separator<char> subSep(" ");
               tokenizer<char_separator<char> > tokens(subLine, subSep);
               numTokens = 0;

               BOOST_FOREACH(string subT, tokens) {
                  numTokens++;
                  if (numTokens == 1) {
                     if (type == "RS") {
                        auctionDate = subT;
                     }
                     else if (type == "RR") {
                        if (isDouble(subT)) {
                           bond = lexical_cast<double>(subT);
                        }
                        else {
                           cout << "Error, bond must be a double! Exiting...";
                           exit(EXIT_FAILURE);
                        }
                     }
                  }
                  else if (numTokens == 2) {
                     if (type == "RS") {
                        if (isDouble(subT)) {
                           price = lexical_cast<double>(subT);
                        }
                        else {
                           cout << "Error, price must be a double! Exiting...";
                           exit(EXIT_FAILURE);
                        }
                     }
                     else if (type == "RR") {
                        if (isDouble(subT)) {
                           monthlyRent = lexical_cast<double>(subT);
                        }
                        else {
                           cout << "Error, rent must be a double! Exiting...";
                           exit(EXIT_FAILURE);
                        }
                     }
                  }
               }
               break;
            }
            default:
               break;
         }
      }

      if(infile.eof()) break;
      /* Create new property and add to property list based on type */
      if (type == "RS") {
         addProperty(new ResSales(id, name, address, suburb, postcode, bedrooms,
               auctionDate, price), ptrMap);
      }
      else if (type == "RR") {
         addProperty(new ResRentals(id, name, address, suburb, postcode,
               bedrooms, bond, monthlyRent), ptrMap);
      }
   }
   infile.close();
}

/* Function to output residential data */
void PropertyContainer::printResidential(ofstream& outfile,
      PropertyContainer &container) {

   set<Property*, ComparatorProperty>& property =
         container.getAllProperties();
   set<Property*, ComparatorProperty>::iterator it;
   map<const type_info*, string> testProperty;

   testProperty[&typeid(ResSales)] = "ResSales";
   testProperty[&typeid(ResRentals)] = "ResRentals";

   for (it = property.begin(); it != property.end(); ++it) {
      if (testProperty[&typeid(**it)] == "ResSales") {
         ResSales *rs = dynamic_cast<ResSales*>(*it);
         outfile << "RS" << " " << rs->getEmpID() << endl;
         outfile << rs->getOwner() << endl;
         outfile << rs->getAddress() << endl;
         outfile << rs->getSuburb() << endl;
         outfile << rs->getPostcode() << endl;
         outfile << rs->getBedrooms() << endl;
         outfile << rs->getAuctionDate() << " ";
         outfile << rs->getPrice() << endl;
         outfile << "*" << endl;
      }
      else if (testProperty[&typeid(**it)] == "ResRentals") {
         ResRentals *rr = dynamic_cast<ResRentals*>(*it);
         outfile << "RR" << " " << rr->getEmpID() << endl;
         outfile << rr->getOwner() << endl;
         outfile << rr->getAddress() << endl;
         outfile << rr->getSuburb() << endl;
         outfile << rr->getPostcode() << endl;
         outfile << rr->getBedrooms() << endl;
         outfile << rr->getBond() << " ";
         outfile << rr->getMonthlyRent() << endl;
         outfile << "*" << endl;
      }
   }
}

/* Function to output commercial data */
void PropertyContainer::printCommercial(ofstream& outfile,
      PropertyContainer &container) {


   set<Property*, ComparatorProperty>& property =
         container.getAllProperties();
   set<Property*, ComparatorProperty>::iterator it;
   map<const type_info*, string> testProperty;

   testProperty[&typeid(ComSales)] = "ComSales";
   testProperty[&typeid(ComRentals)] = "ComRentals";

   for (it = property.begin(); it != property.end(); ++it) {
      if (testProperty[&typeid(**it)] == "ComSales") {
         ComSales *cs = dynamic_cast<ComSales*>(*it);
         outfile << "CS" << " " << cs->getEmpID() << endl;
         outfile << cs->getOwner() << endl;
         outfile << cs->getAddress() << endl;
         outfile << cs->getSuburb() << endl;
         outfile << cs->getPostcode() << endl;
         outfile << cs->getLicense() << endl;
         outfile << cs->getPrice() << " ";
         outfile << cs->getAuctionDate() << endl;
         outfile << "*" << endl;
      }
      else if (testProperty[&typeid(**it)] == "ComRentals") {
         ComRentals *cr = dynamic_cast<ComRentals*>(*it);
         outfile << "CR" << " " << cr->getEmpID() << endl;
         outfile << cr->getOwner() << endl;
         outfile << cr->getAddress() << endl;
         outfile << cr->getSuburb() << endl;
         outfile << cr->getPostcode() << endl;
         outfile << cr->getLicense() << endl;
         outfile << cr->getBond() << " ";
         outfile << cr->getMonthlyRent() << endl;
         outfile << "*" << endl;
      }
   }
}


