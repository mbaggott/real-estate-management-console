#ifndef __COMPARATOR_EMPID_H__
#define __COMPARATOR_EMPID_H__

#include "staff.h"

/* Comparison function object (functor) */
/* Used so that staff objects may be sorted in their vector container.
   Necessary because stored staff objects are pointers, and default
   sorting would sort by pointer and fail to sort by object, even if the
   < operator is overloaded */

template <class T>
class ComparatorEmpID {

   public:
      bool operator() (T *staff1, T *staff2) {
         string s1, s2;
         int s1Int, s2Int;

         s1 = staff1->getEmpID();
         s2 = staff2->getEmpID();

         s1.erase(0, 1);
         s2.erase(0, 1);

         try {
            s1Int = lexical_cast<int>(s1);
            s2Int = lexical_cast<int>(s2);
            if (s1Int < s2Int) {
               return true;
            }
         }
         catch (bad_lexical_cast &c) {
            cerr << endl
                 << "Error comparing employee ID's, employees not sorted!"
                 << endl;
            exit(EXIT_FAILURE);
         }

         return false;
      }
};


#endif
