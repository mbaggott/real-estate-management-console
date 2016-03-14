//
// userInterface.h
//
// Interface class with menu
//

#ifndef __USERINTERFACE_H__
#define __USERINTERFACE_H__


/* HEADER FILES AND NAMESPACES*/
#include <iostream>
#include <string>
#include "staff_container.h"
#include "property_container.h"
#include "map_container.h"
#include "utility1.h"

using namespace std;

/* Constants */
static const int MENU_DEFAULT = -1;
static const int MENU_QUIT = 13;
static const int MENU_MIN = 1;
static const int MENU_MAX = 13;
static const int FIELD_MIN = 1;
static const int FIELD_MAX = 8;
static const int LEADING_ZERO_MIN = 1;
static const int LEADING_ZERO_MAX = 9;

class UserInterface
{
   private:
      StaffContainer* ptrStaffVec;
      PropertyContainer* ptrPropertySet;
      MapContainer* ptrMap;

      /* private functions for use by this object only */
      void displayMenu();
      int getMenuSelection();
      void displayAll();
      void displayResSales();
      void displayResRentals();
      void displayComSales();
      void displayComRentals();
      void findProperty();
      void addProperty();
      void updateProperty();
      void listStaffProperties();
      void addStaff();
      void removeProperty();
      void removeStaff();
      void quit();
      void getField(int selection, string PropertyType, Property* property);
    public:
      UserInterface(); // Default constructor
      UserInterface(string file1, string file2, string file3);
      ~UserInterface(); // Constructor
      StaffContainer* getStaffContainer() const; // Getter
      PropertyContainer* getPropertyContainer() const; // Getter
      void interact(); // Contains menu

  };

#endif
