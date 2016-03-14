#include "staff_container.h"

/* Default Constructor */
StaffContainer::StaffContainer(): staffFilename("") { }

/* Destructor */
StaffContainer::~StaffContainer() {

   for (unsigned int x = 0; x < staff.size(); x++) {
      delete staff[x];
   }
}

ofstream& operator<<(ofstream& outfile, StaffContainer& container) {

   container.printStaff(outfile, container);

   return outfile;

}

ifstream& operator>>(ifstream& infile, StaffContainer& container) {

   container.loadStaff(container.getStaffFilename(), infile);

   return infile;

}

/* Adds staff to the staff vector (list), and sorts by employee ID.
   sort() makes use of the comparator functor */
void StaffContainer::addStaff(Staff *staffInstance) {

   staff.push_back(staffInstance);
   sort(staff.begin(), staff.end(), ComparatorEmpID<Staff>());

}

/* Remove a staff object from the storage container and delete it from memory */
bool StaffContainer::removeStaff(string id) {

   for (vector<Staff*>::iterator it = staff.begin(); it != staff.end(); it++) {
      if ((*it)->getEmpID() == id) {
         delete *it;
         staff.erase(it);
         return true;
      }
   }
   return false;
}

/* Output all staff details to screen */
void StaffContainer::showAllStaff() {
   for (int x = 0; x < getStaffSize(); x++) {
      cout << *staff[x];
   }
}

/* *** SETTERS *** */

void StaffContainer::setStaffFilename(string filename) {
   staffFilename = filename;
}

/* *** GETTERS *** */

/* Gets the current number of staff in the list */
int StaffContainer::getStaffSize() const {
   return staff.size();
}

string StaffContainer::getStaffFilename() const {
   return staffFilename;
}

/* Return the staff container for outside functions to be able to iterate
   through it */
vector<Staff*>& StaffContainer::getAllStaff() {
   return staff;
}

/* Load staff from file staff.dat into program */
void StaffContainer::loadStaff(string file3, ifstream &infile) {

   string line;

   int numTokens;
   string type;
   string id;
   string name;
   double salary;
   string phone;
   double monetary;

   /* Convert string filename to const *char for opening */
   const char *c = file3.c_str();

   /* Open file and check for problems */
   infile.open(c);
   if (!infile) {
      cout << "Error opening " << file3 << ", exiting...";
      exit(EXIT_FAILURE);
   }

   /* Retrieve file data line by line */
   while (infile.good()) {

      getline(infile, line);
      if(infile.eof()) break;

      /* Tokenize each line of data */
      char_separator<char> sep("|");
      tokenizer<char_separator<char> > tokens(line, sep);
      numTokens = 0;

      /* Extract tokens */
      BOOST_FOREACH(string t, tokens) {
         numTokens++;
         switch(numTokens) {
            case 1:
               type = t;
               if (!validateStaffType(type)) {
                  cerr << "Error, staff type must be SS or SR! Exiting...";
                  exit(EXIT_FAILURE);
               }
               break;
            case 2:
               id = t;
               if (!validateID(id)) {

                  cerr << "Error, employee ID's must be of format 'eXX',"
                       << "exiting...";
                  exit(EXIT_FAILURE);
               }
               break;
            case 3:
               name = t;
               break;
            case 4:
               if (isDouble(t)) {
                  salary = lexical_cast<float>(t);
               }
               else {
                  cout << "Error in staff data, salary is not a float!"
                       << " Exiting..." << endl;
                  exit(EXIT_FAILURE);
               }
               break;
            case 5:
               phone = t;
               break;
            case 6:
               if (isDouble(t)) {
                  monetary = lexical_cast<float>(t);
               }
               else {
                  cout << "Error in staff data, bonus/commission is not a"
                       << " float! Exiting..." << endl;
                  exit(EXIT_FAILURE);
               }
               break;
            default:
               break;
         }
      }

      /* Create new staff and add to staff list based on type of staff */
      to_upper(type);
      if (type == "SS") {
         addStaff(new SalesStaff(id, name, salary, phone,
            monetary));
      }
      else if (type == "SR") {
         addStaff(new RentalsStaff(id, name, salary, phone,
            monetary));
      }
   }
   infile.close();
}

/* Function to output staff data */
void StaffContainer::printStaff(ofstream& outfile, StaffContainer& container) {

   vector<Staff*>& staff = container.getAllStaff();
   vector<Staff*>::iterator it;
   map<const type_info*, string> testStaff;

   testStaff[&typeid(SalesStaff)] =  "SalesStaff";
   testStaff[&typeid(RentalsStaff)] = "RentalsStaff";


   for (it = staff.begin(); it != staff.end(); ++it) {
      if (testStaff[&typeid(**it)] == "SalesStaff") {
         outfile << "SS|";
      }
      else if (testStaff[&typeid(**it)] == "RentalsStaff") {
         outfile << "SR|";
      }
      outfile << (*it)->getEmpID() << "|";
      outfile << (*it)->getName() << "|";
      outfile << setprecision(2) << fixed << (*it)->getSalary() << "|";
      outfile << setprecision(12);
      outfile.unsetf(ios::fixed);
      outfile << (*it)->getMobileNo() << "|";
      if (testStaff[&typeid(**it)] == "SalesStaff") {
         SalesStaff* ss = dynamic_cast<SalesStaff*>(*it);
         outfile << ss->getCommission() << endl;
      }
      else if (testStaff[&typeid(**it)] == "RentalsStaff") {
         RentalsStaff* rs = dynamic_cast<RentalsStaff*>(*it);
         outfile << rs->getBonus() << endl;
      }
   }
}

