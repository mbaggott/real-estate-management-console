#ifndef __MAP_CONTAINER_H__
#define __MAP_CONTAINER_H__

/* Included headers and namespaces */
#include <iostream>
#include <cstdlib>
#include <map>
#include "property.h"

class MapContainer {

   private:
      multimap<string, Property*> property;

   public:
      MapContainer();
      ~MapContainer();
      void addProperty(Property *propertyInstance);
      bool removeProperty(Property* propertyInstance);
      Property* findProperty(string address) const;
      bool listAssociatedProperties(string empID);

};

#endif
