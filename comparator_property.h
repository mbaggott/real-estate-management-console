#ifndef __COMPARATOR_PROPERTY_H__
#define __COMPARATOR_PROPERTY_H__

class ComparatorProperty {

   public:
      bool operator() (Property *prop1, Property *prop2) {

         if (prop1->toString() < prop2->toString()) {
            return true;
         }

         return false;
      }
};


#endif
