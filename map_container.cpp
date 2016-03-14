#include "map_container.h"

/* Default constructor */
MapContainer::MapContainer() {}

/* Destructor */
MapContainer::~MapContainer() {

}

/* Constructor */
void MapContainer::addProperty(Property *propertyInstance) {
   property.insert(pair<string, Property*>(propertyInstance->getEmpID(),
         propertyInstance));
}

/* Remove a property from the container. Reference is assumed to be deleted
   in the property container class. */
bool MapContainer::removeProperty(Property* propertyInstance) {

   multimap<string, Property*>::iterator it;

   for (it = property.begin(); it != property.end(); ++it) {
      if ((*it).second == propertyInstance) {
         property.erase(it);
         return true;
      }
   }
   return false;
}

/* Ouput to screen all properties associated with the supplied employee ID */
bool MapContainer::listAssociatedProperties(string empID) {

   multimap<string, Property*>::iterator it;
   bool matched = false;

   for (it = property.begin(); it != property.end(); ++it) {
      if ((*it).first == empID) {
         cout << *(*it).second << endl;
         matched = true;
      }
   }
   if (matched == true) {
      return true;
   }
   return false;
}

