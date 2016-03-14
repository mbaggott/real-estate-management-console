// header files and namespaces
#include "user_interface.h"
#include <cstdlib>

static const int ARGUMENTS = 4;

int main(int argc, char **argv)
{

   /* Check for 3 program arguments */
   if (argc != ARGUMENTS) {
      cout << "Error, please provide 3 input files! Exiting...";
      exit(EXIT_FAILURE);
   }

   /* Get argument filenames and store as strings */
   string arg1 = *++argv;
   string arg2 = *++argv;
   string arg3 = *++argv;

   /* Check the order and name of the arguemtns are correct */
   if (arg1 != "commercial.dat") {
      cout << "Error, first filename should be commercial.dat, exiting...";
      exit(EXIT_FAILURE);
   }
   if (arg2 != "residential.dat") {
      cout << "Error, second filename should be residential.dat, exiting...";
      exit(EXIT_FAILURE);
   }
   if (arg3 != "staff.dat") {
      cout << "Error, third filename should be staff.dat, exiting...";
      exit(EXIT_FAILURE);
   }

   UserInterface *theInterface = new UserInterface(arg1, arg2, arg3);
   theInterface->interact();

   delete theInterface;

   return EXIT_SUCCESS;
} // end of main
