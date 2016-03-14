#ifndef __PROPERTY_CONTAINER_H__
#define __PROPERTY_CONTAINER_H__

/* included headers and namespaces */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
#include <map>
#include <string>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/tokenizer.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include "property.h"
#include "res_sales.h"
#include "res_rentals.h"
#include "com_sales.h"
#include "com_rentals.h"
#include "comparator_property.h"
#include "map_container.h"

using namespace std;
using namespace boost;

class PropertyContainer {

   private:
      set<Property*, ComparatorProperty> property;
      MapContainer *ptrMap;

      string commercialFilename;
      string residentialFilename;
      string outputFileStage;
      string inputFileStage;

      /* private getters and setters for use by this object only*/
      string getOutputFileStage() const;
      string getInputFileStage() const;
      void setOutputFileStage(string theOutputFileStage);
      void setInputFileStage(string theInputfileStage);

   public:
      PropertyContainer();
      ~PropertyContainer();
      void setCommercialFilename(string filename); // Setter
      void setResidentialFilename(string filename); // Setter
      void setPtrMap(MapContainer* thePtrMap); // Setter
      string getCommercialFilename() const; // Getter
      string getResidentialFilename() const; // Getter
      MapContainer* getPtrMap() const; // Getter

      void addProperty(Property *propertyInstance, MapContainer* mapContainer);
      void showAllProperties();
      void showResSales();
      void showResRentals();
      void showComSales();
      void showComRentals();
      bool removeProperty(string address, MapContainer* mapContainer);
      Property* findProperty(string address) const;

      /* Determine the property object type, and return it */
      template <class T>
      string getPropertyType(T *property) {

         set<Property*>::iterator it;

         map<const type_info*, string> m;
         m[&typeid(ResSales)] = "ResSales";
         m[&typeid(ResRentals)] = "ResRentals";
         m[&typeid(ComSales)] = "ComSales";
         m[&typeid(ComRentals)] = "ComRentals";

         if (m[&typeid(*property)] == "ResSales") {
            return "ResSales";
         }
         else if (m[&typeid(*property)] == "ResRentals") {
            return "ResRentals";
         }
         else if (m[&typeid(*property)] == "ComSales") {
         return "ComSales";
         }
         else if (m[&typeid(*property)] == "ComRentals") {
            return "ComRentals";
         }

         return NULL;
      }

      set<Property*, ComparatorProperty>& getAllProperties();
      void loadCommercialProperties(ifstream& infile, string file1,
            MapContainer* ptrMap);
      void loadResidentialProperties(ifstream& infile, string file2,
            MapContainer* ptrMap);
      friend ofstream& operator<<(ofstream& outfile,
            PropertyContainer& container);
      friend ifstream& operator>>(ifstream& infile,
            PropertyContainer& container);
      void printResidential(ofstream& outfile, PropertyContainer &container);
      void printCommercial(ofstream& outfile, PropertyContainer &container);
};

#endif
